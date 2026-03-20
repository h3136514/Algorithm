#include <iostream>
#include <string>

using namespace std;
int N, M, x1, y1, x2, y2;
string result;

// 비숍 투어
int main(){
    cin >> N >> M;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    
    if (x1 == x2 && y1 == y2) {
        result = "YES";
    } else if (N == 1 || M == 1) {
        // 1xM 또는 Nx1 체스판: 비숍이 대각선 이동 불가
        result = "NO";
    } else if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        result = "YES";
    } else {
        result = "NO";
    }
    
    cout << result << "\n";
    return 0;
}