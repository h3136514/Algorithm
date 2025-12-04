
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int N;
string target, s;
vector<pair<int, string>> v;

bool compare(pair<int, string> p1, pair<int, string> p2){
    // 확률이 다르면 확률이 높은 순
    if(p1.first != p2.first){
        return p1.first > p2.first;
    }
    // 확률이 같으면 사전순
    return p1.second < p2.second;
}

//  팀 이름 정하기
int main(){
    cin >> target;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> s;
        
        // L, O, V, E 개수 세기
        int L = 0, O = 0, V = 0, E = 0;
        
        // target에서 세기
        for(int j = 0; j < target.size(); j++){
            if(target[j] == 'L') L++;
            else if(target[j] == 'O') O++;
            else if(target[j] == 'V') V++;
            else if(target[j] == 'E') E++;
        }
        
        // 팀 이름에서 세기
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'L') L++;
            else if(s[j] == 'O') O++;
            else if(s[j] == 'V') V++;
            else if(s[j] == 'E') E++;
        }
        
        // 공식 적용
        int prob = ((L+O) * (L+V) * (L+E) * (O+V) * (O+E) * (V+E)) % 100;
        
        v.push_back({prob, s});
    }
    
    // 정렬
    sort(v.begin(), v.end(), compare);
    
    // 결과 출력
    cout << v[0].second << "\n";
    
    return 0;
}