#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, M, num, ago = 0, startIdx, endIdx;
string name;
vector<pair<string, pair<int, int>>> v;

// IF문 좀 대신 써줘
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> name >> num;
        if(i != 0){
            if(v[v.size()-1].second.second == num)
                continue;
        }
        v.push_back({name, {ago, num}});
        ago = num + 1;
    }

    for(int i = 0; i < M; i++){
        cin >> num;
        
        startIdx = 0;
        endIdx = v.size()-1;

        while(startIdx <= endIdx){
            int mid = (startIdx + endIdx) / 2;
            
            int sv = v[mid].second.first;
            int ev = v[mid].second.second;

            if(sv <= num && num <= ev){
                cout << v[mid].first << "\n";
                break;
            }

            if(num < sv){
                endIdx = mid - 1;
            }else{
                startIdx = mid + 1;
            }
            
        }
    }

    return 0;
}