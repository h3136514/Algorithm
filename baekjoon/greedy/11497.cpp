#include <iostream>
#include <algorithm>

using namespace std;
int T, N, h, num[100001];

// 통나무 건너뛰기
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> num[i];
        sort(num, num + N);

        for(int i = 2; i < N; i++)
            h = max(h, num[i] - num[i-2]);
        
        cout << h << "\n";

        h = 0;
    }

    return 0;
}