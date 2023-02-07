#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <fstream>

using namespace std;

int main()
{
    int num = 0;
    int count = 0;
    double sum = 0;
    double daily = 0;

    cout << "How many days of calories do you want to enter? ";
    cin >> num;
    cout << endl;
    while (!cin || num < 0)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "You entered something that is not a number." << endl;
        }
        else
        {
            cout << "Please enter a positive number." << endl;
        }
        cout << "How many days of calories do you want to enter? ";
        cin >> num;
        cout << endl;
    }

    while (count < num) // change to for (initial statement; loop condition; count++)
    {
        cout << "Enter the calories for day " << count + 1 << ": ";
        cin >> daily;
        cout << endl;
        while (!cin || daily < 0)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "You entered something that is not a number." << endl;
            }
            else
            {
                cout << "Please enter a positive number. " << endl;
            }
            cout << "Enter the calories for day " << count + 1 << ": ";
            cin >> daily;
            cout << endl;
        }
        sum = sum + daily;
        count++;
    }

    cout << "The average number of calories burned per day is " << sum / num << endl;

    char cont;
    do
    {
        cout << "Do you want to go again? ";
        cin >> cont;
        cout << endl;
        if (cont != 'y' && cont != 'n')
        {
            cout << "I don't understand.  Please enter y or n." << endl;
            cont = 'y';
           continue;
        }
    } while (cont == 'y');

    int guess = 0;
    int win = 0;
    bool isGuessed = false;
    srand(time(0));
    win = rand() % 100 + 1;

    while (!isGuessed)
    {
        cout << "Guess the number between 1 and 100: ";
        cin >> guess;
        cout << endl;
        if (!cin || guess < 1 || guess > 100)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "You entered something that is not a number." << endl;
            }
            else
            {
                cout << "Please enter a number between 1 and 100." << endl;
            }
            continue;
        }

        if (guess == win)
        {
            cout << "You have guessed the number!" << endl;
            isGuessed = true;
        }
    }

    ifstream order;
    order.open("orders.txt");
    if (!order.is_open())
    {
        return 0;
    }
    char product;
    int qty = 0;
    char maxProduct;
    int maxQty = 0;

    while (!order.eof())
    {
        order >> product >> qty;
        if (qty > maxQty)
        {
            maxProduct = product;
            maxQty = qty;
        }
        cout << product << " " << qty << endl;
    }
    cout << "The product with the highest quantity is " << maxProduct
         << " with " << maxQty << " ordered." << endl;

    return 0;
}