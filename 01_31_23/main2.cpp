/*#include <iostream>

using namespace std;


int main()
{
    
    int win = 56;
    int user = 0;
    bool day = true;
    cout << "Enter a number: ";
    cin >> user;
    cout << endl;
    if(win >= user)
        
        cout << "My number is higher than yours. I win!!" << endl;
    else
        cout << "I didn't win this time.  I'll win next time." << endl;

    cout << "Thanks for playing!" << endl;
        return 0;
}
*/
    
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << endl;
    if (0 <= num && num <= 10)
    cout << num << " is within 0 and 10." << endl;
    else
        cout << num << " is not within 0 and 10." <<        
    endl;
    return 0;
}
    


