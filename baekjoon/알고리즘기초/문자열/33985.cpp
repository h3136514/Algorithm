#include <iostream>
#include <string>

using namespace std;
int N;
string s;

int main(){
    cin >> N;
    cin >> s;
    if(s[0] == 'B' || s[N-1] == 'A'){
        cout << "No\n";
    }else
        cout << "Yes\n";

    return 0;
}