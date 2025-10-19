#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
double maxScore = 0, sum = 0;
vector<double> A;

// 나무 블럭 게임
int main(){
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }

    sort(A.begin(), A.end());
    if(N-2 >= 0)
        maxScore = A[N-2]; // 마지막 전꺼(2개일 때는 X)
    
    maxScore = max(maxScore, sum/N);

    cout<<fixed;
    cout.precision(6);  // 6자리수 까지
    cout << maxScore << "\n";

    return 0;
}