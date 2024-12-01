#include <iostream>

using namespace std;
int N, num;
long long sum, price[100001], dist[100001], minPrice;

// 주유소
int main(){
    cin >> N;
    for(int i = 0; i < N -1; i++){
        cin >> dist[i];
    }
    for(int i = 0; i < N; i++){
        cin >> price[i];
    }

    minPrice = price[0];
    for(int i = 0; i < N -1; i++){
        minPrice = min(minPrice, price[i]);
        sum += dist[i] * minPrice;
    }

    cout << sum << "\n";

    return 0;
}