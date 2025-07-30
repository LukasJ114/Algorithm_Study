/*
Platform        : 백준
Title           : 1로 만들기 2
Question Index  : 12852
Link            : https://www.acmicpc.net/problem/12852
*/

#include <iostream>
#include <vector>

using namespace std;

struct Num{
    int cost = 0;
    vector<int> way;
};


int N;

int main(void){
    cin >> N;

    vector<Num> Nums(N+1);
    Nums[1].way.push_back(1);

    for(int i = 2; i <= N; i++){
        Nums[i].cost = Nums[i-1].cost + 1;
        Nums[i].way = Nums[i-1].way;
        Nums[i].way.push_back(i);
        
        if(i % 2 == 0){
            if((Nums[i/2].cost + 1) < Nums[i].cost){
                Nums[i].cost = (Nums[i/2].cost + 1);
                Nums[i].way = Nums[i/2].way;
                Nums[i].way.push_back(i);
            }
        }
        if(i % 3 == 0){
            if((Nums[i/3].cost + 1) < Nums[i].cost){
                Nums[i].cost = (Nums[i/3].cost + 1);
                Nums[i].way = Nums[i/3].way;
                Nums[i].way.push_back(i);
            }
        }
    
    }
    cout << Nums[N].cost << endl;
    
    vector<int> :: reverse_iterator rit;

    for(rit = Nums[N].way.rbegin(); rit != Nums[N].way.rend(); rit++){
        cout << (*rit) << " ";
    }



}