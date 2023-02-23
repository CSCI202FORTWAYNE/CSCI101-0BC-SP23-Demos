#include <iostream>
#include <climits>
#include <string>

void resetStream();

const int MAX_SIZE = 100;
enum colorType
{
    BLUE,
    RED,
    GREEN,
    PURPLE,
    YELLOW,
    ORANGE
};
const std::string colorToStr[] = {"Blue", "Red", "Green", "Purple", "Yellow", "Orange"};
const colorType colors[] = {BLUE,
                            RED,
                            GREEN,
                            PURPLE,
                            YELLOW,
                            ORANGE};

void inputArray(int[], int);

int main()
{
    colorType c = GREEN;
    std::cout << colorToStr[c] << std::endl;
    int nums[MAX_SIZE];
    int sum = 0;
    int largestPos = 0;

    for (int i = 0; i < MAX_SIZE; i++) // i = i + 1;
    {
        nums[i] = 0;
    }
    inputArray(nums, 10);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << nums[i] << std::endl;
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        sum += nums[i]; // sum = sum + nums[i];
    }
    std::cout << "The sum of the elements is " << sum << std::endl;
    std::cout << "The average of the elements is " << static_cast<double>(sum) / MAX_SIZE << std::endl;

    for (int i = 1; i < MAX_SIZE; i++)
    {
        if (nums[i] > nums[largestPos])
        {
            largestPos = i;
        }
    }
    std::cout << "The largest item is " << nums[largestPos] << " located at "
              << largestPos << "." << std::endl;

    // std::cout << nums << std::endl;

    int table[10][10];

    table[0][0] = 0;
    int row = 0;
    for (int i = 0; i < 10; i++)
    {
        table[row][i] = 0;
    }
    int col = 0;
    for (int i = 0; i < 10; i++)
    {
        table[i][col] = 0;
    }
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            std::cout << "Enter a number: ";
            std::cin >> table[row][col];
            std::cout << std::endl;
            while (!std::cin)
            {
                resetStream();
                std::cout << "Enter a number: ";
                std::cin >> table[row][col];
                std::cout << std::endl;
            }
        }
    }

    // lecture activity add code to output. There should be a space between each item in a row and a \n in between each row

    for (col = 0; col < 10; col++)
    {
        int sum = 0;
        for (row = 0; row < 10; row++)
        {
            sum += table[row][col];
        }
        std::cout << "The sum of column " << col << " is " << sum << std::endl;
    }

    // lecture activity 2: Add row processing that calculates the sum of each row.

    return 0;
}

void resetStream()
{

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "You entered something that is not a number." << std::endl;
}

void inputArray(int list[], int numItems)
{
    for (int i = 0; i < numItems; i++)
    {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> list[i];
        std::cout << std::endl;
        while (!std::cin)
        {
            resetStream();
            std::cout << "Enter number " << i + 1 << ": ";
            std::cin >> list[i];
            std::cout << std::endl;
        }
    }
}