#include <iostream>

using namespace std;
int N, cnt, num, pc[101];

// 피시방 알바
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(pc[num]){
            cnt++;
            continue;
        }
        pc[num] = 1;
    }

    cout << cnt << "\n";

    return 0;
}