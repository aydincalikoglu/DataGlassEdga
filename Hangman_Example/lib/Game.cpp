
#include "Game.hpp"
using namespace std;

Game::Game() : m_secretPhrase(0), m_hangman(0) {
  m_secretPhrase = new SecretPhrase();
  m_hangman      = new Hangman();
}

Game::~Game() {
  delete m_secretPhrase;
  delete m_hangman;
}

void Game::play() {

  this -> setPlayerSecretPhrase();
  this -> updateBoard();

  do {
    this -> parsePlayerGuess(this -> getPlayerGuess());
    this -> updateBoard();
  } while(!this -> isGameOver());

  this -> displayResults();

}

void Game::setPlayerSecretPhrase(){
  string response, prompt_msg, error_msg;
  prompt_msg = "Enter your secret phrase: ";
  error_msg  = "Input error! Please try again.";
  response   = Game::getPlayerAnswer(prompt_msg, error_msg);
  m_secretPhrase -> setSecret(response);
}

void Game::displayResults() {
  string msg = (m_hangman -> getStatus() > 0) ? "You got it! The phrase was: " : "You did not get it... The phrase was: ";
  cout << msg << m_secretPhrase -> getSecret() << endl;
}

bool Game::isGameOver() {
  return m_hangman -> getStatus() == 0 || !m_secretPhrase -> hiddenPhraseHasDash();
}

void Game::parsePlayerGuess(char guess) {
  bool found = false;

  string hidden, secret;
  hidden = m_secretPhrase -> getHidden();
  secret = m_secretPhrase -> getSecret();

  for (int i = 0; i < secret.size(); i++) {
    if (tolower(secret[i]) == guess) {
      hidden[i] = secret[i];
      found = true;
    }
  }

  m_secretPhrase -> updateHiddenPhrase(hidden);

  if (!found) {
    int new_status = m_hangman -> getStatus() - 1;
    m_hangman->updateStatus(new_status);
  }
}

void Game::updateBoard() {
  cout << m_hangman -> draw(m_hangman -> getStatus()) << endl;
  cout << "Secret phrase: " << m_secretPhrase -> getHidden() << endl << endl;
}

char Game::getPlayerGuess() {
  string response, prompt_msg, error_msg;
  prompt_msg = "Please input your guess: ";
  error_msg  = "Input error! Please try again.";
  response   = Game::getPlayerAnswer(prompt_msg, error_msg);
  return response[0];
}

bool Game::wantToPlayAgain() {
  string response, prompt_msg, error_msg;
  prompt_msg = "Would you like to play again? (y/n) ";
  error_msg  = "Input error! Please try again.";
  response   = Game::getPlayerAnswer(prompt_msg, error_msg);
  return response[0] == 'y';
}

string Game::getPlayerAnswer(string prompt, string error) {
  string input;
  bool failure;

  do {

    failure = false;
    cout << prompt;
    cin >> input;

    if (cin.fail()) {
      cin.clear();
      cout << error << endl;
      failure = true;
    } else {

      // Loop on input string to check if all char are valids (and force downcase)
      for (int i = 0; i < input.size(); i++) {
        if (isalpha(input[i])) {
          input[i] = tolower(input[i]);
        } else {
          cout << error << endl;
          failure = true;
        }
      }
    }

  } while(failure);

  return input;
}
