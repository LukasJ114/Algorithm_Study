/*
Platform        : 백준
Title           : 알고리즘 수업 - 깊이 우선 탐색 1
Question Index  : 24479
Link            : https://www.acmicpc.net/problem/24479
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
int visitCNT = 0;

//? V가 필요한가?
// V : 정점 집합, E : 간선 집합, R : 시작 노드
void DFS(vector<vector<int>> &E, int R, vector<bool> &visited, vector<int> &cnt){
    //! 1. 방문한 노드 체크
    visited[R] = true;
    ++visitCNT;
    cnt[R] = visitCNT;
    //! 2. 방문한 노드에 연결된 노드들을 확인
    for(auto v : E[R]){
        //! 3. 연결된 노드들 중 방문하지 않은 노드 방문 (오름차순으로 정렬되어 있으므로 순서대로 방문)
        if(!visited[v]){
            DFS(E, v, visited, cnt);
        }
    }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    // //* V (Node 집합) 입력 및 선언
    // vector<int> V(N+1);
    // for(int i = 1; i <= N; i++){
    //     V[i] = i;
    // }

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

    vector<bool> visited(N+1, false);
    vector<int> cnt(N+1,0);

    DFS(E, R, visited, cnt);

    
    //* 출력
    for(int i = 1; i <= N; i++){
        cout << cnt[i] << "\n";
    }

}