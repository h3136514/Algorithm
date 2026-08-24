// https://school.programmers.co.kr/learn/courses/30/lessons/17680
#include <string>
#include <vector>
#include <deque>
 
using namespace std;
deque<string> cache;
int answer = 0;

int solution(int cacheSize, vector<string> cities) { 
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
 
        //대문자 -> 소문자 변환
        for (int j = 0; j < city.length(); j++) {
            city[j] = tolower(city[j]);
        }
 
        //캐시 hit, miss인지 판단
        bool hit = false;
        int index = 0;
        for (index = 0; index < cache.size(); index++) {
            if (cache[index] == city) {
                hit = true;
                break;
            }
        }
 
        //cache 가장 뒤에 넣기(LRU 이므로)
        cache.push_back(city);
 
        //캐시 hit일 경우
        if (hit) {
            //캐시에 있는 기존 데이터 삭제
            cache.erase(cache.begin() + index);
            answer += 1;
        }
        //캐시 miss일 경우
        else {
            //캐시가 넘쳤을 경우, 맨 앞에 있는 가장 오래된 데이터 삭제
            if (cache.size() > cacheSize) {
                cache.pop_front();
            }
            answer += 5;
        }
    }

    return answer;
}
