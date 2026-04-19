// 냅색(Knapsack)
// https://school.programmers.co.kr/learn/courses/30/lessons/389480
#include <string>
#include <vector>

using namespace std;
int answer, bag[121]; // bag[m]은 B흔적이 m개일 떄 A흔적 합을 최대화

int solution(vector<vector<int>> info, int n, int m) {
    int sm = 0;
    for (int i = 0;i < info.size();i++){
        int a = info[i][0];
        int b = info[i][1];
        sm += a;
        for (int j = m; j >= b; j--)
            bag[j] = max(bag[j], bag[j - b] + a);
    }
    
    sm -= bag[m - 1];
    
    if (sm < n)
        answer = sm;
    else
        answer = -1;
    
    return answer;
}