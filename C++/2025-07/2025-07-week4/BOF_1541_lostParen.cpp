/*
Platform        : 백준
Title           : 잃어버린 괄호
Question Index  : 1541
Link            : https://www.acmicpc.net/problem/1541
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){

    string input;
    cin >> input;

    int Sum = 0;

    string eachNum;
    bool meetMinus = 0;     // Minus가 등장했는가? (1 : 등장했음 / 2 : 등장한 적 없음)
    input+='+';

    for(char c : input){
        // cout << "[c = " << c << "]" << endl;
        if(c == '+' || c == '-'){
            if(!meetMinus){ // +
                // cout << eachNum << endl;
                Sum += stoi(eachNum);
                eachNum = "";
            }   
            else{   // -
                // cout << eachNum << endl;
                Sum -= stoi(eachNum);
                eachNum = "";
            }

        }
        else{
            eachNum += c;
        }

        if(c == '-') meetMinus = 1;
    }

    cout << Sum;

}