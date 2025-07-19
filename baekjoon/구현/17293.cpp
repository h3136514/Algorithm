#include<iostream>

using namespace std;

int N;

int main() {

    cin >> N;

    for(int i = N; i > 0; i--){

        if(i==1){
            cout << i <<" bottle of beer on the wall, " << i <<" bottle of beer.\n";
            cout <<"Take one down and pass it around, no more bottles of beer on the wall.\n";
        }
        else if(i == 2){
            cout << i <<" bottles of beer on the wall, " << i <<" bottles of beer.\n";
            cout <<"Take one down and pass it around, "<< i-1 << " bottle of beer on the wall.\n";
        }
        else{
            cout << i <<" bottles of beer on the wall, " << i <<" bottles of beer.\n";
            cout <<"Take one down and pass it around, "<< i-1 << " bottles of beer on the wall.\n";
        }

        cout <<"\n";

    }

    if(N == 1){
        cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
        cout << "Go to the store and buy some more, "<< N <<" bottle of beer on the wall.\n";
    }else{
        cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
        cout << "Go to the store and buy some more, "<< N <<" bottles of beer on the wall.\n";
    }

    return 0;

}