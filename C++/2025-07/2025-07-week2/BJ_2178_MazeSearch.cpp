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


#include <iostream>

using namespace std;

int N, M;
int **Map;
bool **visited;
int Distance = 100000;  // 최대값 10,000 인듯. >> 여유있게 0 하나 더 붙임.


void Input(){
    cin >> N >> M;

    //! Debugging Code
    cout << N << " " << M << " :: N과 M 출력\n";

    Map = new int*[N+2];
    for(int i = 0; i < N+2; i++) Map[i] = new int[M+2];
    
    //! Debugging Code
    cout << "Map 동적할당 완료\n\n";

    string input;

    //! Map 입력 받기
    for(int i = 1; i <= N; i++){
        cin >> input;

        //! Debugging Code
        cout << "input : " << input << "\n";

        for(int j = 1; j <= M; j++){
            Map[i][j] = input[j-1] - '0';
            //! Debugging Code
            cout << Map[i][j] << " ";
        }

        //! Debugging Code
        cout << endl;
        cout << i << "번째 줄 입력 완료\n\n";
    }
    //! Debugging Code
    cout << "Map 입력 완료\n";
}

// Now : 현재 위치, distance : Now까지 이동한 거리
void MazeSearch(int NowRow, int NowCol, int distance){
    //! 1. 방문 체크
    visited[NowRow][NowCol] = 1;
    
    //* 도착지 도착 시 종료
    if(NowRow == N && NowCol == M) {
        if(distance < Distance) Distance = distance;
        return;
    }

    //! 가지치기 :: 현재 재귀의 비용이 글로벌보다 낮으면 더 이상 탐색할 필요가 없다.
    if(distance > Distance) return;

    //! 2. 상하좌우 탐색
    if (Map[NowRow+1][NowCol] && !visited[NowRow+1][NowCol]) MazeSearch(NowRow+1, NowCol, distance+1);
    if (Map[NowRow-1][NowCol] && !visited[NowRow-1][NowCol]) MazeSearch(NowRow-1, NowCol, distance+1);
    if (Map[NowRow][NowCol+1] && !visited[NowRow][NowCol+1]) MazeSearch(NowRow, NowCol+1, distance+1);
    if (Map[NowRow][NowCol-1] && !visited[NowRow][NowCol-1]) MazeSearch(NowRow, NowCol-1, distance+1);




}


int main(void){
    ios::sync_with_stdio(false);
    // cin.tie(NULL);   

    cout << "<<<프로그램 시작>>>\n";

    //! 1. Input 받기
    Input();
    
    cout << "<<입력 완료>>\n";


    //! 2. visited 0으로 초기화
    visited = new bool* [N+2];
    for(int i = 0; i < N+2; i++){
        visited[i] = new bool[M+2];
        for(int j = 0; j < M+2; j++){
            visited[i][j] = 0;
        }
    }


    int distance = 0;
    
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