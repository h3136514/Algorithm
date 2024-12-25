// 자료구조, 정렬, 집합과 맵
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
int N, num, maxN;
unordered_map<int, int> m;
priority_queue<pair<int, pair<int, int>>> q;

// 눈사람
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num;
        m[num] = i;
    }

    for(int i = 1; i <= N; i++){
        cin >> num;
        q.push({m[num] - i,{-i, num}});
    }

    maxN = q.top().first;
    while(!q.empty()){
        if(maxN != q.top().first)
            break;
        
        cout << q.top().second.second << " ";
        q.pop();
    }

    return 0;
}