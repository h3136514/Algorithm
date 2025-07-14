#include<iostream>

using namespace std;
int N, K, ans;

// 1
int main(){
    while(cin >> N){
        K = 1, ans = 1;
        while(true){
            if(ans % N == 0)
                break;
            
            K++;
            ans = ans*10 + 1;
            ans %= N;

        }

        cout << K << "\n";
    }

    return 0;
}