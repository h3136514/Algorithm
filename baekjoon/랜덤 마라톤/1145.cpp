// 브루트포스
#include <iostream>

using namespace std;
int num[5];

// 적어도 대부분의 배수
int main(){
    for(int i = 0; i < 5; i++)
        cin >> num[i];

    for(int i = 3; i <= 1000000; i++){
        int cnt = 0;
        for(int j = 0; j < 5; j++){
            if(i%num[j] == 0)
                cnt++;
        }
        if(cnt >= 3){
            cout << i << "\n";
            break;
        }
    }

    return 0;
}