#include <iostream>

using namespace std;
float W, H, result;

// 삼각형
int main(){
    cin >> W >> H;
    result = (W*H)/2.0;

    cout << fixed; 
    cout.precision(1);
    cout << result << "\n";

    return 0;
}