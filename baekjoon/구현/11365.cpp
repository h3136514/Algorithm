#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> v;
string s;

// !밀비 급일
int main(){
    while(true){
        getline(cin, s);
        if(s =="END")
            break;
        v.push_back(s);
    }

    for(int i = 0; i < v.size(); i++){
        for(int j = v[i].size()-1; j >= 0; j--){
            cout << v[i][j];
        }
        cout << "\n";
    }

    return 0;
}