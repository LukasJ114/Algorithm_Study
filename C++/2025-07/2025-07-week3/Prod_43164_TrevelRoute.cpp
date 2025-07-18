/*
Platform        : 프로그래머스
Title           : 여행경로
Question Index  : 43164
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/43164
*/

#if 1
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 모든 가능한 유효 경로를 저장할 전역 벡터 (사전 순 정렬을 위해 필요)
vector<vector<string>> all_possible_paths;
// 각 항공권(ticket)의 사용 여부를 추적하는 배열
vector<bool> visited_ticket;
int total_tickets_count; // N 대신 tickets.size()를 명확히 표현

// DFS 함수 정의
// current_airport: 현재 위치한 공항 (문자열)
// current_path: 현재까지 탐색한 경로 (공항 이름들의 벡터)
// tickets: 전체 항공권 목록
void DFS(string current_airport, vector<string> current_path, const vector<vector<string>>& tickets) {
    // 1. 종료 조건: 모든 항공권을 다 사용했다면 하나의 유효한 경로를 찾은 것
    if (current_path.size() == total_tickets_count + 1) { // 경로 길이는 티켓 수 + 1 (시작 공항 포함)
        all_possible_paths.push_back(current_path);
        return; // 현재 경로 탐색 완료, 백트래킹 시작
    }

    // 2. 현재 공항에서 출발하는 다음 항공권 탐색
    for (int i = 0; i < total_tickets_count; ++i) {
        // 아직 사용하지 않은 항공권이고, 현재 공항에서 출발하는 항공권이라면
        if (!visited_ticket[i] && tickets[i][0] == current_airport) {
            // 해당 항공권 사용 표시 (전진)
            visited_ticket[i] = true;
            
            // 다음 공항을 현재 경로에 추가
            current_path.push_back(tickets[i][1]);
            
            // 다음 공항으로 DFS 재귀 호출
            DFS(tickets[i][1], current_path, tickets);
            
            // 백트래킹: 현재 항공권 사용 취소 (다른 경로를 위해)
            visited_ticket[i] = false;
            // 현재 경로에서 마지막에 추가했던 공항 제거
            current_path.pop_back(); 
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    total_tickets_count = tickets.size();
    
    // 항공권 사용 여부 초기화 (모두 false)
    visited_ticket.assign(total_tickets_count, false); 
    
    // 결과 경로들을 저장할 벡터 초기화 (이전 실행 결과가 남아있을 수 있으므로)
    all_possible_paths.clear(); 

    // 알파벳 순으로 가장 앞서는 경로를 쉽게 찾기 위해 tickets 배열을 미리 정렬
    // 경로가 여러 개면 알파벳 순서
    sort(tickets.begin(), tickets.end()); 

    // "ICN"에서 시작하는 항공권들을 찾아 DFS 시작
    // 모든 항공권을 한 번씩만 사용해야 하므로, "ICN"에서 시작하는 모든 항공권을 시도해봐야 합니다.
    for (int i = 0; i < total_tickets_count; ++i) {
        if (tickets[i][0] == "ICN") {
            // 이 항공권을 시작점으로 사용
            visited_ticket[i] = true;
            
            // 초기 경로 설정: 시작 공항 + 첫 항공권의 도착 공항
            vector<string> current_path;
            current_path.push_back("ICN");
            current_path.push_back(tickets[i][1]);
            
            // DFS 시작
            DFS(tickets[i][1], current_path, tickets); // 다음 공항부터 탐색 시작
            
            // 백트래킹: 이 시작 항공권의 사용 표시를 해제하여 다음 "ICN" 시작 항공권도 시도할 수 있도록 함
            visited_ticket[i] = false;
        }
    }

    // 모든 가능한 경로가 all_possible_paths에 저장되었으니, 그 중에서 가장 사전 순으로 앞서는 경로를 선택
    // all_possible_paths가 이미 정렬되어 있지 않다면 다시 정렬해야 하지만,
    // 위에서 tickets를 정렬했기 때문에, DFS 탐색 순서가 자연스럽게 사전 순에 가깝게 나옵니다.
    // 하지만 완전히 보장되지는 않으므로, 마지막에 한 번 더 정렬하는 것이 안전합니다.
    sort(all_possible_paths.begin(), all_possible_paths.end());

    // 가장 첫 번째 경로가 사전 순으로 가장 앞서는 경로
    return all_possible_paths[0];
}

#endif


#if 0
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
#endif