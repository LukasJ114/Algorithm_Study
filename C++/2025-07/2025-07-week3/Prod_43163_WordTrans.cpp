/*
Platform        : 프로그래머스
Title           : 단어변환
Question Index  : 43163
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/43163
*/



// 메모리 초과 or 시간 초과
#if 0
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int NumOfWord;

bool compWord(string A, string B){
    int cnt = 0;
    for(int i = 0; i < NumOfWord; i++){
        if(A[i] != B[i]) cnt++;
    }
    if(cnt == 1) return 1;
    else return 0;
}

int BFS(string begin, string target, vector<string> words){
    map<string,int> visited;
    visited[begin] = 0;
    
    queue<string> q;
    q.push(begin);
    
    while(!q.empty()){
        string nowWord = q.front();
        q.pop();
        if(nowWord == target) return visited[nowWord];
        
        for(int i = 0; i < NumOfWord; i++){
            // 이미 방문한 단어 continue 처리
            if(visited.find(words[i]) != visited.end()) continue;
            
            // 현재 검사하는 단어가 1개만 다르면 큐에 추가
            if(compWord(nowWord, words[i])) q.push(words[i]);
            // 방문 체크
            visited[words[i]] = visited[nowWord]++;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    NumOfWord = words[0].size();
    int answer = BFS(begin, target, words);
    return answer;
}

#endif