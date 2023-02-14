#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <climits>

using namespace std;

int getPositiveNumber(string prompt);
double getPositiveNumber();

void resetStream();
int count();
const double PI = 3.14;

int main()
{

    string str;
    cout << "Enter something: ";
    getline(cin >> ws, str);
    cout << endl;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    str[0] = toupper(str[0]);
    if (str == "hello" || str == "hi" || str == "Hello")
    {
        int y;
        cout << "Good Morning!" << endl;
    }

    char ch;
    cout << "Do you want to go again? (Enter Y or N) ";
    cin >> ch;
    cout << endl;
    ch = toupper(ch);
    if (ch != 'Y' && ch != 'N')
    {
        cout << "That's not what I asked for!" << endl;
    }

    int x = getPositiveNumber("Enter a positive number");
    // cout << getPositiveNumber("Enter a positive number") << endl;

    // set up a loop that runs 10 times. each time call count and print the return value.

    return 0;
}

int getPositiveNumber(string prompt)
{
    int ret;
    cout << prompt;
    cin >> ret;
    cout << endl;

    while (!cin || ret < 0)
    {
        if (!cin)
        {
            resetStream();
        }
        else
        {
            cout << "The number entered should be positive." << endl;
        }
        cout << prompt;
        cin >> ret;
        cout << endl;
    }
    prompt = "Prompt done.";
    return ret;
}

void resetStream()
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "You entered something that is not a number." << endl;
}

int count()
{
    static int numTimes = 0;
    // do something to change the value of numTimes by 1
    return numTimes;
}