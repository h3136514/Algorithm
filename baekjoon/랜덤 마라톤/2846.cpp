// 구현
#include <iostream>

using namespace std;
int N, num[1001], maxHigh;

// 오르막길
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    for(int i = 1; i < N; i++){
        bool check = true;
        for(int j = i; j > 0; j--){
            if(num[j] <= num[j-1])  // 오른차순이 아니면 X
                check = false;
            
            if(check)
                maxHigh = max(maxHigh, num[i] - num[j-1]);
        }
    }

    cout << maxHigh << "\n";

    return 0;
}