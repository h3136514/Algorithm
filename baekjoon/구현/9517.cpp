#include <iostream>
#include <vector>

using namespace std;
int idx, M, num, sum;
vector<pair<int, char>> v;

// 아이 러브 크로아티아
int main(){
    cin >> idx;
    cin >> M;
    v.resize(M);
    for(int i = 0; i < M; i++){
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i < M; i++){
        sum += v[i].first;
        if(sum >= 210)
            break;
        if(v[i].second == 'T')
            idx = (idx == 8) ? 1 : idx + 1;
    }

    cout << idx << "\n";

    return 0;
}