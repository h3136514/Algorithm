// 그리디
#include <iostream>

using namespace std;
int N, CNT;

// 거스름돈
int main(){
    cin >> N;
    if(N >= 5){
        if((N%5)%2 == 0)
            CNT = N/5 + N%5/2;
        else
            CNT = (N >= 10) ? N/5 - 1 + (N - (N/5 - 1)*5)/2 : N/2;
    }else
        CNT =(N%2 != 0) ? -1 : N/2;

    cout << CNT << "\n";

    return 0;
}