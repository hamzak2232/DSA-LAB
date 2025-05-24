// EXAMPLE 3.1

#include<iostream>
#include<conio.h>
using namespace std;
int fact(int n){
    if(n==0) {
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    cout<<fact(5)<<endl;
    getch();
    return 0;
}

// EXAMPLE 3.2

#include <iostream>
#include<conio.h>
using namespace std;
void rev(){
    char ch;
    cin.get(ch);
    if(ch!='\n'){
        rev();
        cout.put(ch);
    }
}
int main(){
    rev();
    getch();
    return 0;
}

// EXAMPLE 3.3

#include<iostream>
using namespace std;
int power(int x,int n){
    if(n==0){
        return 1;
    }
    else{
        return power(x,n-1)*x;
    }
}
int main(){
    cout<<power(3,4)<<endl;
    return 0;
}

// EXAMPLE 3.4

#include<iostream>
using namespace std;
int ackermann(int m,int n){
    if(m==0){
        return(n+1);
    }
    else if(m>0 && n==0){
        return (ackermann(m-1,1));
    }
    else if(m>0 && n>0){
        return (ackermann(m-1,ackermann(m,n-1)));
    }
}
int main(){
    int m=1, n=0;
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;
    return 0;
}

// Exercise 3.1

#include <iostream>
using namespace std;

int exponentiate(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    else {
        return exponentiate(base, exp - 1) * base;
    }
}

int main() {
    int baseValue = 2;
    cout << "n\t2^n" << endl;
    for (int exp = 0; exp <= 20; exp++) {
        cout << exp << "\t" << exponentiate(baseValue, exp) << endl;
    }
    return 0;
}

// Exercise 3.2

#include<iostream>
using namespace std;

int AckermannFunction(int firstParam, int secondParam) {
    if (firstParam == 0) {
        return (secondParam + 1);
    } else if (firstParam > 0 && secondParam == 0) {
        return (AckermannFunction(firstParam - 1, 1));
    } else if (firstParam > 0 && secondParam > 0) {
        return (AckermannFunction(firstParam - 1, AckermannFunction(firstParam, secondParam - 1)));
    }
}

int main() {
    int firstValue = 3, secondValue = 4;
    cout << "Ackermann(" << firstValue << ", " << secondValue << ") = " << AckermannFunction(firstValue, secondValue) << endl;
    return 0;
}

// Exercise 3.3

// A)

#include <iostream>
using namespace std;

void displayNumbers(int count) {
    if (count < 0) return;
    cout << count << " ";
    displayNumbers(count - 1);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    displayNumbers(number);
    return 0;
}

// B)

#include <iostream>
using namespace std;

int calculateBinomialCoefficient(int total, int selection) {
    if (selection == 0 || selection == total) return 1;
    return calculateBinomialCoefficient(total - 1, selection - 1) + calculateBinomialCoefficient(total - 1, selection);
}

int main() {
    int total, selection;
    cout << "Enter values for total and selection: ";
    cin >> total >> selection;
    cout << "C(" << total << ", " << selection << ") = " << calculateBinomialCoefficient(total, selection);
    return 0;
}

// C)

#include <iostream>
using namespace std;

bool checkPrimeRecursion(int number, int divisor) {
    if (divisor == 1) return true;
    if (number % divisor == 0) return false;
    return checkPrimeRecursion(number, divisor - 1);
}

bool checkPrime(int number) {
    if (number <= 1) return false;
    return checkPrimeRecursion(number, number - 1);
}

int main() {
    int inputNumber;
    cout << "Enter a number: ";
    cin >> inputNumber;
    if (checkPrime(inputNumber))
        cout << inputNumber << " is a prime number.";
    else
        cout << inputNumber << " is not a prime number.";
    return 0;
}