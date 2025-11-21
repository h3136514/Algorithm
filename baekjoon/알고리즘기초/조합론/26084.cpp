#include <iostream>
#include <string>
#include <map>

using namespace std;
string target, s;
int N;
long long answer = 1;
map<char, int> a, b;

long long combine(int n, int k){
    if(k < 0 || k > n) return 0;
    if(k == 0 || k == n) return 1;

    long long result = 1;
    for(int i = 1; i <= k; i++){
        result = result*(n-k+i)/i;
    }

    return result;
}

// DPS
int main(){
    cin >> target;
    for(int i = 0; i < 3; i++){
        a[target[i]]++;
    }

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(a.find(s[0]) != a.end()){
            b[s[0]]++;
        }
    }

    for(auto alp : a){
        char c = alp.first;
        answer *= combine(b[c], alp.second);
    }

    cout << answer << "\n";

    return 0;
}