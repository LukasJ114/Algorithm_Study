/*
Platform        : 프로그래머스
Title           : 여행경로
Question Index  : 43164
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/43164
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> visited;
vector<vector<string>> travel(0, vector<string>(0));
int N;

void DFS(int current, vector<string> &plan, vector<vector<string>> &tickets){
    visited[current] = 1;
    plan.push_back(tickets[current][0]);
    
    if(plan.size() == N){
        plan.push_back(tickets[current][1]);
        travel.push_back(plan);
    }
    
    
    for(int i = 0; i < N; i++){
        if(tickets[i][0] != tickets[current][1]) continue;
        
        if(visited[i]) continue;
        
        DFS(i, plan, tickets);
    }
    
    visited[current] = 0;

    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    N = tickets.size();
    visited.resize(N,0);
    
    vector<vector<string>> travel;
    
    for(int i = 0; i < N; i++){
        vector<string> plan(N+1);
        if(tickets[i][0] == "ICN"){
            DFS(i, plan, tickets);
        }
        
        // Debugging Code
        for(int i = 0; i <= N; i++){
            cout << plan[i];
        }
    }
    
    
    // for(int i = 0; i < N; i++){
    //     for(int j  = 0; j < N; j++){
    //         cout << travel[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    
    
    return answer;
}