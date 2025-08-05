/*
Platform        : 백준
Title           : 최단경로
Question Index  : 1753
Link            : https://www.acmicpc.net/problem/1753
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int start;
    int goal;
    int weight;
};

int numV, numE;
int startNode;
vector<Edge> edges;

void Input(){
    cin >> numV >> numE;
    cin >> startNode;

    edges.resize(numE);
    for(int i = 0; i < numE; i++){
        cin >> edges[i].start >> edges[i].goal >> edges[i].weight;
    }

}

void printEdges(){
    for(int i = 0; i < numE; i++){
        cout << edges[i].start << " " <<  edges[i].goal << " " << edges[i].weight << endl; 
    }
}


int main(void){
    Input();
    // printEdges();


}