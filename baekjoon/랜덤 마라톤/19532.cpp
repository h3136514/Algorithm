// 수학, 브루트포스
#include <iostream>

using namespace std;
int a, b, c, d, e, f, x, y;

// 수학은 비대면강의입니다
int main(){
    cin >> a >> b >> c >> d >> e >> f;
    for(int i = -999; i <= 999; i++){
        for(int j = -999; j <= 999; j++){
            if((a*i + b*j == c) && (d*i + e*j == f)){
                x = i;
                y = j;
                break;
            }
        }
    }

    cout << x << " " << y << "\n";

    return 0;
}