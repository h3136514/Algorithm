#include<iostream>

using namespace std;

int N;

int main() {

    cin >> N;

    for(int i = N; i > 0; i--){

        cout << i <<" bottles of beer on the wall, " << i <<" bottles of beer.\n";
        if(i==1)
            cout <<"Take one down and pass it around, no bottles of beer on the wall.\n";
        else if(i == 2) 
            cout <<"Take one down and pass it around, "<< i-1 << " bottle of beer on the wall.\n";
        else    
            cout <<"Take one down and pass it around, "<< i-1 << " bottles of beer on the wall.\n";
        cout <<"\n";

    }

    cout << "No more bottles of beer on the wall, no more bottles of beer.\n";

    cout << "Go to the store and buy some more, "<< N <<" bottles of beer on the wall.\n";

  

    return 0;

}