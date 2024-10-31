#include <iostream>

using namespace std;
int N, CNT;

// 한수
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        bool check = true;
        if(i >= 100){   // 3자리 수 이상이면
            int target = i;
            int a = target%10;  // 일의 자리(이전 값)
            target /= 10;
            int b = target%10;  // 십의 자리(현재 값)
            int differ = a - b; // 두 개의 수의 차이

            while (target > 0)
            {   
                b = target%10;
                if(differ != a-b){  // 이전 값 - 현재 값이 다른 경우(한수 X)
                    check = false;
                    break;
                }
                a = target%10;
                target /= 10;
            }
        }

        if(check)
            CNT++;
    }

    cout << CNT << "\n";

    return 0;
}