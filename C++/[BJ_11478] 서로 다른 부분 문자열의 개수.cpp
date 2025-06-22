/*
Platform        : 백준
Title           : 서로 다른 부분 문자열의 개수
Question Index  : 11478
Link            : https://www.acmicpc.net/problem/11478

Prosess         : 푸는 중
*/


#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    set<string> subStr;
    
    cin >> S;
    int len = S.length();

    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            subStr.insert(S.substr(i, j-i+1));
        }

    }
    cout << subStr.size();
}