#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N;
vector<string> v;

int calInt(string a){
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] - '0' > 0 && a[i] - '0' < 10)
            sum += a[i] - '0';
    }

    return sum;
}

bool compare(string a, string b){
    if(a.size() == b.size()){
        int aNum = calInt(a);
        int bNum = calInt(b);
        if(aNum == bNum){
            return a < b;
        }

        return aNum < bNum;
    }
    
    return a.size() < b.size();
}

// 시리얼 번호
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < N; i++){
        cout << v[i] << "\n";
    }

    return 0;
}
