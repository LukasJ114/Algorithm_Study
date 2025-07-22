/*
Platform        : 백준
Title           : ATM
Question Index  : 11399
Link            : https://www.acmicpc.net/problem/11399
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> ATM_TIME;

void Input(){
    cin >> N;
    ATM_TIME.resize(N,0);
    for(int i = 0; i < N; i++){
        cin >> ATM_TIME[i];
    }
}

void printATM(){
    for(int i = 0; i < N; i++){
        cout << ATM_TIME[i] << " ";
    }
}

int main(void){
    Input();

    sort(ATM_TIME.begin(), ATM_TIME.end());

    int timeSum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            timeSum += ATM_TIME[j];
        }
    }
    cout << timeSum;

}