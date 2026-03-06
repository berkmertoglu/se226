

#include <iostream>
#include <cmath> //abs()
using namespace std;
int main(){
cout<<"---Task 1: Digital Root Sequence---"<<endl;
long long number;
cout<<"Please enter a positive integer greater than 9:";
cin>> number;
if(number<=9) {
cout << "Lütfen 9'dan büyük bir sayı giriniz." << endl;
}else{
int steps=0;
cout<< number;
while(number>=10) {
int digit_sum = 0;
long long temp_number = number;
while (temp_number > 0) {
digit_sum += temp_number%10;
temp_number /= 10;
}
number = digit_sum;
steps++;
cout << "->" << number;
}
cout<<"\nFinal value:"<<number<<endl;
cout<<"\nTotal steps:"<<steps<<endl;
}
cout<<"\n"<< string(40,'=')<<"\n"<<endl;
// TASK2: FizzBuzz Counter
int n2;
while (true){
cout<<"Please enter a number between 10 and 100:";
cin>> n2;
if(n2>=10&& n2<=100) break;
cout<<"Invalıd input.Please enter a number between 10 and 100"<<endl;
}
 int fizz_count=0;
 int buzz_count=0;
 int fizzbuzz_count=0;
 for (int i=1; i<=n2;i++) {
if (i % 7 == 0) continue;
if (i % 3 == 0 && i % 5 == 0) {
cout << "FizzBuzz" << endl;
fizzbuzz_count++;
} else if (i % 3 == 0) {
cout << "Fizz" << endl;
fizz_count++;
} else if (i % 5 == 0) {
cout << "Buzz" << endl;
buzz_count++;
} else {
cout << i << endl;
}
 }
cout<<"---Summary---"<<endl;
cout<<"Fizz count:"<<fizz_count<<endl;
cout<<"Buzz count:"<<buzz_count<<endl;
cout<<"FizzBuzz count:"<<fizzbuzz_count<<endl;
cout<<"\n"<<string(40, '=')<<"\n"<<endl;
//TASK3:
int n;
cout << "3 ile 9 arasinda bir sayi girin: ";
cin >> n;
if (n < 3 || n > 9) {
cout << "Gecersiz giris!" << endl;
return 0;
}
for (int i = 1; i <= 2 * n - 1; i++) { // 1. loop
int k;
if (i <= n)
k = i;
else
k = 2 * n - i;
for (int j = 1; j <= k; j++) { // 2. loop
cout << j;
}
cout << endl;

}
return 0;

}

