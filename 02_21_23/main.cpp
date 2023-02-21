#include <iostream>
#include <climits>
#include <string>

/* create a program that uses a cerealType enum. Create the enum with any 4 values you want (put into preference order). Create an input function and an output function. In the main create a variable input using the function and output using the function.
 */

enum colorType
{
    BLUE,
    RED,
    GREEN,
    PURPLE,
    YELLOW,
    ORANGE
};

void resetStream();
colorType inputColor();
void printColor(colorType);
std::string colorToString(colorType);

int main()
{
    int num = 67;
    colorType myColor = inputColor();
    std::cout << "My color is ";
    printColor(myColor);
    std::cout << std::endl;
    std::cout << "My color is " << colorToString(myColor) << std::endl;

    return 0;
}

void resetStream()
{

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "You entered something that is not a number." << std::endl;
}

colorType inputColor()
{
    int num;
    colorType myColor;
    std::cout << "Choose a color:" << std::endl;
    std::cout << "1. Blue" << std::endl;
    std::cout << "2. Red" << std::endl;
    std::cout << "3. Green" << std::endl;
    std::cout << "4. Purple" << std::endl;
    std::cout << "5. Yellow" << std::endl;
    std::cout << "6. Orange" << std::endl;
    std::cin >> num;
    std::cout << std::endl;
    while (!std::cin || num - 1 < BLUE || num - 1 > ORANGE)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please choose a color using the number next to the color name." << std::endl;
        std::cin >> num;
        std::cout << std::endl;
    }
    switch (num)
    {
    case 1:
        myColor = BLUE;
        break;
    case 2:
        myColor = RED;
        break;
    case 3:
        myColor = GREEN;
        break;
    case 4:
        myColor = PURPLE;
        break;
    case 5:
        myColor = YELLOW;
        break;
    case 6:
        myColor = ORANGE;
        break;
    default:
        myColor = BLUE;
    }
    return myColor;
}

void printColor(colorType theColor)
{
    switch (theColor)
    {
    case BLUE:
        std::cout << "Blue";
        break;
    case RED:
        std::cout << "Red";
        break;
    case GREEN:
        std::cout << "Green";
        break;
    case PURPLE:
        std::cout << "Purple";
        break;
    case YELLOW:
        std::cout << "Yellow";
        break;
    case ORANGE:
        std::cout << "Orange";
        break;
    default:
        std::cout << "Unknown Color";
    }
}

std::string colorToString(colorType theColor)
{
    switch (theColor)
    {
    case BLUE:
        return "Blue";
        break;
    case RED:
        return "Red";
        break;
    case GREEN:
        return "Green";
        break;
    case PURPLE:
        return "Purple";
        break;
    case YELLOW:
        return "Yellow";
        break;
    case ORANGE:
        return "Orange";
        break;
    default:
        return "Unknown Color";
    }
}