// 구현, 문자열
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string str, tmp;
vector<string> target = { "c'", "j'", "n'", "m'", "t'", "s'", "l'", "d'", "qu'" };
vector<string> vowel = { "a", "e", "i", "o", "u", "h" };
vector<string> v, result;

// 줄어들었을 가능성이 있는지 확인(
bool checkViwel(string s) {
	for (int i = 0; i < target.size(); i++) {
		for (int j = 0; j < vowel.size(); j++) {
			if (s == (target[i] + vowel[j])) 
				return true;
		}
	}

	return false;
}

// 단어 개수 세기 
int main() {
	getline(cin, str);

	tmp = "";
	for (int i = 0; i < str.size(); i++) {
		if ((str[i] == '-') || (str[i] == ' ')) {   // 띄어쓰기와 -(하이픈)을 기준으로 “단어”를 쪼갠다
			v.push_back(tmp);
			tmp = "";
			continue;
		}

		tmp += str[i];
	}
	v.push_back(tmp);

	for (int i = 0; i < v.size(); i++) {
		tmp = v[i][0];
		for (int j = 1; j < v[i].size(); j++) {
			tmp += v[i][j];
			if (v[i][j - 1] == '\'') {
				if (checkViwel(tmp)) {  // 단어가 줄어들었을 가능성이 있는지 확인
					result.push_back(tmp.substr(0, tmp.size() - 1));
					tmp = v[i][j];
				}
			}
		}
		if (tmp != "")
			result.push_back(tmp);
	}

	cout << result.size() << "\n";

	return 0;
}