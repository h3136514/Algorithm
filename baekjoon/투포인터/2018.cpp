#include <iostream>

using namespace std;
int N, CNT, startNum, endNum, sum;

// 수들의 합 5 
int main(){
    cin >> N;

    CNT = 1;    // 자기 자신
    endNum = N/2 + 1;
    startNum = N/2;
    sum = startNum + endNum;
    while(startNum <= endNum && startNum > 0){
        if(sum == N){
            CNT++;
            sum -= endNum--;
            sum += --startNum;
        }
        else if(sum > N){
            sum -= endNum--;
        }else{
            sum += --startNum;
        }

    }

    cout << CNT << "\n";

    return 0;
}