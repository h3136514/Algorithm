// 피보나치 수 분배 
#include <iostream>
#include <string>

using namespace std;
int T, N;
long long num[101];

int main(){
    // X, BA, BBA 반복(피보나치 수열이므로)
    cin >> T;
    while(T--){
        cin >> N;
        if(N%3 == 1)
            cout << "impossible\n";
        else{
            int idx = N/3;
            N %= 3;
            if(N == 2)
                cout << "BA";

            while(idx--)
                cout << "BBA";
            cout << "\n";
        }
    }

    return 0;
}