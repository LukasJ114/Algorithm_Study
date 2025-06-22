/*
Platform        : 백준
Title           : 문자열 집합
Question Index  : 1425
Link            : https://www.acmicpc.net/problem/14425

Prosess         : complete
*/
/*
#Input
3 5
1 2 4
2 3 4 5 6

#Output
4
*/

#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<int, int> A, B;
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        A[tmp] ++;
    }
    for(int i = 0; i < M; i++){
        cin >> tmp;
        B[tmp]++;
    }

    map<int, int> mTmp;
    map<int, int>::iterator it;
    mTmp = A;
    int sum = 0;
    int cnt = 0;


    for (it = B.begin(); it != B.end(); it++){
        if(A.count(it->first)){
            continue;
        }
        else cnt++;
    }
    sum += cnt;
    cnt = 0;
    for(it = A.begin(); it != A.end(); it++){
        if(B.count(it->first)){
            continue;
        }
        else cnt++;
    }
    sum += cnt;
    cout << sum;
}