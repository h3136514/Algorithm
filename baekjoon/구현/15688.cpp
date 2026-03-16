#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> v;

// 수 정렬하기 5 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        cout << v[i] << "\n";
    }

    return 0;
}