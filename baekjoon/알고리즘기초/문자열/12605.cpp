#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int N;
string s;
vector<string> v;

// 단어순서 뒤집기
int main(){
    cin >> N;
    cin.ignore();
    for(int i = 1; i <= N; i++){
        getline(cin, s);

        stringstream ss(s);
        string word = "";
       
        while(getline(ss, word, ' ')){
            v.push_back(word);
        }

        cout << "Case #" << i <<":";
        for(int j = v.size()-1; j >= 0; j--){
            cout << " " << v[j];
        }
        cout << "\n";
    
        v.clear();
    }

    return 0;
}