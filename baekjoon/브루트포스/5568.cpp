#include <iostream>
#include <string>
#include <set>

using namespace std;
int N, K, maxNum, visitied[11];
string num[11];
set<string> s;

void backtrack(int cnt, string st){
    if(cnt == K){
        s.insert(st);

        return;
    }

    for(int i = 0; i < N; i++){
        if(!visitied[i]){
            visitied[i] = 1;
            backtrack(cnt+1, st + num[i]);
            visitied[i] = 0;
        }
    }
}

// 카드 놓기
int main(){
    cin >> N;
    cin >> K;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    backtrack(0, "");

    cout << s.size() << "\n";

    return 0;
}