// 정렬
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
int N, num, CNT;
vector<int> v;
priority_queue<int> q;
unordered_map<int, int> m;

// 좌표 압축
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
        q.push(-num);
    }

    while(!q.empty()){
        num = -q.top();
        q.pop();

        if(m.find(num) == m.end()){
            m[num] = ++CNT;
        }
    }

    for(int i = 0; i < N; i++){
        num = v[i];

        cout << m[num]-1 << " ";
    }
    cout << "\n";

    return 0;
}
