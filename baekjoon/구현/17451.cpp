
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<long long> v;

// 평행 우주
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // 뒤에서부터 계산
    for (int i = n-2; i >= 0; i--) {
        if(v[i] < v[i+1]){
            long long k = (v[i+1] - 1)/v[i] + 1;
            v[i] *= k;
        }
    }
    
    cout << v[0] << '\n';
    
    return 0;
}