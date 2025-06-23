#include <iostream>
#include <string>

using namespace std;
int N;
string S = "WelcomeToSMUPC";

// Welcome to SMUPC!
int main(){
    cin >> N;
    cout << S[(N-1) % 14] << "\n";

    return 0;
}