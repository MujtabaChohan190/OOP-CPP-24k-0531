/*Q2: Develop a Program that organize digital cricket match where two players, Player 1 and Player 2, are 
competing over 12 balls. The game, named "Cricket Showdown," involves each player taking turns to score runs 
on every ball. The twist is, they have to enter their scores, ranging from 0 to 6, and if a player mistakenly inputs 
a score outside this range, the score won't count, but the ball will still be marked. You should not violate any 
principle of Object-oriented programming. 
1. Create a class “player” consisting of following members with appropriate datatypes: 
  ballScores[12]: denotes an array wherein the scores corresponding to each ball are stored. 
  PlayerName: representing the player name. 
  TotalScore: containing count total score for each player. 
2. Create a class “Game” consisting of following members with appropriate datatypes: 
 playGame(Player& player): each player gets their turn to face the 12  balls. The function prompts the 
player to enter the score for each ball. 
 ValidateScore(): if the score entered is not between 0 and 6 (inclusive), it won't be considered, but the 
ball will still be recorded. 
 findWinner(Player& player1, Player& player2): the winner is determined based on the total scores. 
 displayMatchScoreboard(Player& player1, Player& player2): This function displays the detailed 
summary of the match. In summary, each player's name and their score against each ball should be in 
ascending manner with average score and total score for each player, giving a comprehensive overview 
of their performance.*/

#include <iostream>
#include <iomanip> // For fixed and setprecision
using namespace std;

// Player class
class Player {
private:
    string playerName;
    int ballScores[12]; // Array to store scores of 12 balls
    int totalScore;

public:
    // Constructor
    Player(string name) : playerName(name), totalScore(0) {
        for (int i = 0; i < 12; i++) {
            ballScores[i] = 0; // Initialize scores to zero
        }
    }

    // Function to set the score for a ball
    void setBallScore(int ball, int score) {
        if (score >= 0 && score <= 6) {
            ballScores[ball] = score;
            totalScore += score; // Add to total score
        } else {
            cout << "Invalid score! The ball is counted, but no score is recorded.\n";
        }
    }

    // Getters
    string getPlayerName() const { return playerName; }
    int getTotalScore() const { return totalScore; }
    int getBallScore(int ball) const { return ballScores[ball]; }

    // Function to calculate the average score
    double getAverageScore() const {
        return totalScore / 12.0; // Total score divided by 12 balls
    }
};

// Game class
class Game {
public:
    // Function to handle a player's turn
    void playGame(Player &player) {
        cout << "\n" << player.getPlayerName() << "'s turn begins!\n";

        for (int i = 0; i < 12; i++) {
            int score;
            cout << "Enter score for ball " << (i + 1) << ": ";
            cin >> score;
            player.setBallScore(i, score);
        }
    }

    // Function to determine the winner
    void findWinner(Player &player1, Player &player2) {
        cout << "\n=== MATCH RESULT ===\n";
        if (player1.getTotalScore() > player2.getTotalScore()) {
            cout << player1.getPlayerName() << " wins with " << player1.getTotalScore() << " runs!\n";
        } else if (player2.getTotalScore() > player1.getTotalScore()) {
            cout << player2.getPlayerName() << " wins with " << player2.getTotalScore() << " runs!\n";
        } else {
            cout << "It's a tie! Both players scored " << player1.getTotalScore() << " runs.\n";
        }
    }

    // Function to display the match scoreboard
    void displayMatchScoreboard(Player &player1, Player &player2) {
        cout << "\n=== MATCH SCOREBOARD ===\n";
        cout << "Ball #   " << player1.getPlayerName() << "   " << player2.getPlayerName() << endl;
        
        for (int i = 0; i < 12; i++) {
            cout << (i + 1) << "        " << player1.getBallScore(i) << "        " << player2.getBallScore(i) << endl;
        }

        cout << "\nTotal Score:  " << player1.getTotalScore() << "       " << player2.getTotalScore() << endl;
        cout << "Average Score: " << fixed << setprecision(2) << player1.getAverageScore() << "     " << player2.getAverageScore() << endl;
    }
};

// Main function
int main() {
    cout << "Welcome to Cricket Showdown!\n";
    
    // Taking player names as input
    string name1, name2;
    cout << "Enter Player 1 name: ";
    cin >> name1;
    cout << "Enter Player 2 name: ";
    cin >> name2;

    // Creating Player objects
    Player player1(name1);
    Player player2(name2);
    
    // Creating Game object
    Game cricketGame;

    // Playing the game
    cricketGame.playGame(player1);
    cricketGame.playGame(player2);

    // Displaying scoreboard
    cricketGame.displayMatchScoreboard(player1, player2);

    // Declaring the winner
    cricketGame.findWinner(player1, player2);

    return 0;
}
