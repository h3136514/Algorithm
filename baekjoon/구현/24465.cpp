#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int N, a, b;
map<int, bool> m;
vector<pair<int, int>> v;

int searchStar(int month, int day){
    int star;
    if((month == 1 && day >= 20) ||(month == 2 && day <= 18)){
        star = 1;
    }else if((month == 2 && day >= 19) ||(month == 3 && day <= 20)){
        star = 2;
    }else if((month == 3 && day >= 21) ||(month == 4 && day <= 19)){
        star = 3;
    }else if((month == 4 && day >= 20) ||(month == 5 && day <= 20)){
        star = 4;
    }else if((month == 5 && day >= 21) ||(month == 6 && day <= 21)){
        star = 5;
    }else if((month == 6 && day >= 22) ||(month == 7 && day <= 22)){
        star = 6;
    }else if((month == 7 && day >= 23) ||(month == 8 && day <= 22)){
        star = 7;
    }else if((month == 8 && day >= 23) ||(month == 9 && day <= 22)){
        star = 8;
    }else if((month == 9 && day >= 23) ||(month == 10 && day <= 22)){
        star = 9;
    }else if((month == 10 && day >= 23) ||(month == 11 && day <= 22)){
        star = 10;
    }else if((month == 11 && day >= 23) ||(month == 12 && day <= 21)){
        star = 11;
    }else{
        star = 12;
    }

    return star;
}

// 데뷔의 꿈
int main(){
    for(int i = 0; i < 7; i++){
        cin >> a >> b;
        m[searchStar(a, b)] = true;
    }

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        if(m.find(searchStar(a, b)) == m.end()){
            v.push_back({a, b});
        }
    }
    if(v.empty()){
        cout <<"ALL FAILED\n";
    }else{
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            cout << v[i].first << " " << v[i].second << "\n";
        }
    }

    return 0;
}