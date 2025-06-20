/*
Platform        : 백준
Title           : 숫자 카드 2 
Question Index  : 10816
Link            : https://www.acmicpc.net/problem/10816

Prosess         : 완료
*/
/*
# Input
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

# Output
3 0 0 1 2 0 0 2
*/

#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    map<int,int> map_N;
    int tmp = 0;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        if(map_N.count(tmp)) map_N[tmp] = map_N[tmp] + 1;
        else map_N.insert({tmp, 1});
    }

    int M;
    cin >> M;
    int output = 0;
    for(int i = 0; i < M; i++){
        cin >> output;
        if(map_N.count(output)) cout << map_N[output] << " ";
        else cout << 0 << " ";
    }
}

// int main(void){
//     map<int, int> m;
//     m.insert({1,4});
//     cout << m[1]+1;
// }