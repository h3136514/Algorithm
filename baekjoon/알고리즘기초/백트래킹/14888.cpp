#include <iostream>

#define MAX_VALUE 1000000001
#define Min_VALUE -1000000001
using namespace std;
int N, A[11], oper[4];
int sumMax = Min_VALUE, sumMin = MAX_VALUE; 

void dfs(int cnt, int sum) {
    if(cnt == N) {
        if(sumMax < sum)
            sumMax = sum;
        if(sumMin > sum)
            sumMin = sum;

        return;
    }

    for(int i = 0; i < 4; i++) {
        if(!oper[i])
            continue;
        
       if(i == 0) {
            oper[i]--;
            dfs(cnt+1, sum+A[cnt]);
            oper[i]++;
       }else if(i == 1) {
            oper[i]--;
            dfs(cnt+1, sum-A[cnt]);
            oper[i]++;
       }else if(i == 2) {
            oper[i]--;
            dfs(cnt+1, sum*A[cnt]);
            oper[i]++;
       }else {
            oper[i]--;
            dfs(cnt+1, sum/A[cnt]);
            oper[i]++;
       }
    }
}

// N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램
int main() {

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < 4; i++)
        cin >> oper[i];

    dfs(1, A[0]);

    cout << sumMax << endl;
    cout << sumMin << endl;

    return 0;
}