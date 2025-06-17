/*
Platform        : 백준
Title           : 수 찾기 
Question Index  : 1920
Link            : https://www.acmicpc.net/problem/1920

Prosess         : 푸는 중

*/
/*
# Test Case
## Input
5
4 1 5 2 3
5
1 3 7 9 5

## Output
1
1
0
0
1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int n;
    cin >> n;

    vector<int> a_Arr(n);           // n개의 숫자 배열
    for(int i = 0; i < n; ++i){
        cin >> a_Arr[i];
    }

    int m;
    cin >> m;
    vector<int> x_Arr(m);

    vector<int> test = {1,2,3,4,5};

    for (int i = 0; i < m; ++i){
        cin >> x_Arr[i];

        int tmp = find(a_Arr.begin(), a_Arr.end(), x_Arr[i]) - a_Arr.begin();
        if (tmp == n) cout << 0 <<"\n";
        else cout << 1 << "\n";
    }


}