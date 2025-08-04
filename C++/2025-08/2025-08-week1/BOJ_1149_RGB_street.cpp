/*
Platform        : 백준
Title           : RGB거리
Question Index  : 1149
Link            : https://www.acmicpc.net/problem/1149
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct RGB{
    int costR = 0;
    int costG = 0;
    int costB = 0;
};

struct House{
    int red = 0;
    int green = 0;
    int blue = 0;
};

int N;
vector<RGB> street;
vector<House> house;


void Input(){
    cin >> N;
    street.resize(N);
    house.resize(N);
    for(int i = 0; i < N; i++){
        cin >> street[i].costR >> street[i].costG >> street[i].costB;
    }
}

int main(void){
    Input();
    
    house[0].red = street[0].costR;
    house[0].green = street[0].costG;
    house[0].blue = street[0].costB;

    for(int i = 1; i < N; i++){
        house[i].red = min(house[i-1].blue, house[i-1].green) + street[i].costR;
        house[i].green = min(house[i-1].red, house[i-1].blue) + street[i].costG;
        house[i].blue = min(house[i-1].red, house[i-1].green) + street[i].costB;
    }
    
    cout << min(house[N-1].red, min(house[N-1].blue, house[N-1].green));

}

