#include <iostream>
#include <queue>

#define MAX 987654321
using namespace std;
int a, b, R, CNT, num[1000][1000];
queue<pair<int, pair<int, int>>> q;

void bfs(){
    q.push({0, {a, b}});
    num[b][a] = 0;

    while(!q.empty()){
        int currentCnt = q.front().first;
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        q.pop();

        if(num[currentY][currentX]){
            CNT = currentCnt;
            break;
        }

        num[currentY][currentX] = 1;
        int sum = currentX + currentY + 2;
        if(sum < R){
            q.push({currentCnt + 1, {currentX + 1, currentY + 1}});
        }else{
            q.push({currentCnt + 1, {currentX/2, currentY/2}});
        }
    }

}

// 트릭 플라워
int main(){
    cin >> a >> b;
    cin >> R;
    bfs();

    cout << CNT << "\n";

    return 0;
}