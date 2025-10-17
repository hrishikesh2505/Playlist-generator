#include <iostream>
using namespace std;
int main() {
 int num;
// int fact=1;
// cout<<"Enter number: ";
// cin>>num;
// for(int i=1; i<=num; i++){
//     fact=fact*i;
// }
// cout<<fact;
    cout<<"Enter num: ";
    cin>>num;
    if (num==2){
        cout<<"prime";
    }else{
        for(int i=2; i<num; i++){
        if(num %i ==0){
            cout<<" is not prime.";break;
        }
    }    
    }
    cout<<" is prime.";

    return 0;
    }