#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
    int eom1, eom2, eom3;
    double discount1, discount2, discount3;
    int user;
    double discounta;
    double bill;

    cout << setprecision(2) << showpoint << fixed;

    ifstream eomFile;
    eomFile.open("EOM.txt");
    eomFile >> eom1 >> discount1;
    eomFile >> eom2 >> discount2;
    eomFile >> eom3 >> discount3;
    eomFile.close();

    cout << "Enter your employee number to see if you get a discount: ";
    cin >> user;
    if(!cin)
    {
        cout << "You did not enter a number! The program will now exit." << endl;
        return 0;
    }
    if(user < 10000 || user > 99999)
    {
        cout << "You entered a number that is out of range! ";
        cout << "Employee numbers are 5 digits (between 10000 and 99999). Program will now exit." << endl;
        return 0;
    }
    
    
    if(user == eom1)
    {
        discounta = discount1;
    }
    else if(user == eom2)
    {
        discounta = discount2;
    }
    else if (user == eom3)
    {
        discounta = discount3;
    }
    else
    {
        cout << "Sorry you did not win a discount this month. Try again next month." << endl;
        return 0;
    }

    cout << "You have won a discount of " << discounta * 100 << "%." << endl;
    cout << "Enter the total bill: ";
    cin >> bill;
    cout << endl;
    if(!cin)
    {
        cout << "You did not enter a number! The program will now exit." << endl;
        return 0;
    }
    if(bill <= 0)
    {
        cout << "The total should be greater than 0. The program will now exit." << endl;
        return 0;
    }
    

    cout << "Your discount will take $"<< bill * discounta <<" off your bill." << endl;
    cout << "Your new total is $" << bill - (bill*discounta) << "." << endl;




    return 0;
}