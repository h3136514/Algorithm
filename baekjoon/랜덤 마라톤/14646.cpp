// 시물레이션, 구현
#include <iostream>

using namespace std;
int N, CNT, maxCNT, a, num[100001];

// 욱제는 결정장애야!!
int main(){
    cin >> N;
    for(int i = 0; i < N*2; i++){
        cin >> a;
        if(!num[a]){
            num[a] = 1;
            CNT++;
            
            maxCNT = max(maxCNT, CNT);
        }else{
            num[a] = 0;
            CNT--;
        }
    }

    cout << maxCNT << "\n";

    return 0;
}