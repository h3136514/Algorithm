#include <iostream>

using namespace std;
int N, P, Q, A[101], B[101], num[101];

// 마라탕후루
int main(){
    cin >> N >> P >> Q;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> B[i];
    }

    for(int i = 1; i <= N; i++){
        int cnt = 0;
        
        while(A[i] != B[i]){
            cnt++;
            A[i] += P;
            B[i] += Q;

            if(cnt == 10000){
                cout << "NO\n";
                return 0;
            }

        }

        num[i] += cnt;
    }

     cout << "YES\n";
    for(int i = 1; i <= N; i++){
        cout << num[i] << " ";
    }
    cout << "\n";

    return 0;
}