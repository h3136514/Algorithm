#include <iostream>
#include <string>
#include <map>

using namespace std;
int N, CNT;
string s;
map<string, bool> m;

// 인사성 밝은 곰곰이
int main(){
    cin >> N;
    while(N--){
        cin >> s;
        if(s == "ENTER"){
            m.clear();
            continue;
        }
        
        if(m.find(s) == m.end()){
            m[s] = true;
            CNT++;
        }
    }

    cout << CNT << "\n";

    return 0;
}