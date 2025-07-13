/*
Platform        : 프로그래머스
Title           : 게임 맵 최단거리
Question Index  : 1844
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/1844


아래와 같은 에러 발생. 근데 왜 발생하는지 모르겠음. 프로그래머스에서는 정답처리 되었다.
Prog_1844_GameMapMinDistance.cpp:39:24: error: a space is required between consecutive right angle brackets (use '> >')
   39 |     queue <pair<int,int>> q;
      |                        ^~
      |                        > >
/Users/lukas/VSC/Algorithm_Study/Algorithm_Study/C++/2025-07/2025-07-week3/Prog_1844_GameMapMinDistance.cpp:44:12: error: expected expression
   44 |     q.push({startRow,startCol});
      |            ^
/Users/lukas/VSC/Algorithm_Study/Algorithm_Study/C++/2025-07/2025-07-week3/Prog_1844_GameMapMinDistance.cpp:68:24: error: expected expression
   68 |                 q.push({nextRow, nextCol});
      |                        ^
3 errors generated.

*/


#include <iostream>
#include <queue>
#include <vector>



using namespace std;



// void Input(vector< vector<int> > maps){
//     for(int i = 0; i < MAPSIZE; i++){
//         for(int j = 0; j < MAPSIZE; j++){
//             cin >> maps[i][j];
//         }
//     }
// }

int solution(vector< vector<int> > &maps){
    int n = maps.size();
    int m = maps[0].size();

    //* visited 선언
    vector< vector<int> > visited(n, vector<int>(m, 0));

    int startRow = 0, startCol = 0;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    queue <pair<int,int>> q;
    if(maps[0][0] == 0){
        return -1;
    }
    //* start 추가
    q.push({startRow,startCol});
    //* start 방문 체크
    visited[0][0] = 1;

    while(!q.empty()){
        int nowRow = q.front().first;
        int nowCol = q.front().second;
        q.pop();
        
        

        if(nowRow == n-1 && nowCol == m-1){
            return visited[nowRow][nowCol];
        }


        for(int i = 0; i < 4; i++){
            int nextRow = nowRow + dr[i];
            int nextCol = nowCol + dc[i];

            //* 잘못된 인덱스 접근 차단
            if(nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m) continue;

            if(maps[nextRow][nextCol] && !visited[nextRow][nextCol]){
                q.push({nextRow, nextCol});
                visited[nextRow][nextCol] = visited[nowRow][nowCol] + 1;
            }
        }
        

    }
    return -1;

}

int main(void){
    vector< vector<int> > maps(5,vector<int>(5));   // 1 : 길, 0 : 벽

    // Input(maps);
    cout << solution(maps);

}