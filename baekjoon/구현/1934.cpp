#include <iostream>

using namespace std;
int T, A, B;
int gcd(int a, int b) {
    if (!b)return a;
    return gcd(b, a%b);
}

// 최소공배수
int main(){
    cin >> T;
    while(T--){
        cin >> A >> B;
        
        cout << A*B/gcd(A, B) << "\n";
    }

    return 0;
}