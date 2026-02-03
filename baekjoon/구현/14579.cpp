#include <iostream>

using namespace std;
int a, b;
long long sum, result;

// 덧셈과 곱셈
int main(){
    cin >> a >> b;
    for(int i = 1; i <= a; i++){
        sum += i;
    }
    result = (sum) % 14579;

    for(int i = a+1; i <= b; i++){
        sum += i;
        result = (result*sum)%14579;
    }

    cout << result << "\n";

    return 0;
}