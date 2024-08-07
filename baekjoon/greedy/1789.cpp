#include <iostream>

using namespace std;
long long S, N, sum;

int main() {
    cin >> S;

    while(S >= sum){
        sum += ++N;
    }

    cout << --N << endl;

    return 0;
}