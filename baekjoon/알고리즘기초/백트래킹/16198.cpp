#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, maxSum;
vector<int> v, a;
priority_queue<pair<int, pair<int, int>>> q;

void copyV(vector<int> tmp, int n, int idx){
    for(int i = 0; i < idx; i++)
        a[i] = tmp[i];
    for(int i = idx; i < n-1; i++)
        a[i] = tmp[i+1];
}

void backtracking(vector<int> tmp, int n, int sum){
    if(n == 2){
        maxSum = max(maxSum, sum);
        return;
    }

    for(int i = 1; i < n-1; i++){
        int cal = tmp[i-1] * tmp[i+1];
        copyV(tmp, n, i);
        backtracking(a, n-1, sum+cal);
    }
}

// 에너지 모으기
int main(){
    cin >> N;
    v.resize(N), a.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    
    backtracking(v, N, 0);

    cout << maxSum << "\n";

    return 0;
}
