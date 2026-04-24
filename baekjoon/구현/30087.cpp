#include <iostream>
#include <map>
#include <string>

using namespace std;
int N;
string s;
map<string, string> m;

int main(){
    m["Algorithm"] = "204", m["DataAnalysis"] = "207", m["ArtificialIntelligence"] = "302", m["CyberSecurity"] = "B101" , m["Network"] = "303", m["Startup"] = "501", m["TestStrategy"] = "105";
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        cout << m[s] << "\n";
    }
    return 0;
}