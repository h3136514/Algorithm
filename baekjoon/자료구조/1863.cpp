// 스택
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int N, x, y, CNT;
vector<pair<int, int>> v;
stack<int> s;

// 스카이라인 쉬운거
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        if(!s.empty() && s.top() > v[i].second){
            while(!s.empty() && s.top() > v[i].second){
                s.pop();
                CNT++;
            }
            if(s.empty() || s.top() != v[i].second)
                s.push(v[i].second);
        }else
            s.push(v[i].second);
    }

    while(!s.empty() && s.top() != 0){
        CNT++;
        s.pop();
    }

    cout << CNT << "\n";

    return 0;
}
