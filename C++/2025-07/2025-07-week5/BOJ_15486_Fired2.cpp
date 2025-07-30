/*
Platform        : 백준
Title           : 퇴사2
Question Index  : 15486
Link            : https://www.acmicpc.net/problem/15486
*/

#include <iostream>
#include <vector>

using namespace std;

struct Schedule{
    int time;
    int price;
    int money = 0;
};

int N;
vector<Schedule> schedules;

void Input(){
    cin >> N;
    schedules.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> schedules[i].time >> schedules[i].price;
    }
}

void printSchedules(){
    for(int i = 1; i <= N; i++){
        cout << i << "(T,P,M) : " << schedules[i].time << " " << schedules[i].price << " " << schedules[i].money << endl;
    }
}

int main(void){
    Input();
    // printSchedules();

    for (int i = 1; i <= N; i++){
        if(schedules[i].money == 0 || schedules[i].money < schedules[i-1].money) schedules[i].money = schedules[i-1].money;

        // 범위 넘어가는 경우 차단
        if(((i-1) + schedules[i].time) > N) continue;

        // 오늘 t일짜리 스케줄을 수행하면 스케줄 완료 후 Money
        int afterWorkMoney = schedules[i-1].money + schedules[i].price;
        // t일 후의 Money
        int preMoney = schedules[(i-1)+schedules[i].time].money;

        if (preMoney < afterWorkMoney){     // 스케줄 수행한 게 더 이익인 경우
            schedules[(i-1)+schedules[i].time].money = afterWorkMoney;
        }
        else continue;      // 아니면 넘어가기

    }
    // printSchedules();
    cout << schedules[N].money;

}