/*
Platform        : 백준
Title           : 피보나치 수 1
Question Index  : 24416
Link            : https://www.acmicpc.net/problem/24416
*/

#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 0, cnt2 = 0;

int fibo(int n){
    if((n == 1 || n == 2)){
        cnt1++;
        return 1;
    }
    else{
        return fibo(n-1) + fibo(n-2);
    }
}
/*
5
4, 3
3,2 / 2,1
2,1/ 2 / 2 / 1

*/

int fiboD(int n){
    vector<int> F(n+1, 0);
    F[1] = 1;
    F[2] = 1;

    for(int i = 3; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
        cnt2++;
    }

    return F[n];
}

int main(void){

    int n;
    cin >> n;
    fibo(n);
    fiboD(n);
    
    cout << cnt1 << " " << cnt2;;
}