// 우선순위 큐, 집합과 맵
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
int N, M, P, L, problem[100001][101];  // 문제가 존재하는지 유무
string s;
priority_queue<pair<int, int>> hard, easy;
unordered_map<int, int> m;  // 현재 해당 문제의 난이도

// 문제 추천 시스템 Version 1
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> P >> L;
        problem[P][L] = 1;

        m[P] = L;
        hard.push({L, P});
        easy.push({-L, -P});
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> s >> P;
        if(s == "add"){
            cin >> L;
            problem[P][L] = 1;

            m[P] = L;
            hard.push({L, P});
            easy.push({-L, -P});
        }else if(s == "recommend"){
            if(P == 1){
                while(!hard.empty()){
                    int a = hard.top().first;
                    int b = hard.top().second;
                    
                    if(!problem[b][a]){
                        hard.pop();
                        continue;
                    }
                    cout << b << "\n";
                    break;
                }
            }else{
                while(!easy.empty()){
                    int a = -easy.top().first;
                    int b = -easy.top().second;
                    
                    if(!problem[b][a]){
                        easy.pop();
                        continue;
                    }
                    cout << b << "\n";
                    break;
                }
            }
        }else{  // solved
            problem[P][m[P]] = 0;
            m.erase(P);
        }
    }

    return 0;
}
