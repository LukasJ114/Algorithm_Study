/*
Platform        : 백준
Title           : 괄호
Question Index  : 9012
Link            : https://www.acmicpc.net/problem/9012
*/

#include <iostream>
#include <vector>
#include <stack>

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

    for(int i = 0; i < T; i++){
        cin >> s;
        stack<char> stack;
        bool isVPS = true;
        for(char c : s){
            if(c=='(') stack.push(c);
            else{
                if(stack.empty()){
                    isVPS = false;
                    break;
                }
                stack.pop();
            }
        }
        if(!stack.empty()) isVPS = false;
        cout << (isVPS ? "YES\n" : "NO\n");
    }

    // for(int kk = 0; kk < T; kk++){
    //     cout << "반복문 진행 : " << kk+1 << endl;
    //     arr.clear();
    //     cin >> s;
    //     len = s.length();
    //     cout << len << endl;
    //     // 조기종료 : 길이가 홀수인 경우, 첫 시작이 `)`인 경우, 끝이 `(`인 경우
    //     if ((len%2 != 0) || (s[0] == ')') || (s[len-1] == '(')){
    //         cout << "No::조기종료\n";
    //         continue;
    //     }

    //     // vector에 대입
    //     for(int i = 0; i < len; i++){
    //         // cout << "벡터 만들기 : " << i+1 <<endl;
    //         // cout << s[i] << " ";
    //         // cout << "S :" << s << endl;
    //         arr.push_back(s[i]);
    //         // cout << arr[i] << ' ';  // debugging code
    //     } 
    //     cout << "벡터 삽입 완료\n";
        
    //     // iterator가 돌면서 앞뒤가 같으면 벡터에서 제거
    //     it = arr.begin();
    //     for (it+=1 ; it!=arr.end(); it++){
    //         if((*(it-1) == '(')&&(*it == ')')){
    //             arr.erase(it-1);
    //             arr.erase(it);

    //         }
    //     }

    //     if(arr.size()==0) cout << "Yes\n";
    //     else cout << "No\n";

    // }



}