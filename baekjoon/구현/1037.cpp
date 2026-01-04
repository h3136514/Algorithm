#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, target;
vector<int> v;

// 약수
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    target = v[0] * v[N-1];

    cout << target << "\n";

    return 0;
}
