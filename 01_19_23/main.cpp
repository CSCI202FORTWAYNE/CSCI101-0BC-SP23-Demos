#include <iostream>
#include <string>

using namespace std;


int main()
{
    int x = 5;
    int num = 2;
    double y = 4.5;
    double z = x + y;
    char ch = 'A';
    string input = "Have a nice day!/n";

    //x = 15;
    z = x + y;
    double answer = x / num; // answer = 2
    cout << answer << endl;
    //cout << 5 % 2 << endl;
    answer = static_cast<double>(x) / num + 7.5;
    cout << "Enter a whole number: ";
    cin >> x;
    cout << endl;


    cout << "You have entered " << x << endl;

    return 0;
}