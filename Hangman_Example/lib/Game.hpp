#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>
#include <string>
#include "SecretPhrase.hpp"
#include "Hangman.hpp"

class Game {
  public:
    Game();
    ~Game();
    void play();
    void updateBoard();
    void parsePlayerGuess(char guess);
    void displayResults();
    void setPlayerSecretPhrase();

    char getPlayerGuess();

    bool isGameOver();
    bool wantToPlayAgain();

    static std::string getPlayerAnswer(std::string prompt_msg, std::string error_msg);

  private:
    SecretPhrase *m_secretPhrase;
    Hangman *m_hangman;

};

#endif
