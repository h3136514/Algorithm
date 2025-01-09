// 구현
#include <iostream>
#include <string>

using namespace std;
string s, r;

// 코드마스터 2023
int main(){
    cin >> s;
    if(s == "SONGDO")
        r = "HIGHSCHOOL";
    else if(s == "CODE")
        r =  "MASTER";
    else if(s == "2023")
        r = "0611";
    else
        r = "CONTEST";

    
    cout << r << "\n";

    return 0;
}