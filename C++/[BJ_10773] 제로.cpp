/*
Platform        : 백준
Title           : 제로
Question Index  : 10773
Link            : https://www.acmicpc.net/problem/10773
*/

#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> stack;

    int K;
    cin >> K;

    int tmp;
    for(int i = 0; i < K; i++){
        cin >> tmp;
        if(tmp == 0) stack.pop();
        else stack.push(tmp);
    }
    int sum = 0;
    while(!stack.empty()){
        sum += stack.top();
        stack.pop();
    }
    cout << sum;
}

