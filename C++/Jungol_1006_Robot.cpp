/*
Platform        : 정올
Title           : 로봇
Question Index  : 1006
Link            : https://jungol.co.kr/problem/1006?cursor=OCw1LDg%3D
*/

/* 
TODO : Line 127 Code Check. while문은 돌아가는데 결과 출력이 안나옴.

*/

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
    State() {}
    State(int R, int C, int H, int B) {
        row = R;
        col = C;
        heading = H;
        before = B;
    }
};
State StartPoint;
State GoalPoint;

// 1 : 동, 2 : 서, 3 : 남, 4 : 북
int dr[5] = { 0, 0, 0, -1, 1 };
int dc[5] = { 0, 1, -1, 0, 0 };


/*
TODO 1. 직진 기능 : 최대 3까지 한번에 갈 수 있다.
TODO 2. 우회전 : Heading을 오른쪽으로 90도 꺾기.
TODO 3. 좌회전 : Heading을 왼쪽으로 90도 꺾기.
*/
void Input();

State TurnRight(State Now) {
    if (Now.heading == 1) Now.heading = 3;
    else if (Now.heading == 2) Now.heading = 4;
    else if (Now.heading == 3) Now.heading = 2;
    else Now.heading = 1;
    Now.before = 0;
    return Now;
}

State TurnLeft(State Now) {
    if (Now.heading == 1) Now.heading = 4;
    else if (Now.heading == 2) Now.heading = 3;
    else if (Now.heading == 3) Now.heading = 1;
    else Now.heading = 2;
    Now.before = 0;
    return Now;
}
/*
회전 함수에서 아예 새로운 State를 선언해서 State로 리턴을 해줘야 할까?
*/


State MoveForward(State Now) {
    if (Now.heading == 1) {  // 동쪽
        Now.col += 1;
    }
    else if (Now.heading == 2) { //서쪽
        Now.col -= 1;
    }
    else if (Now.heading == 3) {// 남쪽
        Now.row -= 1;
    }
    else Now.row += 1;      // 북쪽

    Now.before++;

    return Now;
}


int FindWay(State Now, int way) {
    // 0 : Left, 1 : Right, 2 : 180
    if (Now.heading == 1) {
        if (way == 4) return 0;  // Left
        if (way == 3) return 1;  // Right
        else return 2;
    }
    else if (Now.heading == 2) {
        if (way == 3) return 0;
        if (way == 4) return 1;
        else return 2;
    }
    else if (Now.heading == 3) {
        if (way == 1) return 0;
        if (way == 2) return 1;
        else return 2;
    }
    else if (Now.heading == 4) {
        if (way == 2) return 0;
        if (way == 1) return 1;
        else return 2;
    }
    else cout << "FindWay 중 오류 발생";
}


void BFS(State Now) {
    // vector<vector<int>> visited(R, vector<int>(C, 0));

    queue<State> q;
    q.push(Now);
    // visited[Now.row][Now.col] = 1;

    int cnt = 0;

    while (!q.empty()) {
        cout << "CODE CHECK\n"; 
        State nowState = q.front();
        q.pop();

        for (int nextWay = 1; nextWay <= 4; nextWay++) {
            int nextRow = nowState.row + dr[nextWay];
            int nextCol = nowState.col + dc[nextWay];
            State nextState = State(nextRow, nextCol, nextWay, nowState.before);

            if (nextRow < 0 || nextCol < 0 || nextRow >= R || nextCol >= C) continue;

            if (!Map[nextRow][nextCol]) {     // 탐색한 곳이 길일 때
                if (nowState.heading == nextWay) {     // 현재 방향과 탐색한 곳이 일치할 때 :: 전진
                    if (nowState.before == 0) {    // 첫번째 전진
                        q.push(MoveForward(nowState));
                        cnt++;
                    }
                    else if (nowState.before == 1 || nowState.before == 2) {
                        q.push(MoveForward(nowState));
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
                else {       // 현재 방향과 탐색한 곳의 방향이 다를 때.  // 회전
                    int way = FindWay(nowState, nextWay);
                    if (way == 0) {      // Left
                        q.push(TurnLeft(nowState));
                        cnt++;
                    }
                    else if (way == 1) {  // Right
                        q.push(TurnRight(nowState));
                        cnt++;
                    }
                    else if (way == 2) {  // 180 degree
                        q.push(TurnRight(nowState));
                        cnt++;
                    }
                    else {
                        // TODO : 방향이 같은데 여기까지 들어오는 오류가 발생함. >> 해결.
                        // TODO : 180도 반대 방향에서 오류 발생 >> 해결.
                        cout << "**에러 발생** \nWay = " << way << endl;
                        cout << "nowState(r,c,h) : " << nowState.row << " " << nowState.col << " " << nowState.heading << endl;
                        cout << "nextWay : " << nextWay << endl;
                        return;
                    }
                }
            }


        }

    }
    cout << cnt;
}

int main() {
    Input();
    cout << "Input 완료\n";
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
    // cin >> State[0][0] >> State[0][1] >> State[0][2];
    // cin >> State[1][0] >> State[1][1] >> State[1][2];

    cin >> StartPoint.row >> StartPoint.col >> StartPoint.heading;
    cin >> GoalPoint.row >> GoalPoint.col >> GoalPoint.heading;


    // //! Debugging Code
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++){
    //         cout << Map[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << "Start : " << State[0][0] << " " << State[0][1] << " " << State[0][2] << endl;
    // cout << "Goal  : " << State[1][0] << " " << State[1][1] << " " << State[1][2];
}
