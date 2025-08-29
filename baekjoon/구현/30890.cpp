#include <iostream>
#include <map>

using namespace std;
int X, Y;
map<double, int> m;

// 드럼
int main(){
    cin >> X >> Y;
    for(int i = 1; i <= X; i++){
        double cal = i/(double)X;
        m[cal] = 1;
    }

    for(int i = 1; i <= Y; i++){
        double cal = i/(double)Y;
        if(m.find(cal)== m.end())
            m[cal] = 2;
        else
            m[cal] = 3;
    }

    for(auto a : m){
        cout << a.second;
    }

    return 0;
}