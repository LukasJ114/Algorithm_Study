/*
Platform        : 백준
Title           : 계단오르기
Question Index  : 2579
Link            : https://www.acmicpc.net/problem/2579
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stair{
    int value;
    int sum;
    int cnt;
};

int N;
vector<Stair> stairs;

void Input(){
    cin >> N;
    stairs.resize(N);
    for(int i = 0; i < N; i++){
        cin >> stairs[i].value;
        stairs[i].sum = 0;
        stairs[i].cnt = 0;
    }
}

// 앞에서 부터
#if 1
int main(void){
    Input();
    
    //* 1. 배열의 0번째 (1번 계단)
    stairs[0].sum = stairs[0].value;
    
    //* 2. 배열의 1번째 (2번 계단)
    stairs[1].sum = stairs[0].value + stairs[1].value;

    //* 3. 배열의 2번째 (3번 계단)
    stairs[2].sum = max(stairs[0].value + stairs[2].value, stairs[1].value + stairs[2].value);

    for(int i = 3; i < N; i++){
        stairs[i].sum = max(stairs[i].value + stairs[i-2].sum, stairs[i].value + stairs[i-1].value + stairs[i-3].sum);
    }

    cout << stairs[N-1].sum;


}
#endif

// 뒤에서 부터
#if 0
int main(void){

    Input();

    int i = N-1;
    stairs[i].sum = stairs[i].value;
    stairs[i].cnt = 1;

    i--;
    stairs[i].sum = stairs[i].value + stairs[i+1].sum;
    stairs[i].cnt = 2;


    i--;
    for(i; i >= 0; i--){
        if(stairs[i+1].cnt == 2){   // 이번이 연속 3번째인 경우
            stairs[i].sum = stairs[i+2].sum + stairs[i].value;  // 현재 sum = 전전 sum + 현재 value
            stairs[i].cnt = 1;
        }
        else{   
            int tmp1 = stairs[i+1].sum + stairs[i].value;   // 바로 전
            int tmp2 = stairs[i+2].sum + stairs[i].value;   // 두번 전
            if(tmp1 > tmp2){
                stairs[i].sum = tmp1;
                stairs[i].cnt = 2;
            }
            else{   // tmp1 <= tmp2
                stairs[i].sum = tmp2;
                stairs[i].cnt = 1;
            }
        }
    }

    if(stairs[0].sum > stairs[1].sum) cout << stairs[0].sum;
    else cout << stairs[1].sum;


}
#endif
