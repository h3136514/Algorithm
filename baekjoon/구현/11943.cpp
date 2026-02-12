#include <iostream>

using namespace std;
int A, B, C, D;

// 파일 옮기기
int main(){
    cin >> A >> B;
    cin >> C >> D;

    cout << min((A+D), (C+B)) << "\n";

    return 0;
}