/*
Platform        : 백준
Title           : 상근이의 여행
Question Index  : 9372
Link            : https://www.acmicpc.net/problem/9372
*/

#include <iostream>

using namespace std;

int main(void){
    int t;
    int n, m;
    int tmpA, tmpB;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        
        for(int j = 0; j < m; j++){
            cin >> tmpA >> tmpB;
        }
        cout << n-1 << endl;
    }

}