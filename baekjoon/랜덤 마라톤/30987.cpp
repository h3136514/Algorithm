// 수학, 미적분학학
#include <iostream>

using namespace std;
int startX, endX, a, b, c, d, e;

// 하루 피부과
int main(){
    cin >> startX >> endX;
    cin >> a >> b >> c >> d >> e;
    int x1 = c-e;
    int x2 = (b-d)/2;
    int x3 = a/3;

    int rager =(x3*endX*endX*endX + x2*endX*endX + x1*endX) - (x3*startX*startX*startX + x2*startX*startX + x1*startX);
    cout << rager << "\n";

    return 0;
}
