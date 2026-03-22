#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int n;
vector<string> words;

bool isSimilar(string target, string word) {
    if (abs((int)target.length() - (int)word.length()) > 1)
        return false;

    vector<int> count(26, 0);
    for (char c : target) count[c - 'A']++;
    for (char c : word) count[c - 'A']--;

    int diff = 0;
    for (int i : count)
        diff += abs(i);

    return diff <= 2;
}

// 비슷한 단어
int main() {
    cin >> n;
    words.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    int count = 0;
    for (int i = 1; i < n; i++) {
        if (isSimilar(words[0], words[i])) 
            count++;
    }

    cout << count;
    return 0;
}