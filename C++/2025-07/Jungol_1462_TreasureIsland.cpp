

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>


using namespace std;


int N, M;
// True : 땅, False : 바다
vector<vector<bool>> Map;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };

int lastRow, lastCol;
int MAX = 0;


void TresureHunt();
void BFS(vector<vector<int>>& visited, int row, int col);
void BFS_1(vector<vector<int>>& visited, int row, int col);

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
            // Map[i][j] = (Input[j] == 'L') ? 1 : 0;
        }
    }

    // // ! Debugging Code
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << Map[i][j];
    //     }
    //     cout << endl;
    //     cout << "WTFWTFWTFWTF\n";
    // }

    // cout << "WTF\n";

}


int main(void) {
    Input();
    // cout << "입력 완료\n";
    TresureHunt2();

}


void BFS2(int row, int col) {
    vector<vector<int>> visited(N, vector<int>(M,0));
    queue<pair<int, int>> q;
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
            
            
            if (Map[nextRow][nextCol] && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = visited[nowRow][nowCol] + 1;
                q.push({ nextRow, nextCol });
            }
            
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << visited[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    int tmp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] > tmp) tmp = visited[i][j];
        }
    }
    if(MAX < tmp) MAX = tmp;

    // for (int i = 0; i < N; i++) {
    //     int tmp = *max_element(visited[i].begin(), visited[i].end());
    //     if (MAX < tmp) MAX = tmp;
    // }



}
void TresureHunt2() {
    vector<vector<bool>> visited(N, vector<bool>(M,0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 육지이면서 방문하지 않은 곳
            if (Map[i][j] && !visited[i][j]) {
                visited[i][j] = true;
                BFS2(i,j);
            }
        }
    }
    cout << MAX-1;
}

/*
전체 이중 반복문으로 1(땅)을 탐색.
발견 시 1차 BFS 실행.
한쪽 제일 끝에서 다시 BFS 실행. => 거리를 visited에 저장.

혹시 다른  섬이 있나 남은 반복문으로 탐색.
*/

void BFS(vector<vector<int>>& visited, int row, int col) {

    queue<pair<int, int>> q;
    q.push({ row,col });

    while (!q.empty()) {
        int nowRow = q.front().first;
        int nowCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            // 범위 넘어가는 경우 차단.
            if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= M) continue;


            if (Map[nextRow][nextCol] && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = visited[nowRow][nowCol] + 1;
                q.push({ nextRow, nextCol });
            }


        }
        // 탐색의 한쪽 끝 부분 저장
        lastRow = nowRow;
        lastCol = nowCol;
    }

}
void BFS_1(vector<vector<int>>& visited, int row, int col) {

    queue<pair<int, int>> q;
    queue<pair<int,int>> qqq;
    q.push({ row,col });

    while (!q.empty()) {
        int nowRow = q.front().first;
        int nowCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            // 범위 넘어가는 경우 차단.
            if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= M) continue;


            if (Map[nextRow][nextCol] && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = visited[nowRow][nowCol] + 1;
                q.push({ nextRow, nextCol });
                qqq.push({ nextRow, nextCol });
            }


        }
        // 탐색의 한쪽 끝 부분 저장
        lastRow = nowRow;
        lastCol = nowCol;
    }

    while(!qqq.empty()){
        visited[qqq.front().first][qqq.front().second] = 0;
        qqq.pop();
    }


}

void TresureHunt() {
    vector<vector<int>> visited(N, vector<int>(M,0));
    // cout << "보물찾기 시작!!!!!\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 육지이면서 방문하지 않은 곳
            if (Map[i][j] && !visited[i][j]) {
                // cout << "육지 발견. 탐색 시작\n";
                BFS_1(visited, i, j);
                
                BFS(visited, lastRow, lastCol);
            }
        }
    }
    int res = N * M;

    for (int i = 0; i < N; i++) {
        int tmp = *max_element(visited[i].begin(), visited[i].end());
        if (res > tmp) res = tmp;
    }
    cout << res;
}