#include <iostream>
#include <queue>

using namespace std;
queue <pair<int, int>> q;   // 중요도와 해당하는 인덱스 저장
priority_queue<int> import; // 중요도가 큰 순서로 저장
int T, N, M, CNT, num;

// 초기화
void init() {
    CNT = 0;
    while(!q.empty())
        q.pop();
    while(!import.empty())
        import.pop();
}

void printerQueue() {
    while(!q.empty()) {
        int value = q.front().first;
        int idx = q.front().second;
        q.pop();
        int target = import.top();

        // 중요도가 가장 높은게 아니면
        if(target != value){
            q.push({value, idx});
            continue;
        }

        import.pop();
        CNT++;

        // 해당 문서가 궁금한 문서라면
        if(idx == M)
            break;


    }
}

// 프린터 큐
int main() {
    cin >> T;
    while(0 < T--) {
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            cin >> num;
            q.push({num, i});
            import.push(num);
        }

        printerQueue();
        cout << CNT << "\n";

        init();
    }
    return 0;
}