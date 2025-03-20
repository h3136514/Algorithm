// 그리디, 정렬
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
long long N, D, X, num, CNT;
vector<int> monster;
priority_queue<int>equipment;

// 돌아온 똥게임
int main(){
    cin >> N >> D;
    for(int i = 0; i < N; i++){
        cin >> X >> num;
        if(X == 1)
            monster.push_back(num);
        else
            equipment.push(-num);
    }

    sort(monster.begin(), monster.end());

    for(int i = 0; i < monster.size(); i++){
        int damage = monster[i];

        if(D > damage){
            D += damage;
            CNT++;
            continue;
        }

        // 몬스터를 없앨 수 있는 최소한의 장비 조합을 탐색 
        while(!equipment.empty() && D <= damage){
            for(int j = 0; j < equipment.size(); j++){
                int add = -equipment.top();
                equipment.pop();

                if(D*add > damage){
                    D *= add;
                    CNT +=2;
                    break;
                }

                equipment.push(-add);
            }

            // 제일 작은 장비를 곱함
            if(D <= damage){
                D *= -equipment.top();
                equipment.pop();
                CNT++;
            }
        }
    }

    cout << CNT + equipment.size() << "\n";

    return 0;
}
