// 해시, 소수점(오차범위)
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;
int N, scoreN, scoreR, memori, runt, lang, codeL, faliSum;
string user;
set<string> accesSum;
unordered_map <string, int> m;

// 정답 비율 계산하기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> scoreN >> user >> scoreR >> memori >> runt >> lang >> codeL;
        if(user == "megalusion")
            continue;

        // 문제를 맞았으면
        if(accesSum.find(user) != accesSum.end())
            continue;

        if(scoreR == 4){
            accesSum.insert(user);
            faliSum +=  m[user];
        }else
            m[user]++;
    }

    cout << fixed;
    cout.precision(10); // 해당 오차범위까지 출력(소수점 밑 출력 범위)

    if((accesSum.size() + faliSum) == 0)
        cout << "0\n";
    else{
        double answer = (static_cast<double> (accesSum.size()) / (accesSum.size() + faliSum)) * 100;
        cout << answer << "\n";
    }

    return 0;
}