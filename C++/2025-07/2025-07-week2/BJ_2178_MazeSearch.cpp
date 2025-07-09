/*
Platform        : 백준
Title           : 미로탐색
Question Index  : 2178
Link            : https://www.acmicpc.net/problem/2178
4209 4210 4208 4205 4204 4195 4191 4185 4176 4175 4172 4170 

4165 4166 4169 

4222

고양이랑 4263 4247 4259 4327 4328 

뒷모습 4188 4347

고양이만 4266 4275 *4285 4305 4308 4310 4316(잴리) 
*/

/*
TODO - 1. 가지치기가 이루어지지 않음. 이유가 뭘까...
*/

#if 01

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int **Map;

void Input(){
    //* 1. N, M 입력 받기
    cin >> N >> M;

    //* 2. Map 배열 동적할당
    Map = new int*[N+2];
    for(int i = 0; i < N+2; i++) Map[i] = new int[M+2];

    //* 3. Map 전체를 0으로 초기화
    string input;
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            Map[i][j] = 0;
        }
    }

    //* 4. Map 입력 받기
    for(int i = 1; i <= N; i++){
        cin >> input;
        for(int j = 1; j <= M; j++){
            Map[i][j] = input[j-1] - '0';
        }
    }
}

int BFS(int StartRow, int StartCol){
    //* Visited Map 선언 및 초기화
    bool **visited;
    visited = new bool* [N+2];
    for(int i = 0; i < N+2; i++){
        visited[i] = new bool[M+2];
        for(int j = 0; j < M+2; j++){
            visited[i][j] = 0;
        }
    }
    //* disMap(해당 좌표까지의 거리) 선언 및 초기화
    int **disMap;
    disMap = new int* [N+2];
    for(int i = 0; i < N+2; i++){
        disMap[i] = new int[M+2];
        for(int j = 0; j < M+2; j++){
            disMap[i][j] = 1;
        }
    }

    //* Queue 선언
    queue <pair<int,int>> q; 

    //* Queue에 시작점 추가
    q.push({StartRow, StartCol});

    //* 시작점 방문 체크
    visited[StartRow][StartCol] = true;

    //* 상하좌우 탐색을 위한 준비물
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int nowRow, nowCol, nextRow, nextCol, res;
    while(!q.empty()){
        nowRow = q.front().first;
        nowCol = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            nextRow = nowRow + dr[i];
            nextCol = nowCol + dc[i];
            //* 다음 장소가 1이면서 방문한 적이 없는 경우
            if(Map[nextRow][nextCol] && !visited[nextRow][nextCol]){
                //* 방문 체크
                visited[nextRow][nextCol] = true;
                disMap[nextRow][nextCol] = disMap[nowRow][nowCol] + 1;
                q.push({nextRow, nextCol});
            }
        }


    }
    
    //* 도착점까지의 최단 거리 저장 
    res = disMap[N][M];


    //* visited, disMap 메모리 해제
    for(int i = 0; i < N+2; i++){
        delete[] visited[i];
        delete[] disMap[i];
    }
    delete[] visited;
    delete[] disMap;

    return res;
}


int main(void){
    ios::sync_with_stdio(false);
    // cin.tie(NULL);   

    //* 1. Input 받기
    Input();

    cout << BFS(1,1);




    //* 메모리 해제
    for(int i = 0; i < N+2; i++){
        delete[] Map[i];
    }
    delete[] Map;
}

#endif


// DFS & 백트래킹 => 시간초과
#if 0

#include <iostream>

using namespace std;

int N, M;
int **Map;
bool **visited;
int Distance = 100000;  // 최대값 10,000 인듯. >> 여유있게 0 하나 더 붙임.


void Input(){
    //* 0. N, M 입력 받기
    cin >> N >> M;

    //! Debugging Code
    // cout << N << " " << M << " :: N과 M 출력\n";

    //* 1. Map 배열 동적할당
    Map = new int*[N+2];
    for(int i = 0; i < N+2; i++) Map[i] = new int[M+2];
    
    //! Debugging Code
    // cout << "Map 동적할당 완료\n\n";

    //* 2. Map 전체를 0으로 초기화
    string input;
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            Map[i][j] = 0;
        }
    }

    //* 3. Map 입력 받기
    for(int i = 1; i <= N; i++){
        cin >> input;

        // //! Debugging Code
        // cout << "input : " << input << "\n";

        for(int j = 1; j <= M; j++){
            Map[i][j] = input[j-1] - '0';
            // //! Debugging Code
            // cout << Map[i][j] << " ";
        }

        // //! Debugging Code
        // cout << endl;
        // cout << i << "번째 줄 입력 완료\n\n";
    }
    // //! Debugging Code
    // cout << "Map 입력 완료\n";
}

// Now : 현재 위치, distance : Now까지 이동한 거리
void MazeSearch(int NowRow, int NowCol, int distance){
    //! 1. 방문 체크
    visited[NowRow][NowCol] = 1;
    // cout << NowRow << " " << NowCol << " 방문\n";
    
    //! 가지치기 :: 현재 재귀의 비용이 글로벌보다 낮으면 더 이상 탐색할 필요가 없다.
    if (distance > Distance) {
        // cout << "가지치기 발생\n";
        visited[NowRow][NowCol] = 0;
        return;
    }                                                                                  
    //* 도착지 도착 시 종료
    if(NowRow == N && NowCol == M) {
        if(distance < Distance) Distance = distance;
        visited[NowRow][NowCol] = 0;
        return;
    }


    //! 2. 상하좌우 탐색 (Map이 1이고 방문한 적 없는 곳으로 간다.)
    if (Map[NowRow+1][NowCol] && !visited[NowRow+1][NowCol]) MazeSearch(NowRow+1, NowCol, distance+1);
    if (Map[NowRow-1][NowCol] && !visited[NowRow-1][NowCol]) MazeSearch(NowRow-1, NowCol, distance+1);
    if (Map[NowRow][NowCol+1] && !visited[NowRow][NowCol+1]) MazeSearch(NowRow, NowCol+1, distance+1);
    if (Map[NowRow][NowCol-1] && !visited[NowRow][NowCol-1]) MazeSearch(NowRow, NowCol-1, distance+1);

    visited[NowRow][NowCol] = 0;
}


int main(void){
    ios::sync_with_stdio(false);
    // cin.tie(NULL);   

    // cout << "<<<프로그램 시작>>>\n";

    //! 1. Input 받기
    Input();
    
    // cout << "<<입력 완료>>\n";


    //! 2. visited 0으로 초기화
    visited = new bool* [N+2];
    for(int i = 0; i < N+2; i++){
        visited[i] = new bool[M+2];
        for(int j = 0; j < M+2; j++){
            visited[i][j] = 0;
        }
    }


    int distance = 1;
    
    MazeSearch(1,1,distance);

    cout << Distance;


    //! 메모리 해제
    for(int i = 0; i < N+2; i++){
        delete[] visited[i];
        delete[] Map[i];
    }
    delete[] visited;
    delete[] Map;
}

#endif