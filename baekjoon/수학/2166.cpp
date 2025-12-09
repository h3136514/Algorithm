#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int N, x, y;
double result;
vector<pair<double, double>> v;

double solve(int i, int j){
    double a = v[0].first, b = v[0].second;
    double c = v[i].first, d = v[i].second;
    double e = v[j].first, f = v[j].second;

    return (a*d + c*f + e*b - c*b - e*d - a*f)/2;
}

// 다각형의 면적
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }

    for(int i = 1; i < N - 1; i++){
        result += solve(i, i+1);
    }

    cout << fixed;
    cout.precision(1);

    cout << abs(result) << "\n";

    return 0;
}