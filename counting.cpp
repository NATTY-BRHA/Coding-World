#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"How many numbers you want to be counted?";
    int index,num;
    int sum = 0;
    cin>>index;
    for(int i=0;i<index;i++){
        cin>>num;
        sum=sum+num;
    }
    cout<<sum;
    
return 0;
}
