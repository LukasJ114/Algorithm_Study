/*
Platform        : 백준
Title           : 알고리즘 수업 - 너비 우선 탐색 1
Question Index  : 24444
Link            : https://www.acmicpc.net/problem/24444
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

int N, M, R;

// V : 정점 집합, E : 간선 집합, R : 시작 정점
void BFS(vector<vector<int>> &E, int R, vector<int> &cnt){
    vector<bool> visited(N+1, 0);
    queue<int> Q;

    //! 1. 처음 방문한 노드 체크 및 큐에 추가
    visited[R] = true;
    Q.push(R);
    
    int visitCount = 1; // 방문 카운트 저장을 위한 카운터
    //! 2. 탐색 시작 (큐에 있는 순서대로 방문)
    while(!Q.empty()){
        int u = Q.front();
        //! 2-1. 각 노드에 몇번째 방문했는지 체크
        cnt[u] = visitCount++;
        Q.pop();

        //!  2-2. 방문한 노드와 연결된 노드를 큐에 추가
        for (auto v : E[u]){     // v : u 노드에 엣지로 연결된 노드.
            if(!visited[v]){
                visited[v] = true;
                Q.push(v);
            }
        }
    }

    //! 3. 출력
    for(int i = 1; i <= N; i++){
        cout << cnt[i] << "\n";
    }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;
    
    // //* Node 집합 선언
    // vector<int> V;
    // for(int i = 1; i <= N; i++){
    //     V.push_back(i);
    // }

    //* 각 노드에 몇번째로 방문했는지 카운트
    vector<int> cnt(N+1,0);

    //* Edge 집합 선언
    vector <vector<int>> E(N+1, vector<int>());
    int tmpA, tmpB;
    for (int i = 0; i < M; i++){
        cin >> tmpA >> tmpB;
        E[tmpA].push_back(tmpB);
        E[tmpB].push_back(tmpA);
    }

    //* 노드 별로 연결된 노드 오름차순 정렬
    for (int i = 1; i <= N; i++){
        sort(E[i].begin(), E[i].end());
    }

    
    BFS(E, R, cnt);

}