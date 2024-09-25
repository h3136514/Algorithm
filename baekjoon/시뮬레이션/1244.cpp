#include <iostream>

using namespace std;
int N, student, gender, target, num[101];

// 남학생
void man() {
    int a = target;
    while(a <= N) {
        num[a] = (num[a] == 0) ? 1 : 0;
        a += target;
    }
}

// 여학생
void woman() {
    int s = target;
    int e = target;

    while(1 <= s && e <= N) {
        if(num[s] != num[e])
            break;
        
        num[s] = (num[s] == 0) ? 1 : 0;
        if(s != e) {
            num[e] = (num[e] == 0) ? 1 : 0;
        }

        s--;
        e++;
    }

}

// 스위치 켜고 끄기
int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> num[i];
        
    cin >> student;
    for(int i = 0; i < student; i++) {
        cin >> gender >> target;

        if(gender == 1)
            man();
        else
            woman();
    }

    for(int i = 1; i <= N; i++) {
        cout << num[i] << " ";
        if(i%20 == 0)
            cout << "\n";
    }

    return 0;
}
