/*
Platform        : 백준
Title           : 단지번호붙이기
Question Index  : 2667
Link            : https://www.acmicpc.net/problem/2667
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




#if 1
// CNT = 몇번째 단지인지
int CNT, N;
// 각 단지별로 세대가 몇 개 있는지
vector<int> APT(25,0);

void Numbering(int row, int col, vector<vector<int>> &map, vector<vector<bool>> &visited);


int main(void){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin >> N;
    vector<vector<int>> map(N+2, vector<int>(N+2));
    for (int i = 1; i <= N; i++){
        string input;
        cin >> input;
        cout << input << " 입력 완료\n";
        for(int j = 0; j < N; i++){
            map[i][j+1] = input[j] - '0';
        }
    }
    
    
    APT.resize(N);
    vector<vector<bool>> visited(N+2, vector<bool>(N+2, 0));
    
    for (int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            // 1. 방문 체크
            if (visited[i][j]) continue;
            else visited[i][j] = 1;
            
            // 2. 방문한 곳이 1이라면 Numbering 시작
            if(map[i][j]) 
            Numbering(i, j, map, visited);
            CNT++;
        }
    }
    
    APT.resize(CNT);
    sort(APT.begin(), APT.end());
    
    
    cout << CNT << "\n";
    for(int i = 0; i < CNT; i++){
        cout << APT[i] << "\n";
    }
    
    
    
}


void Numbering(int row, int col, vector<vector<int>> &map, vector<vector<bool>> &visited){
    // 방문 체크. (최초 Numbering 함수 시작 시에는 중복이긴 함.)
    visited[row][col] = 1;

    // 단지에 세대가 몇 개 있는지 카운트
    APT[CNT]++;

    if(map[row+1][col] && !visited[row+1][col]){    // 위
        Numbering(row+1, col, map, visited);
    }
    if(map[row-1][col] && !visited[row-1][col]){    // 아래
        Numbering(row-1, col, map, visited);
    }
    if(map[row][col+1] && !visited[row][col+1]){    // 오른쪽
        Numbering(row, col+1, map, visited);
    }
    if(map[row][col-1] && !visited[row][col-1]){    // 왼쪽
        Numbering(row, col-1, map, visited);
    }

}
#endif