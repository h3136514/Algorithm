#include <iostream>
#include <string>

using namespace std;
string A, B;
long long minSum, maxSum;

// 5와 6의 차이
int main(){
    cin >> A >> B;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '5')
            A[i] = '6';
    }
    for(int i = 0; i < B.size(); i++){
        if(B[i] == '5')
            B[i] = '6';
    }
    maxSum = stoll(A) + stoll(B);

    for(int i = 0; i < A.size(); i++){
        if(A[i] == '6')
            A[i] = '5';
    }
    for(int i = 0; i < B.size(); i++){
        if(B[i] == '6')
            B[i] = '5';
    }
    minSum = stoll(A) + stoll(B);

    cout << minSum << " " << maxSum << "\n";

    return 0;
}