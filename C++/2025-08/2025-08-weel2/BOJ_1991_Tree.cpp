/*
Platform        : 백준
Title           : 트리순회
Question Index  : 1991
Link            : https://www.acmicpc.net/problem/1991
*/

#include <iostream>
#include <vector>

using namespace std;

vector<pair<char,char>> Tree;
int N;



void Input(){
    cin >> N;
    Tree.resize(N);
    char root, left, right;
    for(int i = 0; i < N; i++){
        cin >> root >> left >> right;

        Tree[root-'A'].first = left;
        Tree[root-'A'].second = right;
    }

}

void printTree(){
    for(int i = 0; i < N; i++){
        cout << i << Tree[i].first << Tree[i].second;
        cout << endl;
    }
}

// 전위탐색
void preorder(char curr){
    if(curr == '.') return;

    cout << curr;
    
    preorder(Tree[curr-'A'].first);

    preorder(Tree[curr-'A'].second);
}

// 중위탐색
void inorder(char curr){
    if(curr == '.') return;

    inorder(Tree[curr-'A'].first);

    cout << curr;

    inorder(Tree[curr-'A'].second);

}

//후위탐색
void postorder(char curr){
    if(curr == '.') return;
    
    postorder(Tree[curr-'A'].first);
    postorder(Tree[curr-'A'].second);
    cout << curr;
}

int main(void){
    Input();
    // printTree();


    preorder('A');

    cout << endl;

    inorder('A');

    cout << endl;

    postorder('A');



}