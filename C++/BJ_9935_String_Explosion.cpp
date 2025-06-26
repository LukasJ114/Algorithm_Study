/*
Platform        : 백준
Title           : 문자열 폭발
Question Index  : 9935
Link            : https://www.acmicpc.net/problem/9935
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string Input_Str, Trigger;
    string::reverse_iterator rit;   // Trigger 순회를 위한 Iterator
    stack<char> input;      // 입력받은 문자열을 저장하는 스택
    stack<char> comp;       // 비교할 때 임시 저장하는 스택
    stack<char> output;     // 출력을 위한 스택
    bool bomb;      // 폭탄 의심 여부
    
    cin >> Input_Str;
    cin >> Trigger;

    int len = Trigger.length();
    char key = Trigger[len-1];
    
    for (char c: Input_Str){
        input.push(c);

        // 입력받은 문자열이 Trigger보다 길고, 현재 문자열이 Trigger의 마지막 문자와 같을 때
        if((input.size() >= len) && (key == c)){    
            bomb = 1;   // 폭탄 의심 On
            // Reverse iterator를 이용해서 Trigger의 뒤부터 순회
            for(rit = Trigger.rbegin(); rit!=Trigger.rend(); rit++){
                if(input.top() == *rit){    // Trigger와 input이 일치하는지 확인
                    comp.push(*rit);
                    input.pop();
                }
                else{
                    bomb = 0;   // 폭탄 의심 해제
                    break;
                }
            }
            // input stack에서 삭제한 내용 원상복구
            while((bomb == 0) && (!comp.empty())){
                input.push(comp.top());
                comp.pop();
            }
            while(!comp.empty()) comp.pop();    // comp stack clear
        }
    }

    // 출력 : 문자열이 다 폭발해서 남은게 없는 경우
    if (input.empty()){
        cout << "FRULA" << endl;
        return 0;
    }

    // 출력을 위해 스택의 순서를 맞추기 위해 다른 스택으로 옮겨서 출력
    // 스택 옮기기
    while(!input.empty()){
        output.push(input.top());
        input.pop();
    }
    // 출력
    while(!output.empty()){
        cout << output.top();
        output.pop();
    }



}