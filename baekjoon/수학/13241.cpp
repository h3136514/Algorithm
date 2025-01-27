// 수학, 유클리드호제법
#include <iostream>

using namespace std;
long long A, B;

//유클리드호제법
long long gcd(long long a, long long b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

// 최소공배수
int main(){
    cin >> A >> B;

    cout << A*B / gcd(A, B) << "\n";

    return 0;
}