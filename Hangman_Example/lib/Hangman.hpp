#ifndef DEF_HANGMAN
#define DEF_HANGMAN

#include <iostream>
#include <string>

class Hangman {
  public:
    Hangman();
    ~Hangman();
    int getStatus();
    void updateStatus(int newValue);
    std::string draw(int status);
    void resetStatus();

  private:
    int m_status;

};

#endif
