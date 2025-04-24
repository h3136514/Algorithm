#include <iostream>

using namespace std;
int N, A[1002], B[1002], dp1[1002], dp2[1002], maxA, maxB;

// 세기의 대결
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        A[N+i] = A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
        B[N+i] = B[i];
    }

    for(int start = 0; start < N; start++){
        for(int i = 0; i < N; i++){
            int pos = start + i;
            
            dp1[i] = 1;
            dp2[i] = 1;
            for(int j = 0; j < i; j++){
                if(A[pos] > A[start+j]){
                    dp1[i] = max(dp1[i], dp1[j]+1);
                }
                if(B[pos] > B[start+j]){
                    dp2[i] = max(dp2[i], dp2[j]+1);
                }
            }
    
            maxA = max(maxA, dp1[i]);
            maxB = max(maxB, dp2[i]);
        }
    }
    for(int i = 0; i < N; i++){
        dp1[i] = 1;
        dp2[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
            if(B[i] > B[j]){
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }

        maxA = max(maxA, dp1[i]);
        maxB = max(maxB, dp2[i]);
    }

    if(maxA > maxB)
        cout << "YJ Win!\n";
    else if(maxA < maxB)
        cout << "HG Win!\n";
    else
        cout << "Both Win!\n";

    return 0;
}