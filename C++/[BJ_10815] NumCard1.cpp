/*
Platform        : 백준
Title           : 숫자 카드 1
Question Index  : 10815
Link            : https://www.acmicpc.net/problem/10815

Prosess         : 푸는 중
*/
/*
# Input
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10

# Output
1 0 0 1 1 0 0 1
*/


#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tmp;
    cin >> n;
    map<int, int> nArr;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        nArr[tmp] += 1;
    }
    
    int m;
    cin >> m;
    for (int i= 0; i < m; i++){
        cin >> tmp;
        cout << nArr.count(tmp) << " ";
    }

}