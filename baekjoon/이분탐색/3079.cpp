#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
unsigned long long startT = 1, endT, result;
vector<unsigned long long> v;

// 입국심사
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    endT = v[N-1] * M; // 최대시간
    result = endT;
    while(startT <= endT){
        unsigned long long mid = (startT + endT) / 2;
        unsigned long long cnt = 0;

        for(int i = 0; i < N; i++){
            cnt += mid / v[i];
        }

        if(cnt >= M){
            result = min(result, mid);
            endT = mid - 1;
        }else{
            startT = mid + 1;
        }
    }

    cout << result << "\n";

    return 0;
}