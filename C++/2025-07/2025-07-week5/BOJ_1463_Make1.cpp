/*
Platform        : 백준
Title           : 1로 만들기
Question Index  : 1463
Link            : https://www.acmicpc.net/problem/1463
*/

#include <iostream>
#include <vector>

using namespace std;

int N;

int main(void){
    cin >> N;

    vector<int> table(N+1, N);
    table[1] = 0;
    table[2] = 1;
    table[3] = 1;

    for(int i = 4; i <= N; i++){
        
        table[i] = table[i-1] + 1;
        
        if(i % 2 == 0){
            table[i] = (table[i/2] + 1) < table[i] ? (table[i/2] + 1) : table[i];
        }
        if(i % 3 == 0){
            table[i] = (table[i/3] + 1) < table[i] ? (table[i/3] + 1) : table[i];
        }
    
    }
    cout << table[N];


}