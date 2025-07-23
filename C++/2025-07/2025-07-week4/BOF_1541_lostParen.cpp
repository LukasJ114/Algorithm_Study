/*
Platform        : 백준
Title           : 잃어버린 괄호
Question Index  : 1541
Link            : https://www.acmicpc.net/problem/1541
*/


#include <iostream>
#include <vector>

using namespace std;
vector<string> inString(50);
void Input(){
    string input;
    cin >> input;

    int tmpSum = 0, cnt = 0;
    for(auto c : input){
        if(c == '+' || c == '-'){
            inString[cnt] = tmpSum + '0';
            cnt++;
            inString[cnt] = c;
            cnt++;
        }
        else{
            tmpSum += c - '0';
        }
    }

}


int main(void){

    Input();
    for(int i = 0; i <= 50; i++) cout << inString[i] << " ";

}