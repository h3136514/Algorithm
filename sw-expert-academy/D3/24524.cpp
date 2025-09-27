#include <iostream>
#include <vector>
#include <cmath>

#define MAX 987654321
using namespace std;
int T, N, a, sum = MAX;
vector<int> X;

void init(){
    X.clear();
    sum = MAX;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        X.resize(N);
        for(int i = 0; i < N; i++)
            cin >> X[i];
        
        for(int target = 1; target < N-1; target++){
            int cnt = 0;
            for(int i = 0; i < N-1; i++){
                if(i == target)
                    continue;
                if(i+1 == target){
                    cnt += abs(X[i] - X[i+2]);
                }else
                    cnt += abs(X[i] - X[i+1]);
            }
            sum = min(sum, cnt);
        }

        cout << sum << "\n";

        init();
    }

    return 0;
}