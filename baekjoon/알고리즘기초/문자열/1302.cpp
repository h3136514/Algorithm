#include <iostream>
#include <string>
#include <map>

using namespace std;
int N, CNT;
string bookName;
map<string, int> books; //map은 자동 정렬이 되므로 책이름이 사전순으로 있다.

// 베스트셀러
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> bookName;
        books[bookName]++;

        CNT = max(CNT, books[bookName]);
    }

    for(auto book : books){
        if(CNT == book.second){
            cout << book.first << "\n";
            break;
        }
    }
}