/*
Platform        : 백준
Title           : 하노이 탑 이동 순서
Question Index  : 11729
Link            : https://www.acmicpc.net/problem/11729
*/

#include <iostream>
#include <cmath>

using namespace std;

void Hanoi(int n, int start, int goal){
    if(n == 1){
        cout << start << " " << goal << "\n";
    }
    else{
        Hanoi(n-1, start, (6-start-goal));
        cout << start << " " << goal << "\n";
        Hanoi(n-1, (6-start-goal), goal);
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    int moveSum = pow(2,K) - 1;
    cout << moveSum << "\n";

    Hanoi(K, 1, 3);
}

