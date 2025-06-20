#include <iostream>

using namespace std;
long long N, s, sum, value;

// 새치기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(s - sum > value)
            value = s - sum;
        sum += s;
    }

    cout << value << "\n";

    return 0;
}