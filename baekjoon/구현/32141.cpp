#include <iostream>
#include <vector>

using namespace std;
int N, H, cnt;
vector<int> v;

// 카드 게임 (Easy)
int main(){
    cin >> N >> H;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    for(int i = 0; i < N; i++){
        cnt++;
        H -= v[i];
        if(H <= 0){
            break;
        }
    }

    if(cnt == N && H > 0)
        cnt = -1;

    cout << cnt << "\n";

    return 0;
}