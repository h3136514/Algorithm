#include <iostream>
#include <vector>

using namespace std;
int x, y, target, num[13];
vector<int> V[13];

void init(){
    num[1] = 0, num[2] = 0, num[3] = 0;
}

// 스피카
int main(){
    for(int i = 0; i < 12; i++){
        cin >> x >> y;

        V[x].push_back(y);
        V[y].push_back(x);
    }

    for(int i = 1; i <= 12; i++){
        if(V[i].size() != 3)  // 해당 정점의 차수가 3이어야함
            continue;
        
        for(int j = 0; j < 3; j++){
            x = V[i][j];
            num[V[x].size()] = 1;
        }

        if(num[1] && num[2] && num[3]){ // 인접한 정점들의 차수가 1, 2, 3인 경우
            target = i;
            break;
        }

        init();
    }

    cout << target << "\n";

    return 0;
}
