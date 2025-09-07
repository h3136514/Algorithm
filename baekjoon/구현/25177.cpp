#include <iostream>

using namespace std;
int N, M, gap, a[1001], b[1001];

// 서강의 역사를 찾아서
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }

    for(int i = 0; i < M; i++){
        if(N <= i)
            gap = max(gap, b[i]);
        else
            gap = max(gap, b[i]-a[i]);
    }

    cout << gap << "\n";

    return 0;
}