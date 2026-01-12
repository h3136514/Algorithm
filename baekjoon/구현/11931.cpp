#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> v;

// 수 정렬하기 4
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());
    for(int i = 0; i < N; i++){
        cout << v[i] << "\n";
    }

    return 0;
}