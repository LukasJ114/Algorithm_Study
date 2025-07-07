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

#if 01
// CNT = 몇번째 단지인지
int CNT, N;
// 각 단지별로 세대가 몇 개 있는지
vector<int> APT;

void Numbering(int row, int col, int** map, vector<vector<bool>> &visited);


int main(void){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    
    // # INPUT
    cin >> N;
    // cout << "N 입력완료" << endl;
    // vector<vector<int>> map(N+2, vector<int>(N+2));
    
    
    // 2차원 MAP 생성 및 할당
    int **map = new int* [N+2];
    for(int i = 0; i < N+2; i++){
        map[i] = new int[N+2];
        
    }
    for (int i = 1; i <= N; i++){
        string input;
        cin >> input;
        // cout << input << " 입력 완료\n";
        for(int j = 0; j < N; j++){
            map[i][j+1] = input[j] - '0';
        }
    }
    // cout << "테두리 제외 입력 완료" << endl;
    // 테두리 초기화
    for(int i = 0; i < N+2; i++){
        map[0][i] = 0;
        map[N+1][i] = 0;
        map[i][0] = 0;
        map[i][N+1] = 0;
    }
    // cout << "모든 입력 완료" << endl;
    
    
    // # SEARCHING
    // APT.resize(N);
    
    vector<vector<bool>> visited(N+2, vector<bool>(N+2, 0));
    for (int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            // 1. 방문 체크
            if (visited[i][j]) continue;    // 만약 방문한 곳이면 continue
            else visited[i][j] = 1;         // 방문한 곳이 아니면 체크
            
            // 2. 방문한 곳이 1이라면 Numbering 시작
            if(map[i][j]) {
                APT.push_back(0);   // 아파트 단지 추가
                Numbering(i, j, map, visited);
                CNT++;
            }
        }
    }
    
    // 출력을 위한 순서 정렬
    sort(APT.begin(), APT.end());

    // # OUTPUT
    cout << CNT << "\n";
    for(int i = 0; i < CNT; i++){
        cout << APT[i] << "\n";
    }   
    
}


void Numbering(int row, int col, int **map, vector<vector<bool>> &visited){
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

#if 0   // 메모리 초과
// CNT = 몇번째 단지인지
int CNT, N;
// 각 단지별로 세대가 몇 개 있는지
vector<int> APT(25,0);

void Numbering(int row, int col, vector<vector<int>> &map, vector<vector<bool>> &visited);


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // # INPUT
    cin >> N;
    // cout << "N 입력완료" << endl;
    vector<vector<int>> map(N+2, vector<int>(N+2));
    for (int i = 1; i <= N; i++){
        string input;
        cin >> input;
        // cout << input << " 입력 완료\n";
        for(int j = 0; j < N; j++){
            map[i][j+1] = input[j] - '0';
        }
    }
    
    // # SEARCHING
    APT.resize(N);
    vector<vector<bool>> visited(N+2, vector<bool>(N+2, 0));
    
    for (int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            // 1. 방문 체크
            if (visited[i][j]) continue;    // 만약 방문한 곳이면 continue
            else visited[i][j] = 1;         // 방문한 곳이 아니면 체크
            
            // 2. 방문한 곳이 1이라면 Numbering 시작
            if(map[i][j]) {
                Numbering(i, j, map, visited);
                CNT++;
            }
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