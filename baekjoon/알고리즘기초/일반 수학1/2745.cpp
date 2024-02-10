#include<iostream>
#include<cmath>
using namespace std;
int B, sum;
string N;

int main(){
    cin >> N >> B;
    for(int i=0;i<N.length();i++){
        char ch = N[N.length() - 1 - i];
        if('0' <= ch && ch <= '9')
            sum += (ch - '0') * pow(B, i);
        else
            sum  += (ch - 'A' + 10) * pow(B, i);
    }
    cout << sum;
    return 0;
}