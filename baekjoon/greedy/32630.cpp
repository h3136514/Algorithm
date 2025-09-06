#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long N, A, maxSum, sum1, sum2;
vector<long long> v;

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
        maxSum += v[i];
    }

    sort(v.begin(), v.end());
    sum1 = 2*(v[0]*v[1]);
    sum2 = 2*(v[N-1]*v[N-2]);

    for(int i = 2; i < N; i++){
        sum1 += v[i];
        sum2 += v[N-i-1];
    }

    maxSum = max(maxSum, sum1);
    maxSum = max(maxSum, sum2);

    cout << maxSum << "\n";

    return 0;
}