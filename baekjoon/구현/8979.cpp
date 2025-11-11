#include <iostream>
#include <queue>

using namespace std;
int N, K, cnt = 1, grade = 0, agoGrade = 1, a, b, c, num;
priority_queue<pair<pair<int, int>, pair<int, int>>> q;

// 올림픽
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> num >> a >> b >> c;
        q.push({{a, b}, {c, num}});
    }

    a = -1;
    while(!q.empty()){
        int numi = q.top().second.second;
        int ai = q.top().first.first;
        int bi = q.top().first.second;
        int ci = q.top().second.first;
        q.pop();

        if(a == ai && b == bi && c == ci){
            if(numi == K){
                if(grade == 0){
                    grade = 1;
                }
                cout << grade << "\n";
                return 0;
            }
            cnt++;
            continue;
        }

        grade += cnt;
        cnt = 1;

        if(numi == K){
            cout << grade << "\n";
            return 0;
        }
        
        a = ai;
        b = bi;
        c = ci;
    }

    return 0;
}