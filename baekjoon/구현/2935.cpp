#include<iostream>
#include<string>

using namespace std;
string a, b, c, result;

// 소음
int main(){
    cin >> a >> c >> b;
    if(c == "*"){
        result = a;
        for(int i = 0; i < b.size()-1; i++)
            result += "0";
    }else{
        if(a.size() == b.size()){
            result = a;
            result[0] = '2';
        }else if(a.size() < b.size()){
            result = b;
            result[b.size() - a.size()] ='1';
        }else{
            result = a;
            result[a.size() - b.size()] ='1';
        }
    }

    cout << result << "\n";

    return 0;
}