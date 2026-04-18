// https://school.programmers.co.kr/learn/courses/30/lessons/12946
#include <vector>
using namespace std;

vector<vector<int>> answer;

// n개를 from → to로 옮기기 (via = 경유 기둥)
void hanoi(int n, int from, int via, int to) {
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }
    hanoi(n - 1, from, to, via);   // n-1개를 from → via
    answer.push_back({from, to});   // 가장 큰 원판 from → to
    hanoi(n - 1, via, from, to);   // n-1개를 via → to
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return answer;
}