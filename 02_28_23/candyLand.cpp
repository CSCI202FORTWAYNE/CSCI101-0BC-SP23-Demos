#include <iostream>
#include <string>

const int NUM_COLORS = 6;
const int DECK_SIZE = 60;
const int BOARD_SIZE = 115;
const int MAX_PLAYERS = 6;

enum colorType
{
    START = -1,
    RED,
    PURPLE,
    YELLOW,
    GREEN,
    BLUE,
    ORANGE
};
const std::string colorName[] = {"Red", "Purple", "Yellow", "Green", "Blue", "Orange"};
const colorType colors[] = {RED,
                            PURPLE,
                            YELLOW,
                            GREEN,
                            BLUE,
                            ORANGE};
const string colorStr[] = {"\033[38;5;196m\033[48;5;88m",
                           "\033[38;5;135m\033[48;5;53m",
                           "\033[38;5;226m\033[48;5;178m",
                           "\033[38;5;118m\033[48;5;2m",
                           "\033[38;5;81m\033[48;5;4m",
                           "\033[38;5;214m\033[48;5;166m"};
const string STARTCOLOR = "\033[1m";
const string RESETCOLOR = "\033[0m";

struct cardType
{
    colorType color;
    bool isDouble = false;
};

struct playerType
{
    std::string name;
    colorType color;
    int position = 0;
};

void generateBoard(colorType[], int);
std::string getColorName(colorType); // complete for lecture activity

struct playerListType
{
    playerType playerList[MAX_PLAYERS];
    int numPlayers;
};

int main()
{
    colorType board[BOARD_SIZE];
    generateBoard(board, BOARD_SIZE);
}

void generateBoard(colorType[], int)
{
}
