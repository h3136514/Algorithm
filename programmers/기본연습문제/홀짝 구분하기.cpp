#include <iostream>
#include <string>

using namespace std;
string s;

int main(void) {
    int n;
    cin >> n;
    s = (n % 2 == 0) ? "even" : "odd";
    
    cout << n << " is " << s << "\n"; 
    
    return 0;
}