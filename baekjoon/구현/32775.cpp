#include <iostream>

using namespace std;
int S, F;

// 가희와 4시간의 벽 1
int main(){
    cin >> S;
    cin >> F;

    if(S > F)
        cout << "flight\n";
    else
        cout << "high speed rail\n";

    return 0;
}