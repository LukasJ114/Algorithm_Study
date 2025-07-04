/*
Platform        : 백준
Title           : 연산자 끼워넣기
Question Index  : 14888
Link            : https://www.acmicpc.net/problem/14888
*/

#include <iostream>

using namespace std;


int N;
int cnt = 0;
int arr[100];
int operand[4];
int Max = -1000000000;
int Min = 1000000000;

void DFS(int Add, int Sub, int Mul, int Div, int X, int sum){
    if (X == N-1){
        if (sum < Min) Min = sum;
        if (sum > Max) Max = sum;   
    }
    if (Add > 0) DFS(Add-1, Sub, Mul, Div, X+1, sum + arr[X+1]);
    if (Sub > 0) DFS(Add, Sub-1, Mul, Div, X+1, sum - arr[X+1]);
    if (Mul > 0) DFS(Add, Sub, Mul-1, Div, X+1, sum * arr[X+1]);
    if (Div > 0) DFS(Add, Sub, Mul, Div-1, X+1, int(sum / arr[X+1]));


}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input : Number of Array
    cin >> N;
    // Input : Array
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    // Input : operand
    for (int i = 0; i < 4; i++){
        cin >> operand[i];
    }

    DFS(operand[0], operand[1], operand[2], operand[3], 0, arr[0]);
    cout << Max << "\n" << Min;

}