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


void Input(){
    cin >> N >> M;

    //* Map 선언
    Map = new int* [N+1];
    for(int i = 0; i < N+1; i++){
        Map[i] = new int [M+1];
        for(int j = 0; j < M+1; j++){
            Map[i][j] = 0;
        }
    }

    //* Map 입력
    for (int i = 1; i <= N; i++){
        string input;
        cin >> input;
        for (int j = 1; j <= M; j++){
            Map[i][j] = input[j-1];
        }
    }

}

void BFS(int startRow, int startCol, int wall){

    //* visited 동적할당 및 초기화
    int ***visited;
    visited = new int**[N+1];
    for(int i = 0; i < N+1; i++){
        visited[i] = new int*[M+1];
        for(int j = 0; j < M+1; j++){
            visited[i][j] = new int[2];
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
        }
    }
    //* visited row = 0, col = 0 접근하지 못하도록 visited = 1로 세팅
    for(int i = 0; i < N+1; i++){
        visited[i][0][0] = 1;
        visited[i][0][1] = 1;
    }
    for(int i = 0; i < M+1; i++){
        visited[0][i][0] = 1;
        visited[0][i][1] = 1;
    }
    //* 도착지 기본값 -1로 세팅
    visited[N][M][0] = -1;
    visited[N][M][1] = -1;




    //* 이동을 위한 배열 선언
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<tuple<int,int,int>> q;
    // q.push({1,2,3});
    // get<1>(q.front());
    
    //* 최초 시작 좌표 대입
    q.push({startRow, startCol, wall});






    //* visited 동적할당 해제
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < M+1; j++){
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





    //* Map 동적할당 해제
    for(int i = 0; i < N+1; i++){
        delete[] Map[i];
    }
    delete[] Map;
}