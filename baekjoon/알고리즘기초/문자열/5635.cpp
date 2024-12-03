#include <iostream>
#include <string>
#include <queue>

using namespace std;
int N, year, month, day;
string name;
priority_queue<pair<pair<int, int>, pair<int, string>>> q;

// 생일
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> name >> day >> month >> year;
        q.push({{year, month},{day, name}});
    }

    cout << q.top().second.second << "\n";
    
    while(q.size() != 1)
        q.pop();

    cout << q.top().second.second << "\n";

    return 0;
}