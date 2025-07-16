/*
Platform        : 정올
Title           : 로봇
Question Index  : 1006
Link            : https://jungol.co.kr/problem/1006?cursor=OCw1LDg%3D
*/

/*


*/


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_N (102)
enum {East, West, South, North};
int dr[] = {0, 0, 1, -1 };  // 방향: 인덱스 0=동,1=서,2=남,3=북
int dc[] = {1, -1, 0, 0 };
int turn[][4] = { 
    { North, South, East, West },
    { South, North, West, East }
};

int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N][4];

typedef struct _node {
    int r, c, dir;
}node;
node Queue[MAX_N * MAX_N * 4];
int front, rear;

int R, C;
node sPos, ePos;

void input_data(void) {
    int temp;
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            scanf("%d", &temp);
            map[i][j] = !temp;
        }
    }
    scanf("%d %d %d", &sPos.r, &sPos.c, &sPos.dir);
    scanf("%d %d %d", &ePos.r, &ePos.c, &ePos.dir);
    --sPos.dir;
    --ePos.dir;
}

void print_data(void) {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_visit(void) {
    for (int k = 0; k < 4; ++k) {
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                printf("%d ", visit[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
   
}

int BFS(void) {
    // 시작위치를 Queue에 넣고, 방문표시
    Queue[rear++] = sPos;
    visit[sPos.r][sPos.c][sPos.dir] = 1;

    while (front != rear) {
        // 하나의 노드꺼내기
        node curr = Queue[front++];
        int cnt = visit[curr.r][curr.c][curr.dir];
        if (curr.r == ePos.r && curr.c == ePos.c && curr.dir == ePos.dir) {
            printf("front %d\n", front);
            return cnt - 1;
        }
        
        // 인접찾기
        // 1, 2, 3 이동
        for (int i = 1; i <= 3; ++i) {
            int nR = curr.r + dr[curr.dir] * i;
            int nC = curr.c + dc[curr.dir] * i;
            if (!map[nR][nC]) break;  // 이동 실패시 나머지도 이동하면 안됨
            if (visit[nR][nC][curr.dir]) continue;

            //if (nR == ePos.r && nC == ePos.c && curr.dir == ePos.dir) {
            //    printf("front %d\n", front);
            //    return cnt;
            //}

            //  범위 밖에 0으로 채워놓았기 때문에 범위 검사는 생략
            Queue[rear++] = (node){ nR, nC, curr.dir };
            visit[nR][nC][curr.dir] = cnt + 1;
        }
        // left, right Turn
        for (int i = 0; i < 2; ++i) {
            int nDir = turn[i][curr.dir];
 
            if (visit[curr.r][curr.c][nDir]) continue;
            //if (curr.r == ePos.r && curr.c == ePos.c && nDir == ePos.dir) {
            //    printf("front %d\n", front);
            //    return cnt;
            //}
            Queue[rear++] = (node){ curr.r, curr.c, nDir };
            visit[curr.r][curr.c][nDir] = cnt + 1;

        }
    }
    return -1;  // 도착 못함
}

int main(void) {
    input_data();
    //print_data();
    printf("%d\n", BFS());
    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<vector<bool>> Map;   // 1 : Wall, 0 : Road
// vector<vector<int>> State(2, vector<int>(3,0));

struct State {
    int row;
    int col;
    int heading;    // 1 : 동, 2 : 서, 3 : 남, 4 : 북
    int before;
    int cnt;
    State() {}
    State(int R, int C, int H, int B, int CNT) {
        row = R;
        col = C;
        heading = H;
        before = B;
        cnt = CNT;
    }
};
State StartPoint;
State GoalPoint;

// 1 : 동, 2 : 서, 3 : 남, 4 : 북
int dr[5] = { 0, 0, 0, 1, -1 };
int dc[5] = { 0, 1, -1, 0, 0 };


/*

*/
void Input();

State TurnRight(State Now) {
    if (Now.heading == 1) Now.heading = 3;
    else if (Now.heading == 2) Now.heading = 4;
    else if (Now.heading == 3) Now.heading = 2;
    else Now.heading = 1;
    Now.before = 0;
    Now.cnt++;
    //  cout << "[우회전]\n";
    return Now;
}

State TurnLeft(State Now) {
    if (Now.heading == 1) Now.heading = 4;
    else if (Now.heading == 2) Now.heading = 3;
    else if (Now.heading == 3) Now.heading = 1;
    else Now.heading = 2;
    Now.before = 0;
    Now.cnt++;
    // cout << "[좌회전]\n";
    return Now;
}
/*
? 회전 함수에서 아예 새로운 State를 선언해서 State로 리턴을 해줘야 할까?
*/


State MoveForward(State Now) {
    int beforeRow;
    int beforeCol;
    if (Now.heading == 1) {  // 동쪽
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.col += 1;
    }
    else if (Now.heading == 2) { //서쪽
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.col -= 1;
    }
    else if (Now.heading == 3) {// 남쪽
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.row += 1;
    }
    else {
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.row -= 1;      // 북쪽
    }
    Now.before++;
    // cout << "[전진 :: (" << beforeRow << "," << beforeCol << ") => (" << Now.row << "," << Now.col << ") ]\n";
    return Now;
}


int FindWay(State Now, int way) {
    // 0 : Left, 1 : Right, 2 : 180
    if (Now.heading == 1) {     // 동쪽. 오른쪽
        if (way == 4) return 0;     // Left
        if (way == 3) return 1;     // Right
        else return 2;
    }
    else if (Now.heading == 2) {    // 서쪽. 왼쪽
        if (way == 3) return 0;     // Left
        if (way == 4) return 1;     // Right
        else return 2;
    }
    else if (Now.heading == 3) {    // 남쪽. 아래쪽
        if (way == 1) return 0;     // Left
        if (way == 2) return 1;     // Right
        else return 2;
    }
    else if (Now.heading == 4) {    // 북쪽. 위쪽
        if (way == 2) return 0;     // Left
        if (way == 1) return 1;     // Right
        else return 2;
    }
    else cout << "FindWay 중 오류 발생";
}
bool compState(State s1, State s2) {
    if (s1.row == s2.row && s1.col == s2.col && s1.heading == s2.heading) return 1;
    return 0;
}


void BFS(State Now) {
    vector<vector<int>> visited(R + 1, vector<int>(C + 1, 0));
    for (int i = 0; i <= R; i++) {
        visited[i][0] = 1;
    }
    for (int i = 0; i <= C; i++) {
        visited[0][i] = 1;
    }

    queue<State> q;
    q.push(Now);
    visited[Now.row][Now.col] = 1;

    int cnt = 0;

    while (!q.empty()) {
        State nowState = q.front();
        q.pop();

        // cout << "\n now : (" << nowState.row << "," << nowState.col << " " << nowState.heading << ")\n";
        // cout << "nowState CNT " << nowState.cnt << endl;

        //* 현재 좌표와 목표 좌표의 헤딩값을 제외한 R, C 값이 같을 때. >> 목적지 도착. 주차 
        if (nowState.row == GoalPoint.row && nowState.col == GoalPoint.col) {
            //* 헤딩 방향만 맞춰준다.
            while (nowState.heading != GoalPoint.heading) {
                int way = FindWay(nowState, GoalPoint.heading);
                // cout << "최종 방향전환 " << nowState.heading << " => " << GoalPoint.heading << endl;
                if (way == 0) {      // Left
                    nowState = TurnLeft(nowState);
                    
                }
                else if (way == 1) {  // Right
                    nowState = TurnRight(nowState);
                    
                }
                else if (way == 2) {  // 180 degree
                    nowState = TurnRight(nowState);

                }
            }
            cout << nowState.cnt;
            return;
        }


        for (int nextWay = 1; nextWay <= 4; nextWay++) {
            //cout << "for문 작동 중 : " << nextWay << endl;
            int nextRow = nowState.row + dr[nextWay];
            int nextCol = nowState.col + dc[nextWay];
            State nextState = State(nextRow, nextCol, nextWay, nowState.before, 0);
            //cout << "Next : (" << nextState.row << "," << nextState.col << ")\n";
            
            //* 유효하지 않은 범위 접근 차단
            if (nextRow < 1 || nextCol < 1 || nextRow > R || nextCol > C) continue;

            //cout << "!Map, !visited" << !Map[nextRow][nextCol] << " " << !visited[nextRow][nextCol] << endl;



            if (!Map[nextRow][nextCol] && !visited[nextRow][nextCol]) {     //* 탐색한 곳이 길일 때
                // cout << "\nCODE CHECK : " << nextWay << endl;
                if (nowState.heading == nextWay) {     //* 현재 방향과 탐색한 곳이 일치할 때 :: 전진
                    if (nowState.before == 0) {    // 첫번째 전진
                        State copy(nowState.row, nowState.col, nowState.heading, nowState.before, nowState.cnt);
                        copy.cnt++;
                        q.push(MoveForward(copy));
                        visited[nextRow][nextCol] = 1;

                    }
                    else if (nowState.before == 1 || nowState.before == 2) {
                        q.push(MoveForward(nowState));
                        visited[nextRow][nextCol] = 1;
                    }
                    else if (nowState.before == 3) {      // 이미 3번 전진했는데 앞에 또 직진인 경우.
                        nowState.before = 0;        // before 0으로 초기화 후 다시 전진
                        q.push(nowState);
                    }
                    else {
                        cout << "**전진 중 에러 발생** \n";
                        return;
                    }

                }
                else {       //* 현재 방향과 탐색한 곳의 방향이 다를 때.  // 회전
                    int way = FindWay(nowState, nextWay);
                    // cout << "방향전환 " << nowState.heading << " => " << nextWay << endl;
                    if (way == 0) {      // Left
                        q.push(TurnLeft(nowState));
                    }
                    else if (way == 1) {  // Right
                        q.push(TurnRight(nowState));
                    }
                    else if (way == 2) {  // 180 degree
                        q.push(TurnRight(nowState));
                    }
                    else {  // 문제 발생 코드
                        cout << "**에러 발생** \nWay = " << way << endl;
                        cout << "nowState(r,c,h) : " << nowState.row << " " << nowState.col << " " << nowState.heading << endl;
                        cout << "nextWay : " << nextWay << endl;
                        return;
                    }
                }
            }


        }

    }
    // cout << cnt;
}

int main() {
    Input();
    // cout << "Input 완료\n";
    BFS(StartPoint);
}


void Input() {
    cin >> R >> C;
    Map.resize(R + 1, vector<bool>(C + 1, 0));

    int tmp;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> tmp;
            Map[i][j] = tmp;
        }
    }

    for (int i = 0; i <= R; i++) {
        Map[i][0] = 1;
    }
    for (int i = 0; i <= C; i++) {
        Map[0][i] = 1;
    }
    // cin >> State[0][0] >> State[0][1] >> State[0][2];
    // cin >> State[1][0] >> State[1][1] >> State[1][2];

    cin >> StartPoint.row >> StartPoint.col >> StartPoint.heading;
    cin >> GoalPoint.row >> GoalPoint.col >> GoalPoint.heading;


    // //! Debugging Code
    // for (int i = 0; i <= R; i++) {
    //     for (int j = 0; j <= C; j++) {
    //         cout << Map[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << "Start : " << State[0][0] << " " << State[0][1] << " " << State[0][2] << endl;
    // cout << "Goal  : " << State[1][0] << " " << State[1][1] << " " << State[1][2];
}
#endif


#if 1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<vector<bool>> Map;   // 1 : Wall, 0 : Road
vector<vector<vector<int>>> visited;


struct State {
    int row;
    int col;
    int heading;    // 1 : 동, 2 : 서, 3 : 남, 4 : 북

    State() {}
    State(int R, int C, int H) {
        row = R;
        col = C;
        heading = H;
    }
};
State StartPoint;
State GoalPoint;

// 1 : 동, 2 : 서, 3 : 남, 4 : 북
int dr[5] = { 0, 0, 0, 1, -1 };
int dc[5] = { 0, 1, -1, 0, 0 };

void Input();
void printMap();
void printVisited();

int TurnRight(State Now) {
    if (Now.heading == 1) return 3;
    else if (Now.heading == 2) return 4;
    else if (Now.heading == 3) return 2;
    else if (Now.heading == 4) return 1;

    //  cout << "[우회전]\n";

}

int TurnLeft(State Now) {
    if (Now.heading == 1) return 4;
    else if (Now.heading == 2) return 3;
    else if (Now.heading == 3) return 1;
    else if (Now.heading == 4) return 2;


    // cout << "[좌회전]\n";
    // return Now;
}


State MoveForward(State Now) {
    int beforeRow;
    int beforeCol;
    if (Now.heading == 1) {  // 동쪽
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.col += 1;
    }
    else if (Now.heading == 2) { //서쪽
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.col -= 1;
    }
    else if (Now.heading == 3) {// 남쪽
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.row += 1;
    }
    else {
        beforeRow = Now.row;
        beforeCol = Now.col;
        Now.row -= 1;      // 북쪽
    }
    // Now.before++;
    // cout << "[전진 :: (" << beforeRow << "," << beforeCol << ") => (" << Now.row << "," << Now.col << ") ]\n";
    return Now;
}


int FindWay(State Now, int way) {
    // 0 : Left, 1 : Right, 2 : 180
    if (Now.heading == 1) {     // 동쪽. 오른쪽
        if (way == 4) return 0;     // Left
        if (way == 3) return 1;     // Right
        else return 2;
    }
    else if (Now.heading == 2) {    // 서쪽. 왼쪽
        if (way == 3) return 0;     // Left
        if (way == 4) return 1;     // Right
        else return 2;
    }
    else if (Now.heading == 3) {    // 남쪽. 아래쪽
        if (way == 1) return 0;     // Left
        if (way == 2) return 1;     // Right
        else return 2;
    }
    else if (Now.heading == 4) {    // 북쪽. 위쪽
        if (way == 2) return 0;     // Left
        if (way == 1) return 1;     // Right
        else return 2;
    }
    else cout << "FindWay 중 오류 발생";
}
bool compState(State s1, State s2) {
    if (s1.row == s2.row && s1.col == s2.col && s1.heading == s2.heading) return 1;
    return 0;
}

void printNow(State now){
    cout << "[[now 출력]]\n";
}


void BFS(State Now) {

    queue<State> q;
    q.push(Now);
    visited[Now.row][Now.col][Now.heading]= 1;
    


    while (!q.empty()) {
        State nowState = q.front();
        q.pop();
        int cnt = visited[nowState.row][nowState.col][nowState.heading];

        //* 전방 벽을 만나기 전까지
        for(int i = 1; i <=3; i++){
            int nextRow = nowState.row + dr[nowState.heading] * i;
            int nextCol = nowState.col + dc[nowState.heading] * i;
            cout << i << "칸 전진\n";
            if(Map[nextRow][nextCol] || visited[nextRow][nextCol][nowState.heading]) break;

            q.push(State(nextRow, nextCol, nowState.heading));
            visited[nextRow][nextCol][nowState.heading] = cnt + 1;
        }
        
        if(!visited[nowState.row][nowState.col][TurnLeft(nowState)]){
            q.push(State(nowState.row, nowState.col, TurnLeft(nowState)));
            visited[nowState.row][nowState.col][TurnLeft(nowState)];
        }
        if(!visited[nowState.row][nowState.col][TurnRight(nowState)]){
            q.push(State(nowState.row, nowState.col, TurnRight(nowState)));
            visited[nowState.row][nowState.col][TurnRight(nowState)];
        }

        /*
        // cout << "\n now : (" << nowState.row << "," << nowState.col << " " << nowState.heading << ")\n";
        // cout << "nowState CNT " << nowState.cnt << endl;

        //* 현재 좌표와 목표 좌표의 헤딩값을 제외한 R, C 값이 같을 때. >> 목적지 도착. 주차 
        if (nowState.row == GoalPoint.row && nowState.col == GoalPoint.col) {
            //* 헤딩 방향만 맞춰준다.
            while (nowState.heading != GoalPoint.heading) {
                int way = FindWay(nowState, GoalPoint.heading);
                // cout << "최종 방향전환 " << nowState.heading << " => " << GoalPoint.heading << endl;
                if (way == 0) {      // Left
                    nowState = TurnLeft(nowState);
                    
                }
                else if (way == 1) {  // Right
                    nowState = TurnRight(nowState);
                    
                }
                else if (way == 2) {  // 180 degree
                    nowState = TurnRight(nowState);

                }
            }
            cout << nowState.cnt;
            return;
        }


        for (int nextWay = 1; nextWay <= 4; nextWay++) {
            //cout << "for문 작동 중 : " << nextWay << endl;
            int nextRow = nowState.row + dr[nextWay];
            int nextCol = nowState.col + dc[nextWay];
            
            //cout << "Next : (" << nextState.row << "," << nextState.col << ")\n";
            
            //* 유효하지 않은 범위 접근 차단
            if (nextRow < 1 || nextCol < 1 || nextRow > R || nextCol > C) continue;

            //cout << "!Map, !visited" << !Map[nextRow][nextCol] << " " << !visited[nextRow][nextCol] << endl;
            //* 탐색한 곳이 길이면서 방문하지 않은 경우
            if (!Map[nextRow][nextCol] && !visited[nextRow][nextCol][nextWay]) {     //* 탐색한 곳이 길일 때
                // cout << "\nCODE CHECK : " << nextWay << endl;
                if (nowState.heading == nextWay) {     //* 현재 방향과 탐색한 곳이 일치할 때 :: 전진
                    if (nowState.before == 0) {    // 첫번째 전진
                        State copy(nowState.row, nowState.col, nowState.heading, nowState.before, nowState.cnt);
                        copy.cnt++;
                        q.push(MoveForward(copy));
                        visited[nextRow][nextCol] = 1;

                    }
                    else if (nowState.before == 1 || nowState.before == 2) {
                        q.push(MoveForward(nowState));
                        visited[nextRow][nextCol] = 1;
                    }
                    else if (nowState.before == 3) {      // 이미 3번 전진했는데 앞에 또 직진인 경우.
                        nowState.before = 0;        // before 0으로 초기화 후 다시 전진
                        q.push(nowState);
                    }
                    else {
                        cout << "**전진 중 에러 발생** \n";
                        return;
                    }

                }
                else {       //* 현재 방향과 탐색한 곳의 방향이 다를 때.  // 회전
                    int way = FindWay(nowState, nextWay);
                    // cout << "방향전환 " << nowState.heading << " => " << nextWay << endl;
                    if (way == 0) {      // Left
                        q.push(TurnLeft(nowState));
                    }
                    else if (way == 1) {  // Right
                        q.push(TurnRight(nowState));
                    }
                    else if (way == 2) {  // 180 degree
                        q.push(TurnRight(nowState));
                    }
                    else {  // 문제 발생 코드
                        cout << "**에러 발생** \nWay = " << way << endl;
                        cout << "nowState(r,c,h) : " << nowState.row << " " << nowState.col << " " << nowState.heading << endl;
                        cout << "nextWay : " << nextWay << endl;
                        return;
                    }
                }
            }


        }
        */

    }
    cout << visited[GoalPoint.row][GoalPoint.col][GoalPoint.heading];

}

int main() {
    Input();
    cout << "Input 완료\n";
    BFS(StartPoint);
}


void Input() {
    cin >> R >> C;
    Map.resize(R + 2, vector<bool>(C + 2, 0));
    visited.resize(R + 2, vector<vector<int>>(C + 2, vector<int>(5,0)));

    int tmp;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> tmp;
            Map[i][j] = tmp;
        }
    }

    for (int i = 0; i <= R+1; i++) {
        Map[i][0] = 1;
        Map[i][C+1] = 1;
    }
    for (int i = 0; i <= C+1; i++) {
        Map[0][i] = 1;
        Map[R+1][i] = 1;
    }

    cin >> StartPoint.row >> StartPoint.col >> StartPoint.heading;
    cin >> GoalPoint.row >> GoalPoint.col >> GoalPoint.heading;
}

void printMap(){
    for (int i = 0; i <= R+1; i++) {
        for (int j = 0; j <= C+1; j++) {
            cout << Map[i][j];
        }
        cout << endl;
    }
}
void printVisited(){
    for (int i = 0; i <= R+1; i++) {
        for (int j = 0; j <= C+1; j++) {
            for(int k = 0; k <= 4; k++){
                cout << visited[i][j][k] << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
}



#endif