#include <iostream>
#include <queue>

using namespace std;
int N, num, CNT;
priority_queue<int> q;

// 카드 정렬하기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        q.push(-num);
    }
    
    if(N == 1){
        CNT = 0;
    }else{
        while(!q.empty()){
            int sum = 0;
            sum += -q.top();
            q.pop();

            if(!q.empty()){
                sum += -q.top();    // 가장 작은 두 수를 더함
                q.pop();
                if(!q.empty())
                    q.push(-sum);
            }

            CNT += sum;
        }
    }
    
    cout << CNT << "\n";

    return 0;
}