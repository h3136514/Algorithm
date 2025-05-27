#include<iostream>

using namespace std;
int A, B;

// 상근이의 친구들
int main(){
    while(true){
        cin >> A >> B;
        if(A == 0 && B == 0)
            break;

        cout << A+B <<"\n";
    }

    return 0;
}
