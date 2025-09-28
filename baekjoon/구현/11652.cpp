// 해시 집합
#include <iostream>
#include <map>

using namespace std;
int N, maxLen;
long long a, result;
map<long long, int> m;

// 카드
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        m[a]++;
    }

    for(auto num : m){
        if(maxLen < num.second){
            maxLen = num.second;
            result = num.first;
        }
    }

    cout << result << "\n";

    return 0;
}