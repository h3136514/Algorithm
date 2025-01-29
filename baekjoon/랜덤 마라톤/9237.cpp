// 정렬, 그리디
#include <iostream>
#include <queue>

using namespace std;
int N, num, day;
priority_queue<int> q;

// 이장님 초대
int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        q.push(num);
    }

    for(int i = 1; i <= N; i++){
        day = max(day, i + q.top() + 1);
        q.pop();
    }

    cout << day << "\n";

    return 0;
}