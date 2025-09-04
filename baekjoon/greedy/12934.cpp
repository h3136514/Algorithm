#include <iostream>

using namespace std;
long long X, Y, sum, num, answer;

// 턴 게임
int main(){
    cin >> X >> Y;

    num = 1;
    while(sum <= X + Y){
        sum += num;

        if(sum > X + Y){
            cout << "-1\n";
            return 0;
        }

        if(sum == X + Y){
            break;
        }

        num++;
    }

    while(X > 0){
        answer++;

        if(X >= num){
            X -= num;
            num--;
        }else
            break;
    }

    cout << answer << "\n";

    return 0;
}