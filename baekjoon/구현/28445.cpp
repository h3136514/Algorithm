#include <iostream>
#include <string>
#include <set>

using namespace std;
string a[4];
set<pair<string, string>> s;

// 알록달록 앵무새
int main(){
    cin >> a[0] >> a[1];
    cin >> a[2] >> a[3];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){            
            s.insert({a[i], a[j]});
        }
    }

    for(auto b : s){
        cout << b.first << " " << b.second << "\n";
    }

    return 0;
}