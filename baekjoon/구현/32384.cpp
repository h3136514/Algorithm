#include <iostream>
#include <string>

using namespace std;
int N;
string s = "LoveisKoreaUniversity";

// 사랑은 고려대입니다
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cout << s;
        if(i != N-1)
            cout << " ";
        else
            cout << "\n";
    }

    return 0;
}