#include <iostream>

using namespace std;
int N;
long long sum, tmp, num[10001];

// 거리의 합
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j)
                continue;
            sum += abs(num[i] - num[j]);
        }
    }

    cout << sum << "\n";

    return 0;
}