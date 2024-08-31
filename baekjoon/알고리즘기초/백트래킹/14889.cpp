#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX_VALUE  99999

using namespace std;
int N, a, b, num[21][21], visitied[21], sum;

void dfs(int cnt, int idx) {
    if(cnt == N/2) {
        a=0;
        b=0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if(visitied[i] && visitied[j])
                    a += num[i][j];
                else if(!visitied[i] && !visitied[j])
                    b += num[i][j];
            }
        
        sum = min(sum, abs(a-b));

        return;
    }

    for(int i = idx; i < N; i++) {
        if(!visitied[i]){
            visitied[i] = 1;
            dfs(cnt+1, i+1);
            visitied[i] = 0;
        }
    }
}


int main() {
    sum = MAX_VALUE;

    cin >> N;

    for(int i =0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> num[i][j];

    dfs(0, 0);
    cout << sum << endl;

    return 0;
}