#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, idx;
vector<int> v;

// 안테나
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    idx = (N%2 == 0) ? N/2 - 1: N/2;

    cout << v[idx] <<"\n";

    return 0;
}