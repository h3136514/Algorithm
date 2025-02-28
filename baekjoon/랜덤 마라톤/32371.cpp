// 구현, 부루트포스
#include <iostream>
#include <unordered_map>

using namespace std;
int x, y, lowX = 11, lowY = 11;
char c, keyboard[4][10];
unordered_map<char, pair<int, int>> m;

// 샷건
int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            cin >> c;
            keyboard[i][j] = c;
            m[c] = {i, j};
        }
    }

    for(int j = 0; j < 9; j++){
        cin >> c;
        x = m[c].second;
        y = m[c].first;
        
        lowX = min(lowX, x);
        lowY = min(lowY, y);
    }

    cout << keyboard[lowY+1][lowX+1] << "\n";

    return 0;
}