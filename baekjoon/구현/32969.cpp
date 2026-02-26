#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
string s, result;
bool checkD, checkP;
vector<string> D = {"social", "history", "language", "literacy"}, P = {"bigdata", "public", "society"};

// 학술대회 참가신청
int main(){

    getline(cin, s);
    stringstream ss(s);

    for(int i = 0; i < D.size(); i++){
        if(s.find(D[i]) != string::npos){
            checkD = true;
            break;
        }
    }
    
    for(int i = 0; i < P.size(); i++){
        if(s.find(P[i]) != string::npos){
            checkP = true;
            break;
        }
    }

    result = (checkD) ? "digital humanities" : "public bigdata";
    
    cout << result << "\n";

    return 0;
}