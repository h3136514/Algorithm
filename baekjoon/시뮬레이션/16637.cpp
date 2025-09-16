#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;
int N, CNT, result = numeric_limits<int>::min();
string s;
vector<pair<pair<bool,bool>, pair<long long, long long>>> v;
vector<char> buho;

long long cal(char c, long long a, long long b){
    if(c == '+')
        return a+b;
    else if(c == '-')
        return a-b;
    else
        return a*b;
}

void backtrack(vector<pair<pair<bool,bool>, pair<long long, long long>>> tmp, vector<char> buhoTmp, int cnt){
    if(cnt == 1){
        result = max(result, int(cal(buhoTmp[0], tmp[0].second.first, tmp[0].second.second)));

        return;
    }

    for(int i = 0; i < cnt; i++){
        vector<pair<pair<bool,bool>, pair<long long, long long>>> tmp2 = tmp;
        vector<char> buhoTmp2 = buhoTmp;
        long long num = cal(buhoTmp2[i], tmp2[i].second.first, tmp2[i].second.second);
        bool checkL = tmp2[i].first.first;
        bool checkR = tmp2[i].first.second;
        tmp2.erase(tmp2.begin() + i);
        buhoTmp2.erase(buhoTmp2.begin() + i);

        if(i == 0){ // 괄호X 그냥 계산
            tmp2[0].second.first = num;
        
            backtrack(tmp2, buhoTmp2, cnt-1);
        }else if(i == cnt-1 && !checkL && !checkR){
            tmp2[cnt-2].second.second = num;
            tmp2[cnt-2].first.second = true;    // 괄호 사용

            backtrack(tmp2, buhoTmp2, cnt-1);
        }else if(!checkL && !checkR){
            tmp2[i-1].first.second = true; // 괄호 사용
            tmp2[i-1].second.second = num;
            tmp2[i].first.first = true; // 괄호 사용
            tmp2[i].second.first = num;

            backtrack(tmp2, buhoTmp2, cnt-1);
        }
    }
}

// 괄호 추가하기
int main(){
    cin >> N;
    cin >> s;
    CNT = N/2;

    if(N == 1){
        cout << s << "\n";
        return 0;
    }

    for(int i = 1; i < N; i+= 2){
       buho.push_back(s[i]); 
       v.push_back({{false,false}, {s[i-1] -'0', s[i+1] -'0'}});     
    }

    backtrack(v, buho, CNT);

    cout << result << "\n";

    return 0;
}