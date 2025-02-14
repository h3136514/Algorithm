// 구현, 시뮬레이션, 맵
#include <iostream>
#include <string>
#include <map>

using namespace std;
map<pair<int, int>, int> m;
int N, x, y, CNT, a, b;
string command;

// Footprint
int main(){
    cin >> N;
    cin >> command;
    m[{0, 0}] = 1;
    CNT++;

    for(int i = 0; i < N; i++){
        if(command[i] == 'S')
            y++;
        else if(command[i] == 'N')
            y--;
        else if(command[i] == 'W')
            x--;
        else
            x++;
        
        if(m.find({x, y}) == m.end()){
            m[{x, y}] = 1;
            CNT++;
        }
    }
    
    cout << CNT << "\n";

    return 0;
}