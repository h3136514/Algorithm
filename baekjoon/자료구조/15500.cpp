// 스택
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int N, a, num[124];
stack<int> s[2];
vector<pair<int, int>> v;

//이상한 하노이 탑
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        s[0].push(a);
    }

    for(int i = N; i > 0; i--){
        int targetIdx = num[i];
        int next = (targetIdx == 0) ? 1 : 0;

        while(!s[targetIdx].empty()){
            int target = s[targetIdx].top();
            s[targetIdx].pop();

            if(target == i){
                v.push_back({targetIdx+1, 3});
                break;
            }

            v.push_back({targetIdx+1, next+1});
            s[next].push(target);
            num[target] = next;
        }
    }

    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}