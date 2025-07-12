/*
Platform        : 백준
Title           : 벽 부수고 이동하기
Question Index  : 2206
Link            : https://www.acmicpc.net/problem/2206
*/

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int **Map;

struct Wall{
    int row;
    int col;
    int bomb;
    Wall(int r, int c, int b){
        row = r;
        col = c;
        bomb = b;
    }
};


void Input(){
    cin >> N >> M;

    //* Map 선언
    Map = new int* [N+2];
    for(int i = 0; i < N+2; i++){
        Map[i] = new int [M+2];
        for(int j = 0; j < M+2; j++){
            Map[i][j] = 0;
        }
    }

    //* Map 입력
    for (int i = 1; i <= N; i++){
        string input;
        cin >> input;
        for (int j = 1; j <= M; j++){
            Map[i][j] = input[j-1] - '0';
        }
    }

}
// wall : 벽을 부쉈는지 여부
void BFS(int startRow, int startCol, int brokeWall){
    // //! Debugging Code
    // cout << "BFS 시작\n";

    //* visited 동적할당 및 초기화
    int ***visited;
    visited = new int**[N+2];
    for(int i = 0; i < N+2; i++){
        visited[i] = new int*[M+2];
        for(int j = 0; j < M+2; j++){
            visited[i][j] = new int[2];
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
        }
    }
    //* visited row = 0, col = 0 접근하지 못하도록 visited = 1로 세팅
    for(int i = 0; i < N+2; i++){   // 0번쨰, M+1 번째 열을 1로 세팅
        visited[i][0][0] = 1;
        visited[i][0][1] = 1;
        
        visited[i][M+1][0] = 1;
        visited[i][M+1][1] = 1;
    }
    for(int i = 0; i < M+2; i++){   // 0번째, N+1 번째 행을 1로 세팅
        visited[0][i][0] = 1;
        visited[0][i][1] = 1;

        visited[N+1][i][0] = 1;
        visited[N+1][i][1] = 1;
    }
    //* 도착지 기본값 -1로 세팅
    // visited[N][M][0] = -1;
    // visited[N][M][1] = -1;

    // //! Debugging Code
    // cout << "visited 할당 및 선언 완료\n";



    //* 이동을 위한 배열 선언
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<Wall> q;
    
    //* 최초 시작 좌표 대입
    // q.push({startRow, startCol, wall});     //? Struct인데 이렇게 삽입 가능한가? 
    q.push(Wall(startRow, startCol, brokeWall));    //! 역시 안된다.
    
    //* 최초 시작 좌표 방문 체크
    visited[startRow][startCol][0] = 1;
    
    int res = 0;
    //* 탐색 시작. 
    while(!q.empty()){
        int nowRow = q.front().row;
        int nowCol = q.front().col;
        int nowBomb = q.front().bomb;
        q.pop();

        
        if (nowRow == N && nowCol == M){
            res = visited[nowRow][nowCol][nowBomb];
            // if (res == 0) cout << "-1";
            // else cout << res;
            // return;
            break;
        }


        for(int i = 0; i < 4; i++){
            int nextRow = nowRow + dr[i];
            int nextCol = nowCol + dc[i];
            // 내가 방문한 곳이 벽인가 아닌가. (1이면 벽. 0이면 벽 없음)
            int isWall = Map[nextRow][nextCol];

            
            //* 잘못된 인덱스 접근 차단
            if(nextRow < 1 || nextCol < 1 || nextRow > N || nextCol > M) continue;

            /*
            * 고려해야 할 경우의 수 *
            TODO 1. 탐색한 곳이 벽 && 폭탄을 가지고 있다 ==> 폭탄을 터트리고 진입
            TODO 2. 탐색한 곳이 벽 && 폭탄이 없음 ==>  진입불가
            TODO 3. 탐색한 곳이 벽이 아님. ==> 아무 문제 없음. 진입
            */

            /*
            //* TODO 1 => 탐색하는 곳이 벽이면서 내가 폭탄을 가지고 있다.
            if(visited[nextRow][nextCol][nowBomb] == 0 && isWall && nowBomb == 0){
                visited[nextRow][nextCol][1] = visited[nowRow][nowCol][nowBomb]+ 1;
                visited[nextRow][nextCol][0] = 1;   //예외처리
                q.push(Wall(nextRow, nextCol, 1));
                continue;
            }
            //* TODO 2 => 진입못함. 
            else if(isWall && nowBomb == 1) continue;
            
            //* TODO 3 => 방문한적 없고, 벽 없음. =>> 그냥 집입하면 된다.
            else if(visited[nextRow][nextCol][nowBomb] == 0 && !isWall){
                visited[nextRow][nextCol][nowBomb] = visited[nowRow][nowCol][nowBomb]+ 1;
                q.push(Wall(nextRow, nextCol, nowBomb));
                
            }
            */

            if(!isWall){    // wall이 없을 때
                // 다음 이동하는 곳이 0일때
                if(visited[nextRow][nextCol][nowBomb] == 0){
                    visited[nextRow][nextCol][nowBomb] = visited[nowRow][nowCol][nowBomb]+ 1;
                    q.push(Wall(nextRow, nextCol, nowBomb));
                }
            }
            else{   // wall이 있을때
                if(visited[nextRow][nextCol][1] == 0 && nowBomb == 0){
                    visited[nextRow][nextCol][1] = visited[nowRow][nowCol][nowBomb] + 1;
                    // visited[nextRow][nextCol][0] = 1;   //예외처리
                    q.push(Wall(nextRow, nextCol, 1));
                }
            }
        }
    }



    if (res == 0) cout << "-1";
    else cout << res;


    //* visited 동적할당 해제
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            delete[] visited[i][j];
        }
        delete[] visited[i];
    }
    delete[] visited;

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();

    // //! Debugging Code
    // cout << "input 완료" << endl;
    
    BFS(1,1,0);


    //* Map 동적할당 해제
    for(int i = 0; i < N+2; i++){
        delete[] Map[i];
    }
    delete[] Map;
}


