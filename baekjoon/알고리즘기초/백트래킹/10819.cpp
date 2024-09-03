#include <iostream>
#include <algorithm>

using namespace std;
int N, num[9], arr[9], visitied[9], maxSum;

void dfs(int cnt) {
    if(cnt == N) {
        int sum = 0;
        for(int i = 1; i < N; i++) {
            sum += abs(arr[i-1] - arr[i]);
        }
        maxSum = max(maxSum, sum);

        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visitied[i]) {
            visitied[i] = 1;
            arr[cnt] = num[i];
            dfs(cnt+1);
            visitied[i] = 0;
        }
    }
}

// N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식(|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1])의 최댓값을 구하세요
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }

    dfs(0);

    cout << maxSum << endl;

    return 0;
}