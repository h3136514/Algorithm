// 그리디, 정렬
#include <iostream>
#include <queue>

using namespace std;
int N, L, num;
priority_queue<int> q;

// 스네이크버드
int main(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> num;
        q.push(-num);
    }

    while(!q.empty()){
        if(-q.top() > L)
            break;
        
        q.pop();
        L++;
    }

    cout << L << "\n";

    return 0;
}