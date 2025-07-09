/*
Platform        : 백준
Title           : 토마토
Question Index  : 7576
Link            : https://www.acmicpc.net/problem/7576
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int **Map;
vector<pair<int, int>> goodTomato;

void Input(){
    cin >> M >> N;

    //* Map 선언 및 -1로 초기화
    Map = new int*[N+2];
    for(int i = 0 ; i < N+2; i++) {
        Map[i] = new int[M+2];
        for(int j = 0; j < M+2; j++){
            Map[i][j] = -1;
        }
    }

    //* Map 입력
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> Map[i][j];
            if (Map[i][j]==1){
                goodTomato.push_back({i,j});
            }

        }
    }
}

void BFS(){
    //* Day 배열 선언. (Visited 역할과 출력의 역할도 함께 한다. 해당 배열에서 가장 큰 수를 출력)
    int **Day;
    Day = new int* [N+2];
    for(int i = 0; i < N+2; i++) {
        Day[i] = new int[M+2];
        for(int j = 0; j < M+2; j++){
            Day[i][j] = 0;
        }
    }
    
    //* 잘익은 토마토 전부 큐에 넣는다.
    queue<pair<int,int>> q;
    for(auto p : goodTomato){
        q.push(p);
    }
    //* 상하좌우
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};


    int nowRow, nowCol, nextRow, nextCol;
    //* 탐색 시작
    while(!q.empty()){
        nowRow = q.front().first;
        nowCol = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            nextRow = nowRow + dr[i];
            nextCol = nowCol + dc[i];
            //* 안익은 토마토이면서 방문하지 않은 토마토
            if(Map[nextRow][nextCol]==0 && Day[nextRow][nextCol] == 0) {
                Day[nextRow][nextCol] = Day[nowRow][nowCol] + 1;
                Map[nextRow][nextCol] = 1;
                q.push({nextRow, nextCol});
            }
        }
    }


    int res = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            //* Day배열에서 가장 높은 숫자 찾기
            if (Day[i][j] > res) res = Day[i][j];

            //* 안익은게 남아있으면 `-1` 출력
            if(Map[i][j] == 0){
                cout << -1;
                return;
            }
        }
    }

    //* Day 메모리 해제
    for(int i = 0; i < N+2; i++){
        delete[] Day[i];
    }
    delete[] Day;

    //* 출력
    cout << res;

}



int main(void){

    Input();

    BFS();


    for(int i = 0; i < N+2; i++){
        delete[] Map[i];
    }
    delete[] Map;
}