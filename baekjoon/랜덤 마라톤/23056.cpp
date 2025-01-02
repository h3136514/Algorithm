// 구현, 정렬
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, M, num;
string name;
vector<string> v[11];

// 길이가 짧은 것부터, 길이가 같다면 사전 순
bool compare(string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }

    return a.size() < b.size();
}

// 참가자 명단
int main(){
    cin >> N >> M;
    while(true){
        cin >> num >> name;
        if(num == 0)
            break;
        
        if(v[num].size() == M)
            continue;

        v[num].push_back(name);
    }

    for(int i = 1; i <= N; i+=2){
        if(v[i].size() == 0)
            continue;
        
        sort(v[i].begin(), v[i].end(), compare);

        for(int j = 0; j < v[i].size(); j++){
            cout << i << " " << v[i][j] << "\n";
        }
    }

    for(int i = 2; i <= N; i+=2){
        if(v[i].size() == 0)
            continue;
        
        sort(v[i].begin(), v[i].end(), compare);

        for(int j = 0; j < v[i].size(); j++){
            cout << i << " " << v[i][j] << "\n";
        }
    }

    return 0;
}