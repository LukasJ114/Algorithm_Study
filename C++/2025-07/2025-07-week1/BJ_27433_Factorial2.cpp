/*
Platform        : 백준
Title           : 팩토리얼2
Question Index  : 27433
Link            : https://www.acmicpc.net/problem/27433
*/

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    long long res = 1;

    while (N > 0){
        res *= N;
        N--;
    }
    cout << res;

}