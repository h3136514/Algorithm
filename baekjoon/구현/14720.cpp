#include <iostream>
#include <vector>

using namespace std;
int N, target = 0, cnt;
vector<int> v;

// 우유 축제
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    for(int i = 0; i < N; i++){
        if(target == v[i]){
            cnt++;
        }else{
            continue;
        }
        
        target = (target == 2) ? 0 : target + 1;
    }

    cout << cnt << "\n";

    return 0;
}
