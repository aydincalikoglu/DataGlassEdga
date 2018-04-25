
#include "Game.hpp"
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

Game::Game() : m_secretPhrase(0), m_hangman(0) {
  m_secretPhrase = new SecretPhrase();
  m_hangman      = new Hangman();
  turn  = false;
  playerFirstScore = 0;
  playerSecondScore = 0;

}

Game::~Game() {
  delete m_secretPhrase;
  delete m_hangman;
}

void Game::play(){

  secretWord = generateRandomWord();
  cout << secretWord << endl;
  m_hangman->resetStatus();

  turn  = false;
  playerFirstScore = 0;
  playerSecondScore = 0;
  


  this -> setPlayerSecretPhrase();
  this -> updateBoard();
  
  do {
  	if(turn){
  		cout << "Player 2 turn :"<<endl;
  		turn = false;
  	}
  	else{
  		cout << "Player 1 turn :" <<endl;
  		turn = true;
  	}
    this -> parsePlayerGuess(this -> getPlayerGuess());
    this -> updateBoard();
  } while(!this -> isGameOver());

  this -> displayResults();
}

void Game::setPlayerSecretPhrase(){
  string response, prompt_msg, error_msg;
  prompt_msg = "Enter your secret phrase: ";
  error_msg  = "Input error! Please try again.";
  response   = secretWord;
  m_secretPhrase -> setSecret(response);
}

void Game::displayResults() {
  //string msg = (m_hangman -> getStatus() > 0) ? "You got it! The phrase was: " : "You did not get it... The phrase was: ";
  if(turn){
    string msg = (m_hangman -> getStatus() > 0) ? "Player1 got it!  The phrase was: " : "You did not get it... The phrase was: ";
    cout <<msg << m_secretPhrase -> getSecret() <<"  Your score: " << playerFirstScore<< endl;
  }
  else{
    string msg = (m_hangman -> getStatus() > 0) ? "Player2 got it! The phrase was: " : "You did not get it... The phrase was: ";
    cout << msg << m_secretPhrase -> getSecret()<<"  Your score: " << playerSecondScore << endl;
  }
  
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
      if(turn)
        playerFirstScore+=10;
      else
        playerSecondScore+=10;
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
string Game::generateRandomWord(){

/**	string input;
	int random = 0 ;
	srand (time(NULL));
	ifstream infile("dictionary.txt");
	int counter = 0 ;
	random = rand()%8;
	while (getline(infile, input)){
    	if(counter == random)
    		return input;
    	counter++;
	}
	return input;*/
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);

    /* using nano-seconds instead of seconds */
  srand((time_t)ts.tv_nsec);
	
  int random = 0 ;
	random = rand()%7;

	    ifstream file;
    file.open ("dictionary.txt");
    if (!file.is_open()) return "";
    int countt = 0;
    string word;
    while (file >> word)
    {
    	if(countt == random)
			return word;
        ++countt;
    }
}
void Game::displayWinner(){

  cout<< "You win the game and your score is "<<playerFirstScore<< endl;
}
void Game::displayLoser(){
  cout << "You lose the game and your score is "<< playerSecondScore<<" try again !"<<endl;
}

