#include <iostream>
#include <queue>

using namespace std;
int N, num, A, CNT;
priority_queue<int> q;

// 국회의원 선거
int main() {
    cin >> N;
    cin >> A;
    for (int i = 1; i < N; i++) {
        cin >> num;
        q.push(num);
    }

    while (!q.empty()) {
        num = q.top();
        q.pop();

        if (A > num)
            break;

        CNT++;
        A++;
        num--;

        q.push(num);
    }

    cout << CNT << "\n";

    return 0;
}