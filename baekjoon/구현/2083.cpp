#include <iostream>
#include <string>

using namespace std;
int age, weight;
string name, level;

// 럭비 클럽
int main(){
    while(true){
        cin >> name >> age >> weight;
        if(name == "#" && !age && !weight)
            break;
        
        if(age > 17 || weight >= 80)
            level = "Senior";
        else
            level = "Junior";

        cout << name << " " << level << "\n";
    }

    return 0;
}