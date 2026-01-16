#include <iostream>
#include <string>
#include <map>

using namespace std;
string s, tmp;
map<string, bool> m;

// 피카츄
int main(){
    m["pi"] = true, m["ka"] = true, m["chu"] = true;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        tmp += s[i];
        if(m.find(tmp) != m.end()){
            tmp = "";
        }
    }
    
    if(tmp == "")
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}