/*
Platform        : 백준
Title           : 줄 세우기
Question Index  : 2252
Link            : https://www.acmicpc.net/problem/2252
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Line;
vector<pair<int,int>> comp;
void Input(){
    cin >> N >> M;

    Line.resize(N+1);
    for(int i = 0; i <= N; i++){
        Line[i] = i;
    }
    comp.resize(M);
    for(int i = 0; i < M; i++){
        cin >> comp[i].first >> comp[i].second;
    }
}

void printLine(){
    vector<int> :: iterator it;
    for(it = Line.begin()+1; it != Line.end(); it++){
        cout << *it << " ";
    }
}
void printComp(){
    for(int i = 0; i < M; i++){
        cout << comp[i].first << " " << comp[i].second << endl;
    }
}

int getIndex(int value){
    return find(Line.begin(), Line.end(), value) - Line.begin();
}

int main(void){
    Input();
    
    
    for(int i = 0; i < M; i++){
        int indexFirst = getIndex(comp[i].first);
        int indexSecond = getIndex(comp[i].second);
        
        if(indexFirst < indexSecond) continue;      // 이미 순서가 맞는 경우
        else if(indexFirst == indexSecond) cout << "문제상황 발생 1\n";
        else{
            cout << "indexFirst, indexSecond : " << indexFirst << " " << indexSecond << endl;
            swap(Line[indexFirst], Line[indexSecond]);
        }

        bool flag = 0;
        if(indexFirst > indexSecond) flag = 1;
        while(flag){

            



        }

    }
    
    printLine();



}
