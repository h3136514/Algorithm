#include <iostream>

using namespace std;
long long A, B, C, R;

// Divide & Conquer(a^b = a^(b/2) x a^(b/2))
long long power(long long b){
    if(b == 0)
        return 1;
    if(b == 1)
        return A % C;
    
    R = power(b/2) % C;
    if(b % 2 == 0)  //b가 짝수이면 
        return R * R % C;
    // b가 홀수이면 
    return  R * R % C * A % C;
    
}

// 곱셈
int main(){
    cin >> A >> B >> C;

    cout << power(B) << "\n";

    return 0;
}