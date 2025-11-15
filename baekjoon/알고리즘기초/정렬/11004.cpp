#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int> v;

// K번째 수
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << v[K-1] << "\n";

    return 0;
}