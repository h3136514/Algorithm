#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, string> m;
string s;

// 특별한 학교 이름 
int main(){
    m["NLCS"] = "North London Collegiate School", m["BHA"] = "Branksome Hall Asia", m["KIS"] = "Korea International School", m["SJA"] = "St. Johnsbury Academy";
    cin >> s;
    cout << m[s] << "\n";
    
    return 0;
}
