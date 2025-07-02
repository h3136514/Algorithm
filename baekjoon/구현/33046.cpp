#include <iostream>

using namespace std;
int A, B, C, D, answer;

// Alea Iacta Est
int main(){
    cin >> A >> B;
    cin >> C >> D;

    answer = ((A + B) % 4 == 0) ? 4 : ((A + B) % 4);

    answer = ((answer + C + D-1) % 4 == 0) ? 4 : (answer + C + D-1) % 4;

    cout << answer << "\n";

    return 0;
}