#include<cstdio>
#include<string>
using namespace std;
 
int A, B, C, D;
string AB, CD;
long long add;
 
int main() {
 
    scanf("%d%d%d%d", &A, &B, &C, &D);
    AB = to_string(A) + to_string(B);
    CD = to_string(C) + to_string(D);
    add = stoll(AB) + stoll(CD);
    printf("%lld", add);
    return 0;
}