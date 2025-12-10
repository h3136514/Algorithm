#include <iostream>
#include <vector>

using namespace std;
int N, L, result;
vector<int> v;

// 최대 상승
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    L = v[0];
    for(int i = 1; i < N; i++){
        if(v[i] > L){
            result = max(result, v[i] - L);
        }else{
            L = v[i];
        }
    }

    cout << result << "\n";

    return 0;
}
