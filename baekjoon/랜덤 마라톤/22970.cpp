//구현, 브루트포스
#include <iostream>

using namespace std;
int N, num[5001], cnt = 1, maxCNT = 1;
bool incr, decr;

// 문제 재탕
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    for(int i = 1; i < N; i++){
        if(num[i-1] < num[i]){
            if(decr){ 
                incr = true;
                decr = false;
                maxCNT = max(maxCNT, cnt);
                cnt = 2;
            }else{
                cnt++;
            }
        }else if(num[i-1] > num[i]){
            decr = true;
            cnt++;
        }else{
            maxCNT = max(maxCNT, cnt);
            incr = false;
            decr = false;
            cnt = 1;
        }
        maxCNT = max(maxCNT, cnt);
    }

    cout << maxCNT << "\n";

    return 0;
}