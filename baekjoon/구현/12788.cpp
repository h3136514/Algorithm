#include <iostream>
#include <queue>

using namespace std;
int N, M, K, num, sum, cnt;
bool check = false;
priority_queue<int> q;

// 제 2회 IUPC는 잘 개최될 수 있을까? 
int main(){
    cin >> N;
    cin >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> num;
        q.push(num);
    }

    while(!q.empty()){
        sum += q.top();
        q.pop();
        cnt++;

        if(M*K <= sum){
            check = true;
            break;
        }
    }

    if(check)
        cout << cnt << "\n";
    else
        cout << "STRESS\n";

    return 0;
}