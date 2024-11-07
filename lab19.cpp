// Polina Maidanova
// Programming Fundamentals
// CS 1436
// 005
// Due Date: 11/09/2024
// Date Completed: 11/07/2024
// Date Submitted: 11/08/2024


// This program plays Rock-Paper-Scissors with the user.

#include <iostream> // Header file allowing to use input/output objects.
#include <ctime>    // Header file allowing to access time.
#include <cstdlib>  // Header file allowing to use the random function.
using namespace std;    // Use standard namespace.

// Function prototypes.
int randObject();
int getInput();
int analyzeChoice(int, int);
void displayWinner(int, int, int);
bool anotherRound();

int main()  // Main function is the staring point of the program execution.
{
    // Variables to store user and program's choices for the object, and the determined winner.
    int iUserChoice, iProgramChoice, iWinnerChoice = 0;

    // Seed the random number generator.
    unsigned seed = time(0);
    srand(seed);

    // Game loop.
    do
    {
        iWinnerChoice = 0; // Reset the winner choice before startng a new round.
        
        // Generate random choices for the object for the computer choice.
        iProgramChoice = randObject();

        // Get user's choice from the input.
        iUserChoice = getInput();

        // Quit the program if the user chose to.
        if (iUserChoice == 4)
        {
            cout << "Thanks for playing!" << endl;
            break;
        }

        iWinnerChoice = analyzeChoice(iUserChoice, iProgramChoice); // Determine the winner using the analyzing function.
        displayWinner(iWinnerChoice, iUserChoice, iProgramChoice);  // Display the winner.
        
    } while (iWinnerChoice == 0 || anotherRound()); // Test if it's a tie or if the user wants to play another round.

    return 0;   // Return 0 to indicate successful completion of the program.
}

// Function that generates a random number for the computer's object choice.
int randObject()
{
    const int MAX = 3, MIN = 1; // Initialize mimimum and maximum values for generating one of the 3 object choices.
    int iRandNum;   // Declare a variable that holds the random number.

    iRandNum = rand() % (MAX - MIN + 1) + MIN;  // Generate a random number.
    return iRandNum;    // The function returns the random number.
}

// Function to get user's input.
int getInput()
{
    int iUserInput;

    cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors, or 4 to quit): ";
    cin >> iUserInput;

    // Validate user's input.
    while (iUserInput != 1 && iUserInput != 2 && iUserInput != 3 && iUserInput != 4)
    {
        cout << "Invalid choice. Please, enter 1 for Rock, 2 for Paper, 3 for Scissors, or 4 to quit: ";
        cin >> iUserInput;
    }

    return iUserInput;    // The function returns the validated user's choice.
}

// Function that analyzes the user's choice and the computer's choice to determine the winner.
int analyzeChoice(int iHumanChoice, int iCompChoice)    // The function accepts the user's and computer's choice to determine the winner.
{
    int iWinner;    // Variable that holds the winner number, 1 for user, 2 for computer, 3 for a tie.

    switch(iHumanChoice)    // Check the user's choice.
    {
        case 1: // User picked rock.
            if (iCompChoice == 2)   // Computer pciked paper.
                iWinner = 2;    // Computer wins.
            else if (iCompChoice == 3)  // Computer pciked scissors.
                iWinner = 1;    // User wins.
            else if (iCompChoice == 1)  // Computer pciked rock.
                iWinner = 0;    // Tie.
            break;
        case 2: // User pciked paper.
            if (iCompChoice == 1)   // Computer pciked rock.
                iWinner = 1;    // User wins.
            else if (iCompChoice == 3)  // Computer pciked scissors.
                iWinner = 2;    // Computer wins.
            else if (iCompChoice == 2)  // Computer pciked paper.
                iWinner = 0;    // Tie.
            break;
        case 3: // User picked scissors.
            if (iCompChoice == 1)   // Computer pciked rock.
                iWinner = 2;    // Computer wins.
            else if (iCompChoice == 2)  // Computer pciked paper.
                iWinner = 1;    // User wins.
            else if (iCompChoice == 3)  // Computer pciked scissors.
                iWinner = 0;    // Tie.
            break;
        default:    // None of the cases above match the user's choice.
            cout << "Invalid object choice. Please enter 1, 2, or 3." << endl;
            return -1;  // Return -1 for an error in the user's choice.
    }

    return iWinner; // The fucntion returns the winner number.
}

// Function that displays the winner based on the user's choice and the computer's choice.
void displayWinner(int iWinner, int iHumanChoice, int iCompChoice)  // Accepts the winner number, computer and user choice.
{
    if (iWinner == 1)   // The user wins.
        {
        cout << "You won! ";

        // Display the user's and computer's objects of choice.
        if (iHumanChoice == 1 && iCompChoice == 3)
            cout << "Rock beats scissors!\n";
        else if (iHumanChoice == 2 && iCompChoice == 1)
            cout << "Paper beats rock!\n";
        else if (iHumanChoice == 3 && iCompChoice == 2)
            cout << "Scissors beats paper!\n";
        }
    else if (iWinner == 2)  // Computer wins.
        {
        cout << "Computer won! ";

        // Display the user's and computer's objects of choice.
        if (iHumanChoice == 1 && iCompChoice == 2)
            cout << "Rock is beaten by paper!\n";
        else if (iHumanChoice == 2 && iCompChoice == 3)
            cout << "Paper is beaten by scissors!\n";
        else if (iHumanChoice == 3 && iCompChoice == 1)
            cout << "Scissors is beaten by rock!\n";
        }
    else
        cout << "It's a tie! Starting another round...\n";    // Tie.

    // Print both the user’s and computer’s choices.
    cout << "You chose: " << (iHumanChoice == 1 ? "Rock" : (iHumanChoice == 2 ? "Paper" : "Scissors")) << endl;
    cout << "Computer chose: " << (iCompChoice == 1 ? "Rock" : (iCompChoice == 2 ? "Paper" : "Scissors")) << endl;
}


// Function to set up the conditions for another round.
bool anotherRound() // The function returns true or false.
{
    int iAnotherRound;  // Variable to hold user's choice.

    cout << "Do you want to play another round? (1 for Yes, 2 for No): ";   // Request the user's choice for another round.
    cin >> iAnotherRound;

    // Validate the input.
    while (iAnotherRound!= 1 && iAnotherRound!= 2)
    {
        cout << "Invalid choice. Please, enter 1 for Yes or 2 for No: ";
        cin >> iAnotherRound;
    }

    if (iAnotherRound == 1) // If the user requests another round, return true.
        return true;
    else    // If the user doesn't request another round, return false.
    {
        cout << "Thanks for playing!\n";
        return false;
    }
}
