/*
Platform        : 백준
Title           : 괄호
Question Index  : 9012
Link            : https://www.acmicpc.net/problem/9012
*/

#include <iostream>
#include <vector>


using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int len = 0;
    int cnt = 0;
    vector<char> arr;
    vector<char> :: iterator it;
    string s;
    while(T){
        cin >> s;
        len = s.length();
        // 길이가 홀수인 경우 조기종료
        if ((len%2 != 0) || (s[0] == ')') || (s[len-1] == '(')){
            cout << "No\n";
            continue;
        }
        
        // vector에 대입
        for(int i = 0; i < len; i++){
            arr.push_back(s[i]);
        }
        it = arr.begin();
        for(int i = 1; i < len; i++){
            if ((arr[i-1] == '(') && (arr[i] == ')')){

            }
        }
        for (;it!=arr.end(); it++){
            
        }







        T--;
    }

}