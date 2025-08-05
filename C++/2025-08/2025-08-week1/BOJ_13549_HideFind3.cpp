/*
Platform        : 백준
Title           : 숨바꼭질3
Question Index  : 13549
Link            : https://www.acmicpc.net/problem/13549
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
// {시간, 위치}
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[100005];

void Input(){
    cin >> N >> K;
}

int main(void){
    Input();
    vector<int> timeTable(100001, 999999);
    
    timeTable[N] = 0;
    pq.push({0,N});


    while(!pq.empty()){
        int currTime = pq.top().first;
        int currPos = pq.top().second;

        pq.pop();

        if(currTime >= timeTable[currPos]) continue;

        if(currPos == K) break;


        if(2*currPos < 100001 && timeTable[2*currPos] > currTime){
            timeTable[2*currPos] = currTime;
            pq.push({currTime, 2*currPos});
        }
        if(currPos - 1 >= 0 && timeTable[currPos-1] > currTime){
            timeTable[currPos-1] = currTime + 1;
            pq.push({currTime+1, currPos-1});
        }
        if(currPos + 1 < 100001 && timeTable[currPos+1] > currTime){
            timeTable[currPos+1] = currTime + 1;
            pq.push({currTime+1, currPos + 1});
        }

    }

    cout << timeTable[K];



}


#if 0
/*
! 문제점
TODO 1. 메모리 개선
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<int> timeTable;
int maxSize, minSize;


void Input(){
    cin >> N >> K;
    
    if (N>K) {
        timeTable.resize(N*N, N+1);
        maxSize = N*N;
        minSize = 0;
    }
    else {
        timeTable.resize(K*K, K+1);
        maxSize = K*K;
        minSize = 0;
    }
}


int main(void){

    Input();

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(N);
    timeTable[N] = 0;

    // for(auto at : timeTable){
    //     cout << at << endl;
    // }
    // cout << maxSize << " , " << minSize <<endl;
    // cout << timeTable[17] << " " << timeTable[18] << " " << timeTable[19] << endl;

    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        // cout << "visit : " << now << ", cost : " << timeTable[now] << endl;

        // if(now == K){
        //     cout << timeTable[now];
        //     break;
        // }

        if((timeTable[now*2] > timeTable[now]) && (now*2 <= maxSize)){
            pq.push(now*2);
            timeTable[now*2] = timeTable[now];
        }

        if((timeTable[now+1] > (timeTable[now] + 1)) && (now+1 <= maxSize)){
            pq.push(now+1);
            timeTable[now+1] = timeTable[now] + 1;
        }

        //* (새로 갱신할 값이 기존에 있던 값보다 작을 때) && (범위 안의 값일 때)
        if((timeTable[now-1] > (timeTable[now] + 1)) && (now-1 >= minSize)){
            pq.push(now-1);
            timeTable[now-1] = timeTable[now] + 1;
        }


    }
    cout << timeTable[K];

}

#endif