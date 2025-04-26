#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, W, L, currentW, idx, CNT, sum;
vector<int> v;
queue<pair<int, int>> q;

// 트럭
int main(){
    cin >> N >> W >> L;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    while(CNT < N){
        if(!q.empty()){
            if(sum == q.front().first){
                int num = q.front().second;
                currentW -= v[num];
                q.pop();

                CNT++;
            }
        }

       if(idx < N && currentW + v[idx] <= L){
            q.push({sum + W, idx});
            currentW += v[idx++];
       }
       
        sum++;
    }

    cout << sum << "\n";

    return 0;
}