  // Int main file, creating a video game management system using nested structs, arrays, and multiple files

  #include "VGMS.h"

  #include <iostream>
  #include <string>
  #include <limits> // for user input error validation (numeric_limits)

  using namespace std;

  const int maxGames = 100; // Max games allowed in the array
 
  int main() {

    VideoGame games[maxGames]; // creates an array that is maxGames size
    int numGames = 0;  // Intilizes the variable to 0 to indicate the array is empty

    cout << "Welcome to Mr. Whiskers' Video Game Collection Management System! Please use responsibly!\n\n"; // greeting

    int choice;
    do {
        cout << "Please select an option:" << endl;
        cout << "1. Add a game" << endl;
        cout << "2. Display all games" << endl;
        cout << "3. Search for a game" << endl;
        cout << "4. Sort games" << endl;
        cout << "5. Quit" << endl;
        cout << "6. Remove game" << endl;
        cin >> choice;
        cin.ignore(); // ignore the newline character left by cin

        switch (choice) {
            case 1:
              {
                int newGameID = addGame(games, numGames);
                if (newGameID != -1) {
                  cout << "Game added with ID: " << newGameID << endl;
                }
                break;
              }
            case 2:
                displayGames(games, numGames);
                break;
            case 3:
                searchGames(games, numGames);
                break;
            case 4:
                sortGames(games, numGames);
                break;
            case 5:
                cout << "\nThank you for using Mr. Whiskers Video Game Collection Mangament System! Goodbye!" << endl;
                break;
            case 6:
               removeGame(games, numGames);
               break; 
             default:
        if (cin.fail()) { // check if input was not a number
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear(); // clear cin error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore remaining characters in input stream
        } else { // input was a number outside of the range 1-6
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
        }
        }

        cout << endl;
    } while (choice != 5);

    return 0;
  }
