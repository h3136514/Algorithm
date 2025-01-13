#include <iostream>
#include <string>

using namespace std;
int sum;
string str;

// 그릇 
int main(){
    cin >> str;
    sum += 10;
    for(int i = 1; i < str.size(); i++){
        if(str[i-1] == str[i])
            sum += 5;
        else
            sum += 10;
    }

    cout << sum << "\n";

    return 0;
}