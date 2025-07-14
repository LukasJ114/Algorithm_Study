/*
Platform        : 프로그래머스
Title           : 타켓넘버
Question Index  : 43165
Link            : https://school.programmers.co.kr/learn/courses/30/lessons/43165
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
// numbers : 주어진 숫자들, &target : 목표값(RO), nowSum : 계산값, deep : 몇번째 들어온 건지
void DFS(vector<int> numbers, int &target, int nowSum, int deep, int &answer){
    int numOfNumbs = numbers.size();
    if(deep >= numOfNumbs){
        // BFS END
        if (nowSum == target) answer++;
        return;
    }
    DFS(numbers, target, nowSum + numbers[deep], deep+1, answer);
    DFS(numbers, target, nowSum - numbers[deep], deep+1, answer);
    
}

int solution(vector<int> numbers, int target){
    int answer = 0;
    int numOfNumbs = numbers.size();
    int sum = 0;
    DFS(numbers, target, sum, 0, answer);
    return answer;
}