#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> m;
vector<int> answer;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    for(int i = 0; i < name.size(); i++){
        m[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); i++){
        int sum = 0;
        for(int j = 0; j < photo[i].size(); j++){
            sum +=m[photo[i][j]];
        }
        answer.push_back(sum);
    }
    
    return answer;
}