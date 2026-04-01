#include <iostream>
#include <string>

using namespace std;
int num, target, lo, hi;
string s1, s2;

void init(){
    lo = -1, hi = 11;
}

// 숫자 맞추기
int main(){
    init();

    while(true){
        cin >> num;
        if(num == 0)
            break;

        cin >> s1 >> s2;
        if(s2 == "high"){
            hi = min(hi, num);
        }else if(s2 == "low"){
            lo = max(lo, num);
        }else{
            if(num > lo && num < hi)
                cout << "Stan may be honest\n";
            else
                cout << "Stan is dishonest\n";
    
            init();
        }



    }

    return 0;
}