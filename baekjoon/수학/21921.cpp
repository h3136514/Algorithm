#include <iostream>

using namespace std;
int N, X, num[250001];
long long sum, maxSum, maxLen;

// 블로그
int main(){
    cin >> N >> X;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    for(int j = 0; j < X; j++){
        maxSum += num[j];
    }
    sum = maxSum;
    maxLen = 1;

    for(int i = 1; i <= N - X; i++){
        sum -= num[i-1];
        sum += num[i+X-1];

        if(maxSum == sum)
            maxLen++;
        else if(maxSum < sum){
            maxSum = sum;
            maxLen = 1;
        }
    }
    if(maxSum == 0)
        cout <<"SAD\n";
    else{
        cout << maxSum << "\n";
        cout << maxLen << "\n";
    }

    return 0;
}