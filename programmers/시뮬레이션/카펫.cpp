#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 반환(갈색 격자를 노란색 격자에 둘러싼다.)
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 격자의 총 개수 (갈색 격자 + 노란색 격자)
    int total_size = brown + yellow;
    
    //세로 길이는 최소 3이고 최대(파란색 격자 + 흰색 격자)의 제곱근(정삼각형) 이다.
    for(int h = 3; h <= sqrt(total_size); h++) {
        // 사각형 구성이 되는지 확인
        if(total_size % h == 0) {
            int w = total_size / h;   // 가로 길이
            
            // 카펫 형태로 만들 수 있는지 확인
            if(brown == (w + h - 2) * 2) {
                answer.push_back(w);
                answer.push_back(h);
                
                break;
            }   
        }    
    }
    
    return answer;
}


//테스트 코드
#include <iostream>

using namespace std;

void print(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
    print(solution(10, 2)); //출력값 : 4 3
    print(solution(8, 1)); //출력값 : 3 3
    print(solution(24, 24)); //출력값 : 8 6
  
    return 0;
}

// 더 간단한 코드
/*
vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}
*/