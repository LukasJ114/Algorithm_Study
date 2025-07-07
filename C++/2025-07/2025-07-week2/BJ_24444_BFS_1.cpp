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
void BFS(vector<int> V, vector<vector<int>> E, int R, vector<int> cnt){
    // map<int, bool> visited;
    vector<bool> visited(N+1, 0);
    // for(auto v : V){
    //     visited[v] = false;
    // }
    visited[R] = true;
    queue<int> Q;
    Q.push(R);
    
    int visitCount = 1; // 방문 카운트 저장을 위한 카운터
    while(!Q.empty()){
        int u = Q.front();
        cnt[u] = visitCount++;
        Q.pop();

        // for (auto v : E[u]){     // v : u 노드에 엣지로 연결된 노드.
        //     if(!visited[v]){
        //         visited[v] = true;
        //         Q.push(v);
        //     }
        // }
        for (int i = 1; i <= N; i++){
            bool edgeCheck = E[u][i];      // tmp = 1 or 0 // u와 i의 엣지 유무
            if(edgeCheck && !visited[i]){       // 엣지가 있고, 방문한 적이 없어야 한다.
                visited[i] = true;
                Q.push(i);
            }
        }

    }

    for(int i = 1; i <= N; i++){
        cout << cnt[i] << endl;
    }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;
    
    // Node 집합 선언
    vector<int> V;
    for(int i = 1; i <= N; i++){
        V.push_back(i);
    }

    // 각 노드에 몇번째로 방문했는지 카운트
    vector<int> cnt(N+1,0);

    // Edge 집합 선언
    vector <vector<int>> E(N+1, vector<int>(N+1,0));
    int tmpA, tmpB;
    for (int i = 0; i < M; i++){
        cin >> tmpA >> tmpB;
        E[tmpA][tmpB] = 1;      // 엣지가 있는 곳은 1로 표현
        E[tmpB][tmpA] = 1;
    }

    
    BFS(V, E, R, cnt);

}