#include<cstdio>
int n, m, _gcd;
//유클리드호제법
int gcd(int a, int b) {
    if (!b)return a;
    return gcd(b, a%b);
}

int main() {
    scanf("%d %d", &n, &m);
    _gcd = gcd(n, m);
    printf("%d\n%d", _gcd, n*m / _gcd);     //_gcd:최대공약수, n*m/_gcd: 최소공배수
}