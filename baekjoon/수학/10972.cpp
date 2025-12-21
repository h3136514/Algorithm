// 조합론
// https://www.acmicpc.net/problem/10972
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<int> v;

// 다음 순열
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    if(next_permutation(v.begin(), v.end())){
        for(int i = 0; i < N; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }else
        cout << "-1\n";

    return 0;
}