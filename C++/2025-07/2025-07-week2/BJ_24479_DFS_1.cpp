/*
Platform        : 백준
Title           : 알고리즘 수업 - 깊이 우선 탐색 1
Question Index  : 24479
Link            : https://www.acmicpc.net/problem/24479
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M, R;

// V : 정점 집합, E : 간선 집합, R : 시작 노드
void DFS(){


}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    // V (Node 집합) 입력 및 선언
    vector<int> V(N+1);
    for(int i = 1; i <= N; i++){
        V[i] = i;
    }

    // E (Edge 집합) 입력 및 선언
    vector <vector<int>> E(N+1, vector<int>(N+1,0));
    int tmpA, tmpB;
    for (int i = 0; i < M; i++){
        cin >> tmpA >> tmpB;
        E[tmpA][tmpB] = 1;      // 엣지가 있는 곳은 1로 표현
        E[tmpB][tmpA] = 1;
    }



    
}