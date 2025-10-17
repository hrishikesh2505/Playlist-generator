//Name: Hrishikesh Bhuyan
//Enrollment id: ADTU/2025-29/BCSM/060 
#include <iostream>
using namespace std;
int main() {
    //question 1
// int w,l;
// cout<<"Enter width: ";
// cin>>w;
// cout<<"Enter length:";
// cin>>l;
// int area = l*w ;
// cout << "Area="<<area<<endl;
// int perimeter = 2*(l+w);
// cout<<"Perimeter="<<perimeter<<endl;
//question 2
// float c;
// cout<<"Enter temperature in Celsius: ";
// cin>>c;
// float f = (c*9/5)+32;
// cout<<"Temperature in Fahrenheit: "<<f<<endl;
//question 3
// int a;
// cout<<"Enter a number: ";
// cin>>a;
// if(a%2==0){
//     cout<<a<<" is even number."<<endl;
// }
// else{
//     cout<<a<<" is odd number."<<endl;
// }
// if(a%5==0){
//     cout<<a<<" is divisible by 5."<<endl;
// }
// else{
//     cout<<a<<" is not divisible by 5."<<endl;
// }
//question 4
// int n;
// int count=0;
// cout<<"Enter a number: ";
// cin>>n;
// if(n%2==0){
//     cout<<n<<" is even number."<<endl;
// }else{
//     cout<<n<<" is odd number."<<endl;
// }
// if(n<=1){
//     cout<<n<<" is neither prime nor composite."<<endl;
// }
// for(int i=2;i<=n/2;i++){
//     if(n%i==0){
//         count++;
//         break;
//     }

// if(count==0){
//     cout<<n<<" is a prime number."<<endl;break;
// }else{
//     cout<<n<<" is not a prime number."<<endl;break;
// }
// }
//question 5
// int num1,num2;

// cout<<"Enter number1: ";
// cin>>num1;
// cout<<"Enter number2: ";
// cin>>num2;
// int a=num1;
// int b=num2;
// while(b!=0){
//     int temp=b;
//     b=a%b;
//     a=temp;
// }
// int gcd = a;
// int lcm = (num1*num2)/gcd;
// cout<<"GCD= "<<gcd<<endl;
// cout<<"LCM= "<<lcm<<endl;
int a,  total=0;
cout<<"Enter number of students: ";
cin>>a;
int marks[a];
for(int i=0;i<a;i++){
    cout<<"Enter marks of student: ";
    cin>>marks[i];
    total+=marks[i];
    
}

double average = total/a;

cout<<"Average marks: "<<average<<endl;
cout<<"Total marks: "<<total<<endl;
return 0;


}