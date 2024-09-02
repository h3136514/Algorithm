#include <iostream>

using namespace std;
int k, a, num[14], arr[14], visitied[14];

void init() {
    for(int i = 0; i < 14; i++){
        num[i] = 0;
        arr[i] = 0;
    }
}

void dfs(int cnt, int idx) {
    if(cnt == 6) {
        for(int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    for(int i = idx; i < k; i++) {
        visitied[i] = 1;
        arr[cnt] = num[i];
        dfs(cnt+1, i+1);
        visitied[i] = 0;
    }
}

// 집합 S와 k(집합 S에 포함되는 갯수)가 주어졌을 때, (6개의)수를 고르는 모든 방법을 구하는 프로그램
int main() {
    while(true) {
        cin >> k;
        if(k == 0)
            break;
        
        init();
        for(int i = 0; i < k; i++)
            cin >> num[i];

        dfs(0, 0);
        cout << "\n";
    }

    return 0;
}