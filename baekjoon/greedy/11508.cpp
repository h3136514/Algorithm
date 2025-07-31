#include <iostream>
#include <queue>

using namespace std;
int N, c, cnt;
long long sum;
priority_queue<int> q;

// 2+1 세일 
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c;
        q.push(c);
    }

    while(!q.empty()){
        cnt++;
        int target = q.top();
        q.pop();
        if(cnt%3 == 0)
            continue;
        
        sum += target;
    }

    cout << sum << "\n";

    return 0;
}