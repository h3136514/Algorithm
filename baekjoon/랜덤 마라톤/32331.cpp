#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, X, Y, h, num, sub, cnt, result;
string schoolNum;
vector<int> v;
vector<pair<int, int>> ranking;

int main(){
    cin >> N >> M >> X >> Y;
    cin >> schoolNum >> h;
    // v.push_back({h+Y, schoolNum});

    for(int i = 0; i < N-1; i++){
        cin >> schoolNum >> num;
       
        if(schoolNum.substr(0,4) != "2024")
            continue;
        
        int score = (Y - (X-num)) < 0 ? 0 : (Y - (X-num));
        v.push_back(num + score);
    }

    sort(v.rbegin(), v.rend());

    // 순위 매칭하기
    if(v.size() > 0){
        num = v[0];
        cnt = 1;
        sub = 1;
        ranking.push_back({cnt, num});
        
        for(int i = 1; i < v.size(); i++){
            if(num == v[i]){
                sub++;
                ranking.push_back({cnt, num});
                continue;
            }
                    
            cnt += sub;
            sub = 1;
            num = v[i];
            ranking.push_back({cnt, num});
        }
        // 마지막 추가 등수 확인(김한양이 기말고사에서 0점을 받았을 때 등수를 계산하기 위해)
        cnt += sub;
    }

    if(cnt <= M || ranking.size() < M){ // 목표 등수가 널널할때
        result = 0;
    }else{
        num = 0;
        for(int i = 0; i < ranking.size(); i++){

            // 목표 등수를 처음 지날 때
            if(ranking[i].first >= M){
                if(ranking[i].first == M)   // 목표 등수일때
                    num = ranking[i].second;
                
                result = num;
                break;
            }
            num = ranking[i].second;
        }

        // 마지막 인원의 등수가 목표등수 일 때
        if(ranking[ranking.size()-1].first < M)
            result = ranking[ranking.size()-1].second;
    }

    if(h+Y >= result ){
        cout << "YES\n";
        if(h >= result)
            cout << "0\n";
        else
            cout << result-h << "\n";
    }else
        cout << "NO\n";

    return 0;
}