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

struct RGB1{
    pair<int,int> costR = {1,0};
    pair<int,int> costG = {2,0};
    pair<int,int> costB = {3,0};
};
struct RGB2{
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
vector<RGB2> street;
vector<House> house;


// void Input(){
//     cin >> N;
//     street.resize(N);
//     house.resize(N);
//     for(int i = 0; i < N; i++){
//         cin >> street[i].costR.second >> street[i].costG.second >> street[i].costB.second;
//     }
// }
void Input(){
    cin >> N;
    street.resize(N);
    house.resize(N);
    for(int i = 0; i < N; i++){
        cin >> street[i].costR >> street[i].costG >> street[i].costB;
    }
}

// pair<int,int> compRGB(RGB rgb){
//     int red = rgb.costR.second;
//     int green = rgb.costG.second;
//     int blue = rgb.costB.second;
    
//     if(red <= green && red <= blue){
//         return {1, red};
//     }
//     if(green <= red && green <= blue){
//         return {2, green};
//     }
//     if(blue <= red && blue <= green){
//         return {3, blue};
//     }
// }

// void printInput(){
//     cout << N << endl;
//     for(int i = 0; i < N; i++){
//         cout << "(" << street[i].costR.first << "," << street[i].costR.second << ") (" << street[i].costG.first << "," << street[i].costG.second << ") (" << street[i].costB.first << "," << street[i].costB.second << ")\n";
        
//     }
// }

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
    
    // cout << house[N-1].red << ", " << house[N-1].green << ", " << house[N-1].blue << endl;

    cout << min(house[N-1].red, min(house[N-1].blue, house[N-1].green));

}


#if 0
int main(void){

    Input();

    // printInput();
    int cost = 0;
    int before = 0; // R : 1, G : 2, B : 3
    
    
    before = compRGB(street[0]).first;
    cost += compRGB(street[0]).second;

    cout << "1번째 집(색, 누적가격) : " << before << "," << cost <<endl;

    for(int i = 1; i < N; i++){

        switch(before){
            case 1: // before = R
                if(street[i].costG.second < street[i].costB.second){
                    before = street[i].costG.first;
                    cost += street[i].costG.second;
                    cout << i+1 << "번째 집(색, 누적가격) : " << before << "," << cost <<endl;
                }
                else{
                    before = street[i].costB.first;
                    cost += street[i].costB.second;
                    cout << i+1 << "번째 집(색, 누적가격) : " << before << "," << cost <<endl;
                }
                break;
            case 2: // before = G
                if(street[i].costR.second < street[i].costB.second){
                    before = street[i].costR.first;
                    cost += street[i].costR.second;
                    cout << i+1 << "번째 집(색, 누적가격) : " << before << "," << cost <<endl;
                }
                else{
                    before = street[i].costB.first;
                    cost += street[i].costB.second;
                    cout << i+1 << "번째 집(색, 누적가격) : " << before << "," << cost <<endl;
                }
                break;
            case 3: // before = B
                if(street[i].costG.second < street[i].costR.second){
                    before = street[i].costG.first;
                    cost += street[i].costG.second;
                    cout << i+1 << "번째 집(색, 누적가격) : " << before << "," << cost <<endl;
                }
                else{
                    before = street[i].costR.first;
                    cost += street[i].costR.second;
                    cout << i+1 << "번째 집(색, 누적가격) : " << before << "," << cost <<endl;
                }
                break;
            default:
                cout << "Switch문 에러 발생" << endl;

        }

    }
    cout << cost;

}


#endif