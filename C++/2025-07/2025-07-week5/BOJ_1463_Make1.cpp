/*
Platform        : 백준
Title           : 퇴사2
Question Index  : 15486
Link            : https://www.acmicpc.net/problem/15486
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
        int tmp = N;
        if((i % 3 == 0) || (i % 2 == 0)){
            if(i % 3 == 0){
                table[i] = (table[i/3] + 1) < tmp ? (table[i/3] + 1) : tmp;
            }
            if(i % 2 == 0){
                table[i] = (table[i/2] + 1) < tmp ? (table[i/2] + 1) : tmp;
            }
        }
        
        if(table[i] > (table[i-1] + 1)) table[i] = table[i-1] + 1;
        // table[i] = (table[i-1] + 1) < tmp ? (table[i-1] + 1) : tmp;
    
    }
    cout << table[N];


}