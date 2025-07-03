/*
Platform        : 백준
Title           : N과 M (2)
Question Index  : 15650
Link            : https://www.acmicpc.net/problem/15650
*/

#include <iostream>
#include <set>
#define Max 9

using namespace std;

int N, M;
int NumArr[Max];
bool visited[Max];


void DFS(int initiateNum, int depth){
   if (depth == M){
    for(int i = 0; i < M; i++){
        cout << NumArr[i] << " ";
    }
    cout << "\n";
    return;
   }

   for(int i = initiateNum; i <= N; i++){
    if (!visited[i]){
        visited[i] = true;
        NumArr[depth] = i;
        DFS(i, depth + 1);
        visited[i] = false;
    }
   }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    DFS(1, 0);
}