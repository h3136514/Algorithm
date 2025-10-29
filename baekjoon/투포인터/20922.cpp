#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N, K, result=1;
vector<int> v;
map<int, int> m;

// 겹치는 건 싫어
int main(){
    cin >> N >> K;
    v.resize(N+1);
    for(int i = 1; i <= N; i++)
        cin >> v[i];
    
    int s = 1, e = 1;
    m[v[1]]++;
    while(s <= N && e <= N && s <= e){
        int len = e-s + 1;

        if(m[v[e]] > K || m[v[s]] > K){
            m[v[s]]--;
            s++;
        }else{
            result = max(result, len);
            e++;
            m[v[e]]++;
        }
    }

    cout << result << "\n";

    return 0;
}
