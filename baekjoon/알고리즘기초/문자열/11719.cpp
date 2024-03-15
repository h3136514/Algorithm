#include <iostream>
#include <string> //getline() 사용
using namespace std;

int main() {
	string str;

	while (getline(cin, str)) //빈 줄이 주어질 수도 있기에 while문의 조건문에 getline() 함수를 사용하여, 입력이 없으면 종료되도록 한다.
    {
		cout << str << endl;
	}
}