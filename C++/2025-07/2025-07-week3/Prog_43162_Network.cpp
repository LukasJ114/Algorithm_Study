/*
Platform        : 프로그래머스
Title           : 네트워크
Question Index  : 43162
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/43162
*/

#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &computers, vector<bool> &visited, int node, int &answer, int n){
    answer++;
    visited[node] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            if(computers[i][j] && !visited[j]){
                DFS(computers, visited, i, answer, n);
            }
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(3,0);
    
    // 0번째 인덱스 부터 시작
    DFS(computers, visited, 0, answer, n);
    
    return answer;
}