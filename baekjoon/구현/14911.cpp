#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;
vector<int> v;
map<pair<int, int>, int> m;
vector<pair<int, int>> result;
string s, target;
int targetNum;

// 궁합 쌍 찾기
int main(){
    getline(cin, s);
    getline(cin, target);

    targetNum = stoi(target);
    string num;
    stringstream ss(s);
    while(getline(ss, num, ' ')){
        int numInt = stoi(num);
        v.push_back(numInt);
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size()-1; i++){
        for(int j = i+1; j < v.size(); j++){
            if(v[i] + v[j] > targetNum)
                break;
            if((v[i] + v[j] == targetNum)&& (m.find({v[i], v[j]}) == m.end())){
                m[{v[i], v[j]}] = 1;
                result.push_back({v[i], v[j]});
            }
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i].first << " " << result[i].second << "\n";
    }
    cout << result.size() << "\n";

    return 0;
}