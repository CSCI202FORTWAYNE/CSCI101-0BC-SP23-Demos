#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


int main()
{
    cout << setprecision(2) << fixed << showpoint;
    double payRate;
    int hoursWorked, num;
    char a;
    string name;
    cout << "Enter a character: ";
    cin.get(a);
    cout << endl;
    cout <<"Enter the pay rate: ";
    cin >> payRate;
    cout << "Enter the hours worked: ";
    cin >> hoursWorked;
    cout << "Enter another number: ";
    cin >> num;
    cout << endl;
    cout << left;
    cout << "+-" << setw(30) << setfill('-') << "-" << "+-" << setw(20) << "-" << "+" << endl;
    cout << "| " << setw(30) << setfill(' ') << "Pay Rate:" << "| $" << setw(19) << payRate << "|" << endl;
    cout << "+-" << setw(30) << setfill('-') << "-" << "+-" << setw(20) << "-" << "+" << endl;
    cout << "| " << setw(30) << setfill(' ')  << "Hours worked:"<< "| " << setw(20) << hoursWorked << "|" << endl;
    cout << "+-" << setw(30) << setfill('-') << "-" << "+-" << setw(20) << "-" << "+" <<  endl;
    cout << "| " << setw(30) << setfill(' ')  << "num:"<< "| " << setw(20) << num << "|" << endl;
    cout << "+-" << setw(30) << setfill('-') << "-" << "+-" << setw(20) << "-" << "+" << endl;
    
    cout << "Enter your name: ";
    getline(cin >> ws, name);
    cout << endl;

    cout << "Hello " << name << "!" << endl;

    cout << "character: " << a << endl;

    double answer = pow(hoursWorked, num);

    cout << "answer: " << answer << endl;


    string make, model, color;
    int year;
    ifstream car;
    ofstream carOut;
    car.open("car.txt");
    carOut.open("carout.txt");
    getline(car >> ws, make);
    getline(car >> ws, model);
    car >> year;
    getline(car >> ws, color);

    carOut << make << " " << model << " " << year << " " << color << endl;

    getline(car >> ws, make);
    getline(car >> ws, model);
    car >> year;
    getline(car >> ws, color);
    carOut << make << " " << model << " " << year << " " << color << endl;
    car.close();



    return 0;
}