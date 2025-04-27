// 자료구조, 해시를 사용한 집합과 맵
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int A, B, C, N, CCNT;
long long price, sum;
string name;
bool check = true;
unordered_map<string, long long> menuKind, menu;
queue<long long> AQ, BQ;

// 정식당
int main(){
    cin >> A >> B >> C;
    // 일반메뉴 저장
    for(int i = 0; i < A; i++){
        cin >> name >> price;
        menuKind[name] = 1;
        menu[name] = price;
    }
    // 특별메뉴 저장
    for(int i = 0; i < B; i++){
        cin >> name >> price;
        menuKind[name] = 2;
        menu[name] = price;
    }
    // 서비스메뉴 저장
    for(int i = 0; i < C; i++){
        cin >> name;
        menuKind[name] = 3;
        menu[name] = 0;
    }

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> name;
        if(menuKind[name] == 1){
            AQ.push(menu[name]);
        }else if(menuKind[name] == 2){
            BQ.push(menu[name]);
        }else
            CCNT++;
    }

    while(!AQ.empty()){
        sum += AQ.front();
        AQ.pop();
    }

    if(!BQ.empty() && sum < 20000)  // 특별메뉴는 일반메뉴에서 총 20,000원 이상을 주문해야 가능
        check = false;

    while(!BQ.empty()){
        sum += BQ.front();
        BQ.pop();
    }

    if(CCNT > 1 || (CCNT == 1 && sum < 50000))  // 서비스메뉴는 단 하나만 가능하고 총 50,000원 이상을 주문해야 가능
        check = false;

    if(check)
        cout << "Okay\n";
    else
        cout << "No\n";

    return 0;
}