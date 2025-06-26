/*
Platform        : 백준
Title           : 문자열 집합
Question Index  : 1425
Link            : https://www.acmicpc.net/problem/14425

Prosess         : Complete
*/
/*
#Include
5 11
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
codeplus
codeminus
startlink
starlink
sundaycoding
codingsh
codinghs
sondaycoding
startrink
icerink

#Output
4
*/


#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string,int> S;
    string tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        S[tmp] += 1;
    }

    int cnt = 0;
    for(int i = 0; i < M; i++){
        cin >> tmp;
        if (S.count(tmp)==1) cnt++;
    }
    cout << cnt;
}