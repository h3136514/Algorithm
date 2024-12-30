// 구현, 그리디
#include <iostream>

using namespace std;
int N, num, sum, maxNum;
// 욱제는 효도쟁이야!!
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        sum += num;
        maxNum = max(maxNum, num);
    }

    sum -= maxNum;
    cout << sum << "\n";

    return 0;
}