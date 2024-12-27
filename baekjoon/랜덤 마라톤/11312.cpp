// 수학, 사칙연산
#include <iostream>

using namespace std;
int T;
long long CNT;
double A, B;

// 삼각 무늬 - 2
int main(){
    cin >> T;
    while(T--){
        cin >>  A >> B;
        CNT  = (long long)((A*A/2) / (B*B/2));

        cout << CNT << "\n";
    }

    return 0;
}
