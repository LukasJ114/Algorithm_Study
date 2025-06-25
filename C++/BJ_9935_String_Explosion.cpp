/*
Platform        : 백준
Title           : 문자열 폭발
Question Index  : 9935
Link            : https://www.acmicpc.net/problem/9935
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int>::iterator it;

    string s = "apple";
    cout << s.length();

    // vector<char> str;
    // string tmp;
    // cin >> tmp;
    // for(int i = 0; i < tmp.length(); i++){
    //     str[i] = tmp[i];
    // }
    string::reverse_iterator rit = s.rbegin();
    for(;rit != s.rend(); rit++){
        cout << *rit;

    }



}