// 구현
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
int N, M, CNT;
char c[200];
string str;
vector<pair<string, int>> v;
set<int> s;

// 악질 검거
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> c[j];
        }
        cin >> str;
        CNT = 0;
        int cnt = 0;
        for(int j = 0; j < M; j++){
            if(c[j] =='.'){
                cnt++;
                CNT = max(CNT, cnt);
            }else
                cnt = 0;
        }

        v.push_back({str, CNT});
        s.insert(CNT);
    }

    cout << s.size() << "\n";

    for(int i = 0; i < v.size(); i++)
        cout << v[i].second  << " " << v[i].first << "\n";

    return 0;
}