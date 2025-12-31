#include <iostream>

using namespace std;
int N, maxNum, minNum;

// 피보나치 치킨
int main(){
    cin >> N;

    if(N%2 == 0){
        minNum =  N/2;
    }else{
        minNum = 2 + (N-3)/2;
    }

    if(N%3 == 1){
        maxNum = 2 + (N-4)/3*2;
    }else if(N%3 == 2){
        maxNum = 1 + (N-2)/3*2;
    }else{
        maxNum = N/3*2;
    }

    cout << minNum << " " << maxNum << "\n"; 

    return 0;
}