// 집합과 맵
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int N;
string name, behave;
map<string, bool> m;
vector<string> v;

// 회사에 있는 사람
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> name >> behave;
        if(behave == "enter"){
            m[name] = true;
        }else{
            m.erase(name);
        }
    }

    for(auto a : m){
        v.push_back(a.first);
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}