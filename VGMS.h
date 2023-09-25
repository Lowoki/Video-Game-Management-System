
  // Header file, Creating a video game management system using nested structs, arrays, and multiple files

  #ifndef VGMS_H
  #define VGMS_H

  #include <string>
  using namespace std;

  struct Developer { // Struct 1
    string name;
    string country;
  };

  struct VideoGame { // Struct 2
    int gameID;
    string title;
    string genre;
    string platform;
    int releaseYear;
    Developer developer; //Developer struct as member
  };

  // Functipon prototypes
  // Desc: Adds a new game to the collection via incrementing order
  // Pre: Nothing
  // Post: ID is assigned to the game
  int addGame(VideoGame games[], int& numGames); 
  // Desc: Displays the video games currently added
  // Pre: Nothing
  // Post: Returns the video game list
  void displayGames(VideoGame games[], int& numGames);
  // Desc: Searches for a specific game in the collection 
  // Pre: Searches only via title
  // Post: returns if the game is a match
  void searchGames(VideoGame games[], int& numGames);
  // Desc: Sorts game based on title or ID
  // Pre: Nothing
  // Post: Returns sorted games
  void sortGames(VideoGame games[], int& numGames);
  // Desc: Removes specified game based on ID
  // Pre: Nothing
  // Post: game is removed
  void removeGame(VideoGame games[], int& numGames);

  #endif
