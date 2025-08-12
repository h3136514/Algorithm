#include <iostream>
#include <cmath>

using namespace std;
int N, M, result;

int gcd(int a, int b) {
    if (!b)return a;
    return gcd(b, a%b);
}

// 스승님 찾기
int main() {
    cin >> N >> M;
   
    result = min(gcd(abs(M), abs(N)), 2);

    cout << result << "\n";
    
    return 0;
}