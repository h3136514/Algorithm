#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int N, board[9][9], stoneX, stoneY, kingX, kingY;
int offer_X[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int offer_Y[8] = {0, 0, -1, 1, 1, 1, -1, -1};
string a, b, c;
unordered_map<string, int> moves;

bool check(int x, int y){
    return x >= 1 && x < 9 && y >= 1 && y < 9;
}

// 킹
int main(){
    moves["R"] = 0, moves["L"] = 1, moves["B"] = 2, moves["T"] = 3, moves["RT"] = 4, moves["LT"] = 5, moves["RB"] = 6, moves["LB"] = 7;
    cin >> a >> b >> N;

    kingX = int(a[0]) -64;
    kingY = a[1] -'0';
    stoneX = int(b[0]) -64;
    stoneY = b[1] - '0';

    while(N--){
        cin >> c;
        int x = kingX + offer_X[moves[c]];
        int y = kingY + offer_Y[moves[c]];
       
        if(check(x, y)){
            if(stoneX == x && stoneY == y){
                int ix = stoneX + offer_X[moves[c]];
                int iy = stoneY + offer_Y[moves[c]];
                if(!check(ix, iy))
                    continue;
                
                stoneX = ix;
                stoneY = iy;
            }

            kingX = x;
            kingY = y; 
        }
    }

    cout << char(kingX + 64) << kingY << "\n";
    cout << char(stoneX + 64) << stoneY << "\n";

    return 0;
}