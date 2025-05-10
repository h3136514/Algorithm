// 자료구조
#include <iostream>
#include <queue>

using namespace std;
int N, x;
priority_queue<pair<int,int>> q;

// 절댓값 힙
int main(){
    cin >> N;
    while (N--){
       cin >> x;
       if(x != 0){
            q.push({-abs(x), -x});
            continue;
       }

        if(q.empty())
            cout <<"0\n";
        else{
            cout << -q.top().second << "\n";
            q.pop();
        }
    }
    
    return 0;
}