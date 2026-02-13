#include <iostream>

using namespace std;
int L, CNT;

// 조별과제를 하려는데 조장이 사라졌다
int main(){
    cin >> L;
    CNT = L/5;
    if(L % 5 != 0)
        CNT++;
    
    cout << CNT << "\n";

    return 0;
}