/*
Platform        : 정올
Title           : 보물섬
Question Index  : 1462
Link            : https://jungol.co.kr/problem/1462?cursor=OCw1LDM%3D
*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
// True : 땅, False : 바다
vector<vector<bool>> Map;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };

int MAX = 0;

void BFS2(int row, int col);
void TresureHunt2();


void Input() {
    cin >> N >> M;
    Map.resize(N, vector<bool>(M));
    string Input;

    for (int i = 0; i < N; i++) {
        cin >> Input;
        for (int j = 0; j < M; j++) {
            if (Input[j] == 'L') Map[i][j] = 1;
            else Map[i][j] = 0;
        }
    }
}


int main(void) {
    Input();

    TresureHunt2();

}


void BFS2(int row, int col) {
    vector<vector<int>> visited(N, vector<int>(M,0));
    queue<pair<int, int>> q;
    // 시작점 PUSH
    q.push({ row,col });
    visited[row][col] = 1;
    
    while (!q.empty()) {
        int nowRow = q.front().first;
        int nowCol = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextRow = nowRow + dr[i];
            int nextCol = nowCol + dc[i];
            
            // 범위 넘어가는 경우 차단.
            if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= M) continue;
            
            // 1(육지)이면서 방문하지 않은 곳
            if (Map[nextRow][nextCol] && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = visited[nowRow][nowCol] + 1;
                q.push({ nextRow, nextCol });
            }
            
        }
    }

    int tmp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] > tmp) tmp = visited[i][j];
        }
    }
    if(MAX < tmp) MAX = tmp;
}


void TresureHunt2() {
    // 모든 지점에서 BFS 수행. 최대값을 전역으로 저장 및 갱신.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 육지이면서 방문하지 않은 곳
            if (Map[i][j]) {
                BFS2(i,j);
            }
        }
    }

    // 문제에서 한쪽 지점은 포함하지 않음.
    cout << MAX-1;
}
