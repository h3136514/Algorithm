#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int num[3];
string s;
vector<string> v;

// 모든 세 단어로 나누는 경우
void backtrack(int round, int cnt){
    if(round == 3 && cnt == 0){
        string a = s.substr(0, num[0]);
        string b = s.substr(num[0], num[1]);
        string c = s.substr(num[0]+num[1], num[2]);
        reverse(a.begin(), a.end()), reverse(b.begin(), b.end()), reverse(c.begin(), c.end());

        v.push_back(a+b+c);
        return;
    }

    if(round >= 3 || cnt == 0)
        return;
    
    for(int i = 1; i <= cnt; i++){
        num[round] = i;
        backtrack(round+1, cnt-i);
    }

}

// 단어 나누기
int main(){
    cin >> s;

    backtrack(0, s.size());

    sort(v.begin(), v.end());

    cout << v[0] << "\n";

    return 0;
}