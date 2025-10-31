#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N, M, result;
vector<int> A, B;

int binarySearch(int num){
    int idx = N;
    int s = 0, e = N-1;

    while(s <= e){
        int mid = (s+e)/2;

        if(A[mid] > num){
            idx = min(idx, mid);
            e = mid -1;
        }else{
            s = mid + 1;
        }
    }

    return idx;
}

// 먹을 것인가 먹힐 것인가
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        A.resize(N), B.resize(M);
        for(int i = 0; i < N; i++)
            cin >> A[i];
        for(int i = 0; i < M; i++)
            cin >> B[i];
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        for(int i = M-1; i >= 0; i--){
            int idx = binarySearch(B[i]);
           
            if(idx == N)
                continue;
            
            result += N - idx;
        }

        cout << result << "\n";

        result = 0;
        A.clear(), B.clear();
    }

    return 0;
}
