#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
int N;
string s, fileName;
vector<string> v;
map<string, int> m;

// 파일 정리
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> fileName;
        stringstream ss(fileName);

        while(getline(ss, s, '.')){
            v.push_back(s);
        }

        m[v[1]]++;
        v.clear();
    }

    for(auto ext : m){
        cout << ext.first << " " << ext.second << "\n";
    }

    return 0;
}
