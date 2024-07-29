#include <vector>

using namespace std;
vector<int> parents;
vector<int> rankData;

int find(int x) {
    // x의 부모가 자신인 경우 루트노드를 찾았으므로 반환
    if(parents[x] == x)
        return x;
    
    return parents[x] = find(parents[x]);
}

void unionSet(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);

    // 루트 노드가 같을 경우 유니온 연산을 할 필요가 없음
    if(root1 != root2) {
        if(rankData[root1] < rankData[root2])
            parents[root1] = root2;
        else if(rankData[root1] > rankData[root2])
            parents[root2] = root1;
        else {
            parents[root2] = root1;
            rankData[root1]++;
        }
    }
}

vector<bool> solution(int k, vector<vector<char>> operations) {
    parents.resize(k);
    rankData.resize(k, 0);

    // 초기에 각 노드는 자신을 부모로 설정
    for(int i = 0; i < k; i++)
        parents[i] = i;
    
    vector<bool> results;
    for(auto op : operations) {
        int x = op[1] - '0'; // 문자를 숫자로 변환
        int y = op[2] - '0'; // 문자를 숫자로 변환
        
        if(op[0] == 'u') 
            unionSet(x, y);
        else if(op[0] == 'f')
            results.push_back(find(x) == find(y));
    }

    return results;
}


#include <iostream>

using namespace std;

void init()
{
    parents.clear();
    rankData.clear();
}

void print(vector<bool> vec)
{
    cout << vec[0];
    for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
    cout << endl;
}

int main()
{
  print(solution(3, {{'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}})); // 결과값 : 1
  init();
  print(solution(4, {{'u', '0', '1'}, {'u', '2', '3'}, {'f', '0', '1'}, {'f', '0', '2'}})); // 결과값 : 1 0
  
  return 0;
}
