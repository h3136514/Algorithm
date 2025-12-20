#include <iostream>
#include <deque>

using namespace std;
int N, input, X;
deque<int> dq;

// 덱 2
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    while(N--){
        cin >> input;
        if(input == 1){
            cin >> X;
            dq.push_front(X);
        }else if(input == 2){
            cin >> X;
            dq.push_back(X);
        }else if(input == 3 || input == 4){
            if(dq.empty()){
                cout << "-1\n";
            }else{
                int num;
                if(input == 3){
                    num = dq.front();
                    dq.pop_front();
                }else{
                    num = dq.back();
                    dq.pop_back();
                }
                cout << num << "\n";
            }
        }else if(input == 5){
            cout << dq.size() << "\n";
        }else if(input == 6){
            int num = (dq.empty()) ? 1 : 0;
            cout << num << "\n";
        }else{
            int num;
            if(dq.empty()){
                num = -1;
            }else{
                if(input == 7){
                    num = dq.front();
                }else{
                    num = dq.back();
                }
            }
            cout << num << "\n";
        }
    }

    return 0;
}