// 구현, 정렬, 맵
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
int N, sum;
string tim, hour, minu, name;
unordered_map<string, int> m;
vector<pair<int, string>> v;

// 정렬(통화요금: 내림차순, 이름: 오른차순)
bool compare(pair<int, string> a, pair<int, string> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

// 학생별 통화 요금 계산
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tim >> name;
        sum = 0;
        hour = "";
        minu = "";

        // 시 계산
        for(int j = 0; j < 2; j++){
            hour += tim[j];
        }
        if(hour != ""){
            sum += stoi(hour)*60;
        }

        // 분 계산
        for(int j = 3; j < 5; j++){
            minu += tim[j];
        }
        if(minu != ""){
            sum += stoi(minu);
        }

        if(m.find(name) == m.end())
            m[name] = sum;
        else{
            m[name] += sum;
        }
    }

    // 통화 요금 계산
    for(auto student : m){
        if(student.second <= 100){
            v.push_back({10, student.first});
        }else{
            student.second -= 100;
            int cal = (student.second%50 == 0) ? (student.second/50)*3 : (student.second/50+1)*3;
            v.push_back({cal+10, student.first});
        }
    }

    sort(v.begin(), v.end(), compare);

    // 출력
    for(int i = 0; i < v.size(); i++){
        cout << v[i].second << " " << v[i].first << "\n";
    }

    return 0;
}