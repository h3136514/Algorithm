#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, num, W, K;
vector<int> v;

// 로프
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        K = max(K, v[i]*(N-i));
    }

    cout << K << "\n";

    return 0;
}