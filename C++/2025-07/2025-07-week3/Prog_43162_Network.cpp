/*
Platform        : 프로그래머스
Title           : 네트워크
Question Index  : 43162
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/43162
*/

#include <string>
#include <vector>

using namespace std;
vector<bool> visited;

void DFS(vector<vector<int>> &computers,  int node, int n){
    visited[node] = 1;
    
    for(int i = 0; i < n; i++){
        
        if(computers[node][i] && !visited[i]){
            DFS(computers, i,  n);
        
        }
    }
    
} 

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n,0);
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(computers, i, n);
            
            answer++;
        }
        
    }

    
    return answer;
}