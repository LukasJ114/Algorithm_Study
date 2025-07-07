/*
Platform        : 백준
Title           : 바이러스
Question Index  : 2606
Link            : https://www.acmicpc.net/problem/2606
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M;
int cnt = 0;


void BFS(int Node, vector<vector<bool>> &Edge, vector<bool> &visited){
    visited[1] = 1;
    for(int i = 1; i <= N; i++){
        if(Edge[Node][i] && !visited[i]){        // 엣지가 있으면서 방문한 적 없을 때.
            visited[i] = 1;
            cnt++;
            BFS(i, Edge, visited);
        }
    }

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> M;
    
    vector<bool> visited(N,0);

    vector<vector<bool>> Edge(N+1, vector<bool>(N+1, 0));

    int tmpA, tmpB;
    for(int i = 0; i < M; ++i){
        cin >> tmpA >> tmpB;
        Edge[tmpA][tmpB] = 1;
        Edge[tmpB][tmpA] = 1;
    }
    BFS(1, Edge, visited);

    cout << cnt;
}