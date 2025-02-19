// 수학, 사칙연산
#include <iostream>

using namespace std;
int N, M;

// 초코바
int main(){
    cin >> N >> M;
    if(N*100 >= M)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}