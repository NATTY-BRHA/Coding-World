#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number to check whether its even or odd?\n";
    cin>>n;
    if(n%2 == 0){
        cout<<"The entered number is even";
    }
    else{
        cout<<"The entered number is odd";
    }
return 0;
}
