#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int N;
string s;
vector<string> v;

// 단어 뒤집기
int main(){
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin, s, '\n');
        v.push_back(s);
    }

    for(int i = 0; i < N; i++){
        stringstream ss(v[i]);
        string word = "";

        while(getline(ss, word, ' ')){
            for(int j = word.size() -1; j >= 0; j--){
                cout << word[j];
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}