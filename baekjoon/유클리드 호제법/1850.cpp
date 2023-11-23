#include<cstdio>
long long A, B, C,_gcd;
//유클리드호제법
long long gcd(long long a, long long b) {
    if (!b)return a;
    return gcd(b, a%b);
}

int main(){
    scanf("%lld %lld", &A, &B);
    _gcd=gcd(A, B);
    while(_gcd--){
       printf("1");
    }
    return 0;
}