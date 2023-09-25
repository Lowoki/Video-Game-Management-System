  // Function Definition file, Creating a video game management system using nested structs, arrays, and multiple files
 
  #include "VGMS.h"

  #include <iostream>
  #include <string>
  #include <limits> // numeric_limits

  using namespace std;

  // Max games allowed in the array  
  const int maxGames = 100;

  // Function 1
  int addGame(VideoGame games[], int& numGames) {
    if (numGames == maxGames) { // Check if array is already full
        cout << "Maximum number of games reached." << endl;
        return -1;
    }

    VideoGame newGame;

    // Get input for the new game
    cout << "Enter title: ";
    getline(cin, newGame.title);

    cout << "Enter genre: ";
    getline(cin, newGame.genre);

    cout << "Enter platform: ";
    getline(cin, newGame.platform);

    int releaseYear;
    while (true) {
        cout << "Enter release year: ";
        cin >> releaseYear;
        if (cin.fail()) { // error validation if letter inputted
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            newGame.releaseYear = releaseYear;
            cin.ignore();
            break;
        }
    }

    cout << "Enter developer name: ";
    getline(cin, newGame.developer.name);

    cout << "Enter developer country: ";
    getline(cin, newGame.developer.country);

    // Check if the game already exists in the collection
    for (int i = 0; i < numGames; i++) {
        if (games[i].title == newGame.title) {
            cout << "Game with the same title already exists in the collection." << endl;
            return -1;
        }
    }

    // Generate a unique game ID for the new game
    static int nextGameID = 1;
    newGame.gameID = nextGameID++;

    // Add the new game to the end of the array
    games[numGames++] = newGame;

    // Return the ID of the newly added game
    return newGame.gameID;
  }

  // Function 2 
  // Function to display all games in the array
  void displayGames(VideoGame games[], int& numGames) {
    if (numGames == 0) { // Check if array is empty
        cout << "No games to display." << endl;
        return;
    }

    for (int i = 0; i < numGames; i++) {
        cout << "Game ID: " << games[i].gameID << endl;
        cout << "Title: " << games[i].title << endl;
        cout << "Genre: " << games[i].genre << endl;
        cout << "Platform: " << games[i].platform << endl;
        cout << "Release year: " << games[i].releaseYear << endl;
        cout << "Developer name: " << games[i].developer.name << endl;
        cout << "Developer country: " << games[i].developer.country << endl;
        cout << endl;
    }
  }

  // Function 3 
  // Function to search for a game by title
  void searchGames(VideoGame games[], int& numGames) {
    if (numGames == 0) { // Check if array is empty
        cout << "No games to search." << endl;
        return;
    }

    string searchTitle;
    cout << "Enter game title to search for: ";
    getline(cin, searchTitle);

    bool found = false;
    for (int i = 0; i < numGames; i++) {
        if (games[i].title == searchTitle) {
            cout << "Game found:" << endl;
            cout << "Game ID: " << games[i].gameID << endl;
            cout << "Title: " << games[i].title << endl;
            cout << "Genre: " << games[i].genre << endl;
            cout << "Platform: " << games[i].platform << endl;
            cout << "Release year: " << games[i].releaseYear << endl;
            cout << "Developer name: " << games[i].developer.name << endl;
            cout << "Developer country: " << games[i].developer.country << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Game not found." << endl;
    }
  }

  // Funciton 4
  void sortGames(VideoGame games[], int& numGames) {
    if (numGames == 0) { // Check if array is empty
        cout << "No games to sort." << endl;
        return;
    }

    int choice;
    do {
        cout << "Sort by:" << endl;
        cout << "1. Game ID" << endl;
        cout << "2. Game Title" << endl;
        cin >> choice;
        cin.ignore(); // ignore the newline character left by cin

        if (choice != 1 && choice != 2) { // invalid input
            cout << "Invalid input. Please enter 1 or 2." << endl;
        }
    } while (choice != 1 && choice != 2);

    switch (choice) {
        case 1:
            // Sort by Game ID
            for (int i = 0; i < numGames - 1; i++) {
                for (int j = 0; j < numGames - i - 1; j++) {
                    if (games[j].gameID > games[j + 1].gameID) {
                        // swap games
                        VideoGame temp = games[j];
                        games[j] = games[j + 1];
                        games[j + 1] = temp;
                    }
                }
            }
            break;
        case 2:
            // Sort by Game Title
            for (int i = 0; i < numGames - 1; i++) {
                for (int j = 0; j < numGames - i - 1; j++) {
                    if (games[j].title > games[j + 1].title) {
                        // swap games
                        VideoGame temp = games[j];
                        games[j] = games[j + 1];
                        games[j + 1] = temp;
                    }
                }
            }
            break;
    }

    cout << "Games sorted successfully." << endl;
  }
  // Function 5
  void removeGame(VideoGame games[], int& numGames) {
    if (numGames == 0) { // Check if array is empty
        cout << "No games to remove." << endl;
        return;
    }

    int removeID;
    while (true) {
        cout << "Enter the game ID of the game you want to remove: ";
        cin >> removeID;
        if (cin.fail()) { // error validation if letter inputted
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    bool found = false;
    for (int i = 0; i < numGames; i++) {
        if (games[i].gameID == removeID) {
            found = true;
            // Shift all the elements to the right of the removed game one position to the left to fill the gap
            for (int j = i; j < numGames - 1; j++) {
                games[j] = games[j+1];
            }
            numGames--;
            break;
        }
    }

    if (!found) {
        cout << "Game with the specified ID not found." << endl;
    } else {
        cout << "Game with the specified ID removed successfully." << endl;
    }
  }
