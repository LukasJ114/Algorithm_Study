/*
Platform        : 백준
Title           : 스택2
Question Index  : 28278
Link            : https://www.acmicpc.net/problem/28278
*/


#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Debugging Method
void printStack(stack<int>* stack){
    cout << stack->top() << endl;
}

#if 0
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<int> stack;
    string command;
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin, command);
        // cout << "command : " << command[0] << " " << command[2] << "\n";

        if (command[0] == '1') {          // 입력 :: 작동
            stack.push(command[2] - 48);
            cout << "Processed Command 1" << "\n";
        } 
        
        else if(command[0] == '2'){       // 출력 및 추출 :: 작동
            cout << stack.top() << "\n";
            stack.pop();
            cout << "Processed Command 2" << "\n";
        }
        else if(command[0] == '3') {      // 들어있는 정수의 개수 :: 작동
            if (stack.empty()) cout << -1 << "\n";
            else cout << stack.size() << "\n";
            cout << "processed Command 3" << '\n';
        }
        else if(command[0] == '4') {      // 비었으면 `1` 출력, 있으면 `0` 출력
            cout << stack.empty() << "\n";
            cout << "Processed Command 4" << "\n";
        }     
        else if(command[0] == '5') {      // 맨 위 출력
            if (stack.empty()) cout << -1 << "\n";
            else cout << stack.top() << "\n";
            cout << "Processed Command 5\n";
        }
        else cout << "You entered invalid command!" << "\n";
        // cout << "\n";
    }
}
#endif

#if 01
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    // cout << "N : " << N << endl;

    stack<int> stack;
    int command;
    int input;
    for(int i = 0; i < N; i++){
        // cout << "Loop " << i+1 << endl;
        cin >> command;

        if (command == 1) {          // 입력 :: 작동
            cin >> input;
            stack.push(input);
            // cout << "Processed Command 1" << "\n";
        } 
        
        else if(command == 2){       // 출력 및 추출 :: 작동
            if (stack.empty()) cout << -1 << "\n";
            else {
                cout << stack.top() << "\n";
                stack.pop();
            }
            // cout << "Processed Command 2" << "\n";
        }
        else if(command == 3) {      // 들어있는 정수의 개수 :: 작동
            cout << stack.size() << "\n";
            // cout << "processed Command 3" << '\n';
        }
        else if(command == 4) {      // 비었으면 `1` 출력, 있으면 `0` 출력
            cout << stack.empty() << "\n";
            // cout << "Processed Command 4" << "\n";
        }     
        else if(command == 5) {      // 맨 위 출력
            if (stack.empty()) cout << -1 << "\n";
            else cout << stack.top() << "\n";
            // cout << "Processed Command 5\n";
        }
        else cout << "You entered invalid command!" << "\n";
        // cout << "\n";
    }
    // cout << "For Loop completed sucessfully";
}


#endif