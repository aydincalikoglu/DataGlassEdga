#include <iostream>
#include <string>
#include "lib/Game.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

  Game newGame;

  do {
    newGame.play();
  } while(newGame.wantToPlayAgain());

  return 0;

}
