#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;
unordered_map<string, string> name;
string command[3] ={"Enter", "Leave", "Change"};

// ä�ù濡 ������ �����ų�, �г����� ������ ����� ��� ���ڿ� �迭 record�� �־��� ��, ��� ����� ó���� ��, ���������� ���� ������ ����� ���� �Ǵ� �޽����� ���ڿ� �迭 ���·� ��ȯ(�ð����⵵ : O(N))
vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    // �� record�� ���ؼ� ��ɾ ���� id�� �´� �г����� name�� ����
    for(int i=0; i < record.size(); i++){
        // ���ڿ��� ��Ʈ��ȭ
        stringstream ss(record[i]);
         // ���� �и� ����� ������ �迭
        vector<string> strs;
        
        string str;
        // ��Ʈ���� �� �پ� �о�, ���� ������ �и��� ��, ���Ϳ� ����
        while(getline(ss, str, ' ')){
            strs.push_back(str);
        }
        if(strs[0] == command[0] || strs[0] == command[2]){
            name[strs[1]] = strs[2];
        }
    }

    // �� record�� ���ؼ� Enter �� Change ��ɾ��� ��� ���� �г��Ӱ� ������ ���ڿ��� answer�� �߰�
    for(int i=0; i < record.size(); i++){
        string result ="";
        // ���ڿ��� ��Ʈ��ȭ
        stringstream ss(record[i]);
         // ���� �и� ����� ������ �迭
        vector<string> strs;
        
        string str;
        // ��Ʈ���� �� �پ� �о�, ���� ������ �и��� ��, ���Ϳ� ����
        while(getline(ss, str, ' ')){
            strs.push_back(str);
        }
        if(strs[0] == command[0])
            result += name[strs[1]] + "���� ���Խ��ϴ�.";
        else if(strs[0] == command[1])
            result += name[strs[1]] + "���� �������ϴ�.";
        else
            continue;
            
        answer.push_back(result);
    }

    return answer;
}

#include <iostream>

void print(vector<string> vec)
{
    cout << vec[0];
  for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
  cout << endl;
}

int main()
{
  print(solution( {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan"} ));
  // Prodo���� ���Խ��ϴ�. Ryan���� ���Խ��ϴ�. Prodo���� �������ϴ�. Prodo���� ���Խ��ϴ�.    

  return 0;
}