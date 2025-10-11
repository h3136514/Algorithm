#include <iostream>
#include <string>

using namespace std;
string result;

int gettime(string t){
    int h = (t[0]-'0') * 10 + t[1]-'0';
    int m = (t[3]-'0') * 10 + t[4]-'0';
    int s = (t[6]-'0') * 10 + t[7]-'0';
    return h*3600+m*60+s;
}

string cal(int t){
    string ret, temp;
    temp = to_string(t%60);
    if(temp.length()==1)
        temp = '0'+temp;
    ret = ':'+temp;

    t /= 60;
    temp = to_string(t%60);
    if(temp.length()==1)
        temp = '0'+temp;
    ret = ':'+temp+ret;

    t /= 60;
    temp = to_string(t%60);
    if(temp.length()==1)
        temp = '0'+temp;
    ret = temp+ret;

    return ret;
}

// 24
int main(){
    string st, en; cin >> st >> en;
    int st_ = gettime(st);
    int en_ = gettime(en);
    int v = en_ - st_;

    if(en_ < st_)
        v = 3600*24 - (st_-en_);
    
    result = cal(v);
    cout << result;
    
    return 0;
}