/*
Platform        : 프로그래머스
Title           : 아이템 줍기
Question Index  : 87694
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/87694
*/

#if 1
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> Map(102, vector<int>(102,0));
vector<vector<int>> visited(102, vector<int>(102,0));

void printMap(){
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }
}
void printVisited(){
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            cout.width(2);
            cout << visited[i][j];
            
            cout << " ";
        }
        cout << "\n";
    }
}

void MakeSquare(int x1, int y1, int x2, int y2){
    x1 = x1 * 2;
    x2 = x2 * 2;
    y1 = y1 * 2;
    y2 = y2 * 2;
    
    // 사각형 내부 2로 채우기
    for(int x = x1+1; x <= x2-1; x++){
        for(int y = y1+1; y <= y2-1; y++){
            Map[y][x] = 2;
        }
    }
    
    // 사각형 테두리 2가 아닌 경우 1로 만들기.
    for(int x = x1; x <= x2; x++){
        if(Map[y1][x] != 2) Map[y1][x] = 1;
        if(Map[y2][x] != 2) Map[y2][x] = 1;
    }
    for(int y = y1; y <= y2; y++){
        if(Map[y][x1] != 2) Map[y][x1] = 1;
        if(Map[y][x2] != 2) Map[y][x2] = 1;
    }
}

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int startX, int startY, int GoalX, int GoalY){
    
    startX = startX * 2;
    startY = startY * 2;
    GoalX = GoalX * 2;
    GoalY = GoalY * 2;
    
    // 입력한 (StartY, startX) 방문 체크
    visited[startY][startX] = 1;
    
    queue<pair<int,int>> q;
    // 시작점 큐에 넣는다.
    q.push({startY, startX});

    
    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        
        // 현재 위치가 목표점에 도착하면 Return.
        if(nowX == GoalX && nowY == GoalY){
            return;
        }
        
        // 유효하지 않은 값 접근을 차단.
        if(nowX <= 0 || nowY <= 0 || nowX > 100 || nowY > 100){
            continue;
        }
        
        // 상하좌우 탐색
        for(int i = 0; i < 4; i++){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            
            // if(nextX <= 0 || nextY <= 0 || nextX > 50 || nextY > 50){
            //     continue;
            // }   
            // Map이 0과 2가 아니고 1인 경우. && 방문한적 없는 경우
            if(Map[nextY][nextX] == 1 && !visited[nextY][nextX]){
                q.push({nextY, nextX});
                visited[nextY][nextX] = visited[nowY][nowX] + 1;
                cout << "visited(next) : " << visited[nextY][nextX] << " / visited(now) : " << visited[nowY][nowX] << endl;
                cout << "Next : (" << nextX << ", " << nextY << ") / Now(R,C) : (" << nowX << ", " << nowY << ")" << endl;
            }
        }
    }
    
    
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 직사각형 개수
    int numOfRectangle = rectangle.size();
    
    // Map에 직사각형 그려주기
    for(int i = 0; i < numOfRectangle; i++){
        MakeSquare(rectangle[i][0], rectangle[i][1], rectangle[i][2], rectangle[i][3]);
    }
    

    printMap();
    
    BFS(characterX, characterY, itemX, itemY);
    
    printVisited();
    
    
    
    int answer = visited[itemY*2][itemX*2]/2;
    return answer;
}

#endif




#if 0
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> Map(52, vector<int>(52,0));
vector<vector<int>> visited(52, vector<int>(52,0));

void MakeSquare(int x1, int y1, int x2, int y2){
    // 사각형 내부 2로 채우기
    for(int x = x1+1; x <= x2-1; x++){
        for(int y = y1+1; y <= y2-1; y++){
            Map[y][x] = 2;
        }
    }
    
    // 사각형 테두리 2가 아닌 경우 1로 만들기.
    for(int x = x1; x <= x2; x++){
        if(Map[y1][x] != 2) Map[y1][x] = 1;
        if(Map[y2][x] != 2) Map[y2][x] = 1;
    }
    for(int y = y1; y <= y2; y++){
        if(Map[y][x1] != 2) Map[y][x1] = 1;
        if(Map[y][x2] != 2) Map[y][x2] = 1;
    }
}

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int startX, int startY, int GoalX, int GoalY){
    // 입력한 (StartY, startX) 방문 체크
    visited[startY][startX] = 1;
    
    queue<pair<int,int>> q;
    // 시작점 큐에 넣는다.
    q.push({startY, startX});

    
    while(!q.empty()){
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        
        // 현재 위치가 목표점에 도착하면 Return.
        if(nowX == GoalX && nowY == GoalY){
            return;
        }
        
        // 유효하지 않은 값 접근을 차단.
        if(nowX <= 0 || nowY <= 0 || nowX > 50 || nowY > 50){
            continue;
        }
        
        // 상하좌우 탐색
        for(int i = 0; i < 4; i++){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            
            // if(nextX <= 0 || nextY <= 0 || nextX > 50 || nextY > 50){
            //     continue;
            // }   
            // Map이 0과 2가 아니고 1인 경우. && 방문한적 없는 경우
            if(Map[nextY][nextX] == 1 && !visited[nextY][nextX]){
                q.push({nextY, nextX});
                visited[nextY][nextX] = visited[nowY][nowX] + 1;
                cout << "visited(next) : " << visited[nextY][nextX] << " / visited(now) : " << visited[nowY][nowX] << endl;
                cout << "Next : (" << nextX << ", " << nextY << ") / Now(R,C) : (" << nowX << ", " << nowY << ")" << endl;
            }
        }
    }
    
    
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 직사각형 개수
    int numOfRectangle = rectangle.size();
    
    // Map에 직사각형 그려주기
    for(int i = 0; i < numOfRectangle; i++){
        MakeSquare(rectangle[i][0], rectangle[i][1], rectangle[i][2], rectangle[i][3]);
    }
    
    // Map 출력
    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << endl << endl;
    // ==>> 정상 작동
    
    BFS(characterX, characterY, itemX, itemY);
    
    // visited 출력
    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    // ==>> 정상 작동
    
    int answer = visited[itemY][itemX] + 1;
    return answer;
}

#endif