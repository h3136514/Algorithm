#include <iostream>
#include <queue>

using namespace std;
int N, L, num, pipe[1001], CNT;
priority_queue<int> leak;

// 수리공 항승
int main(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> num;
        leak.push(-num);
    }

    while(!leak.empty()){
        num = -leak.top();
        leak.pop();

        if(pipe[num])
            continue;
        
        CNT++;
        for(int i = num; i < num + L; i++){
            if(i > 1000)
                break;

            if(pipe[i])
                continue;
            pipe[i] = 1;
        }
        
    }

    cout << CNT << "\n";

    return 0;
}