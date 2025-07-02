/*
Platform        : 백준
Title           : N과 M (1)
Question Index  : 15649
Link            : https://www.acmicpc.net/problem/15649
*/

#include <iostream>
#define Max 9

using namespace std;

int N, M;
int NumArr[Max];
bool visited[Max];


void DFS(int depth){
   if (depth == M){
    for(int i = 0; i < M; i++){
        cout << NumArr[i] << " ";
    }
    cout << "\n";
    return;
   }

   for(int i = 1; i <= N; i++){
    if (!visited[i]){
        visited[i] = true;
        NumArr[depth] = i;
        DFS(depth + 1);
        visited[i] = false;
    }
   }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    DFS(0);
}