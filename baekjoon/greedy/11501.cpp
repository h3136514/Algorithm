#include <iostream>
#include <vector>

using namespace std;
int T, N, maxNum;
long long sum;
vector<int> v;

// 주식
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        v.resize(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }

        maxNum = v[N-1];
        for(int i = N-2; i >= 0; i--){
            if(v[i] > maxNum)
                maxNum = v[i];
            else
                sum += maxNum-v[i];
        }

        cout << sum << "\n";
        sum = 0;
        v.clear();
    }

    return 0;
}