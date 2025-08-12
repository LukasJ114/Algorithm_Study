/*
Platform        : 백준
Title           : 최단경로
Question Index  : 1753
Link            : https://www.acmicpc.net/problem/1753
*/


#if 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numV, numE;
int startNode;
vector<vector<pair<int,int>>> edges;
vector<pair<bool, int>> visitNode;

void Input(){
    cin >> numV >> numE;
    cin >> startNode;

    edges.resize(numV+1);
    visitNode.resize(numV+1,{false, 0});

    for(int i = 1; i <= numE; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        cout << start << " " << end << " " << weight <<endl;
        edges[start].push_back({end, weight});
    }

}

void printEdges(){
    cout << "[[edges]]\n";
    for(int i = 1; i <= numV; i++){
        cout << i << " : ";
        int numEdge = edges[i].size();
        if(numEdge != 0){
            for(int j = 0; j < numEdge; j++){
                cout << "[" << edges[i][j].first << " " << edges[i][j].second << "] ";
            }
        }
        cout << endl;
    }
}

int main(void){
    Input();
    // printEdges();

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({startNode, 0});
    visitNode[startNode].first = true;

    while(!pq.empty()){
        int curr = pq.top().first;
        pq.pop();

        // 간선 없으면 생략
        if(edges[curr].size() == 0) continue;

        for(int i = 1; i <= numV; i++){

            if(visitNode[i])
            edges[curr][i].first

        }


    }





}

#endif


#if 0

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numV, numE;
int startNode;
vector<vector<int>> edges;
vector<pair<bool, int>> visitNode;

void Input(){
    cin >> numV >> numE;
    cin >> startNode;

    edges.resize(numV+1, vector<int>(numV+1));
    visitNode.resize(numV+1,{false, 0});

    for(int i = 1; i <= numE; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        edges[start][end] = weight;
    }


}

// void printEdges(){
//     for(int i = 0; i < numE; i++){
//         cout << edges[i].start << " " <<  edges[i].goal << " " << edges[i].weight << endl; 
//     }
// }

void printEdges(){
    for(int i = 1; i <= numV; i++){
        for(int j = 1; j <= numV; j++){
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}


int main(void){
    Input();
    // printEdges();

    visitNode[startNode].first = true;
    visitNode[startNode].second = 0;

    queue<int> q;
    q.push(startNode);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 1; i <= numV; i++){

            //* 연결이 안된 곳이면 continue
            if(edges[curr][i] != 0) continue;

            //* 방문한 적 없는 곳 : 방문체크, 비용 저장
            if(visitNode[i].first == 0) {
                visitNode[i].first = true;
                visitNode[i].second = edges[curr][i];
            }
            else{ //*방문한 적 있는 곳 : 비용 비교해서 낮은 값으로 갱신 
                if(visitNode[i].second > edges[curr][i]){
                    visitNode[i].second = edges[curr][i];
                }
            }
               
        }

    }

    // printEdges();

    for(int i = 1; i <= numV; i++){
        if(visitNode[i].first == 0){
            cout << "INF\n";
        }
        else{
            cout << visitNode[i].second << endl;
        }
    }
    


}

#endif