#include "Hangman.hpp"
using namespace std;

Hangman::Hangman() : m_status(6) {}

Hangman::~Hangman() {}

int Hangman::getStatus() {
  return m_status;
}

void Hangman::updateStatus(int newValue) {
  m_status = newValue;
}

string Hangman::draw(int status) {

  string hangman_draw;

  switch(status) {

    case 0: {
      hangman_draw =  " +---+\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |   o\n";
      hangman_draw += " |  /|\\\n";
      hangman_draw += " |  / \\\n";
      hangman_draw += " |\n";
      hangman_draw += "-+-\n\n";
    }
    break;

    case 1: {
      hangman_draw =  " +---+\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |   o\n";
      hangman_draw += " |  /|\\\n";
      hangman_draw += " |  /\n";
      hangman_draw += " |\n";
      hangman_draw += "-+-\n\n";
    }
    break;

    case 2: {
      hangman_draw =  " +---+\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |   o\n";
      hangman_draw += " |  /|\\\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += "-+-\n\n";
    }
    break;

    case 3: {
      hangman_draw =  " +---+\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |   o\n";
      hangman_draw += " |  /|\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += "-+-\n\n";
    }
    break;

    case 4: {
      hangman_draw =  " +---+\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |   o\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += "-+-\n\n";
    }
    break;

    case 5: {
      hangman_draw =  " +---+\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |   o\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += "-+-\n\n";
    }
    break;

    case 6: {
      hangman_draw =  " +---+\n";
      hangman_draw += " |   |\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += " |\n";
      hangman_draw += "-+-\n\n";
    }
    break;

    default:
       break;
  }

  return hangman_draw;

}
