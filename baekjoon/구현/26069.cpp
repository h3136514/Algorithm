#include <iostream>
#include <string>
#include <map>

using namespace std;
int N;
map<string, bool> m;
string A, B, target = "ChongChong";

// 붙임성 좋은 총총이
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A >> B;
        if(m.size() == 0){
            if(A == target || B == target){
                m[B] = true;
                m[A] = true;
            }
        }else{
            bool checkA = m.find(A) != m.end();
            bool checkB = m.find(B) != m.end();
            if(checkA && checkB){
                continue;
            }else if(checkA){
                m[B] = true;
            }else if(checkB){
                m[A] = true;
            }
        }
    }

    cout << m.size() << "\n";
    return 0;
}