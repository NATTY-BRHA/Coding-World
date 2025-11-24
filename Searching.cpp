#include<iostream>
#include<string>
using namespace std;
int main(){
    string name;
    string StdName[10] = {"Olivia","Amelia","Ava","Charlotte","Emily","Isla","Mia","Noah","Oliver","William "};
    cout<<"Enter a name to be searched from the list:\n";
    cin>>name;
    for(int i =0;i<10;i++){
        if(name == StdName[i]){
            cout<<"Found";
        }
    }
return 0;
}
