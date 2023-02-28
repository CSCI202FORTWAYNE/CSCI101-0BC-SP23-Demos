#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>

const int MAX_CANDIDATES = 10;

struct candidateType
{
    std::string name;
    int votes;
    double percent;
};

struct ballotType
{
    candidateType candidates[MAX_CANDIDATES];
    int numCandidate;
};

void printCandidate(candidateType);
void printCandidate(std::ostream &, candidateType);
candidateType getVotes(candidateType);
void resetStream();

int main()
{
    std::ifstream ballot;
    ballot.open("ballot.txt");
    ballotType theballot;
    theballot.numCandidate = 0;
    int total = 0;
    int winner = 0;
    while (!ballot.eof() && theballot.numCandidate < MAX_CANDIDATES)
    {
        ballot >> theballot.candidates[theballot.numCandidate++].name;
    }
    for (int i = 0; i < theballot.numCandidate; i++)
    {
        theballot.candidates[i] = getVotes(theballot.candidates[i]);
        total = total + theballot.candidates[i].votes;
    }
    for (int i = 0; i < theballot.numCandidate; i++)
    {
        theballot.candidates[i].percent = theballot.candidates[i].votes / static_cast<double>(total);
    }
    std::cout << std::showpoint << std::setprecision(2) << std::fixed;
    std::cout << std::left << std::setw(10) << "Candidate" << std::right << "   " << std::setw(10) << "Votes Received"
              << "   " << std::setw(15) << "% of Total Votes" << std::endl;
    for (int i = 0; i < theballot.numCandidate; i++)
    {
        printCandidate(std::cout, theballot.candidates[i]);
    }
    std::cout << std::left;
    std::cout << std::setw(19) << "Total" << total << std::endl;
    for (int i = 1; i < theballot.numCandidate; i++)
    {
        if (theballot.candidates[i].votes > theballot.candidates[winner].votes)
        {
            winner = i;
        }
    }
    std::cout << "The Winner of the Election is " << theballot.candidates[winner].name << "." << std::endl;
    /* sample row output line
    /* candidateType candidate;
    ballot >> candidate.name;
    candidate.votes = 0;
    candidate.percent = 0;
    std::cout << candidate.name << std::endl;
    printCandidate(candidate);

    candidateType c2;
    ballot >> c2.name;
    c2.votes = 0;
    c2.percent = 0;
    std::cout << c2.name << std::endl;
    printCandidate(std::cout, c2);
    printCandidate(result, c2);

    c2 = candidate;
    std::cout << c2.name << std::endl; */

    return 0;
}

void printCandidate(candidateType theCandidate)
{
    std::cout << std::left << std::setw(10) << theCandidate.name
              << std::right << "   " << std::setw(10) << theCandidate.votes << "   " << std::setw(15)
              << theCandidate.percent * 100
              << "%" << std::endl;
}

void printCandidate(std::ostream &out, candidateType theCandidate)
{
    out << std::left << std::setw(10) << theCandidate.name
        << std::right << "   " << std::setw(10) << theCandidate.votes << "   " << std::setw(15)
        << theCandidate.percent * 100
        << "%" << std::endl;
}

candidateType getVotes(candidateType theCandidate)
{
    std::cout << "Enter the number of votes received by " << theCandidate.name << ": ";
    std::cin >> theCandidate.votes;
    std::cout << std::endl;
    while (!std::cin || theCandidate.votes < 0)
    {
        if (!std::cin)
        {
            resetStream();
        }
        else
        {
            std::cout << "The votes should be greater than 0." << std::endl;
        }
        std::cout << "Enter the number of votes received by " << theCandidate.name << ": ";
        std::cin >> theCandidate.votes;
        std::cout << std::endl;
    }
    return theCandidate;
}
void resetStream()
{

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "You entered something that is not a number." << std::endl;
}
