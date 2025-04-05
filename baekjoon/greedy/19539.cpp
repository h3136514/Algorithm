#include <iostream>

using namespace std;
int N, sum, num, cnt_2;
bool check;

// 사과나무
int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;

        sum += num;
        cnt_2 += num/2; //  2로 성장시킬 수 있는 개수
    }

    // 전체 합이 3의 배수이면서 2의 갯수가 물뿌리는 전체 횟수보다 많거나 같을 때
    if(sum % 3 == 0 && cnt_2 >= sum/3){
        check = true;
    }

    if(check)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}