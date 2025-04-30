// 자료구조
#include <iostream>
#include <queue>

using namespace std;
int N, x;
priority_queue<int> q;

// 최소 힙
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(q.empty())
                cout << "0\n";
            else{
                cout << -q.top() << "\n";
                q.pop();
            }
        }else{
            q.push(-x);
        }
    }

    return 0;
}