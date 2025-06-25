#include <iostream>
#include <string>

using namespace std;
int N, A, B;
string answer;

// 정보섬의 대중교통
int main(){
    cin >> N >> A >> B;
    if(A > B)
        answer = "Subway";
    else if(A < B)
        answer = "Bus";
    else
        answer = "Anything";

    cout << answer << "\n";

    return 0;
}