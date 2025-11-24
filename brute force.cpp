#include <iostream>
#include <string>
#include <ctime>        // library file for calculation of time
using namespace std;
string brute_force(string target){
        int min_len = 32;
        int max_len = 126;
        
        for (int ch1 = min_len ; ch1 <= max_len ; ch1++){
            for (int ch2 = min_len ; ch2 <= max_len ; ch2++){
                for (int ch3 = min_len ; ch3 <= max_len ; ch3++){
                    for (int ch4 = min_len ; ch4 <= max_len ; ch4++){
                        // Concetenation of characters to form an attempt;
                        string sample = string(1,(char)ch1) + (char)ch2 + (char)ch3 + (char)ch4;
                        //if concetenated word is the real password:
                        if(sample == target){
                            return sample;
                        }
                    }
                }
            }
        }
        throw runtime_error("Password not found of 4 char");
    }
int main() {
    string target = "Pytr";
    double elapse_time;
    try{
        clock_t strt_time = clock();
        string find_pass = brute_force(target);
        clock_t end_time = clock();
        
        elapse_time = double(strt_time - end_time) / CLOCKS_PER_SEC;
        cout<<"Wow ! We did it... Password FOUND: "<<find_pass<<"\n";
        cout<<"Time taken in this process is: "<<elapse_time<<"\n";
        
    } catch(const runtime_error& e){
        cerr << e.what() << endl;
    }
    return 0;
}
