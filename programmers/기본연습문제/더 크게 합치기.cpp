#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    answer = max(stoi(ab), stoi(ba));
    
    return answer;
}