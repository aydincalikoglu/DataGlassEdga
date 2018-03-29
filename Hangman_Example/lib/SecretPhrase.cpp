
#include "SecretPhrase.hpp"

using namespace std;

SecretPhrase::SecretPhrase() {}
SecretPhrase::~SecretPhrase() {}

string SecretPhrase::getSecret() {
  return m_secretPhrase;
}

string SecretPhrase::getHidden() {
  return m_hiddenPhrase;
}

void SecretPhrase::setSecret(string secret) {
  m_secretPhrase = secret;
  m_hiddenPhrase = hidePhrase(secret);
}

string SecretPhrase::hidePhrase(string toHide) {
  string hidden = toHide;

  for (int i = 0; i < toHide.size(); i++) {
    hidden[i] = (toHide[i] != ' ') ? '-' : ' ';
  }

  return hidden;
}

bool SecretPhrase::hiddenPhraseHasDash() {
  bool hasDash = false;

  for (int i = 0; i < m_hiddenPhrase.size(); i++) {
    if (m_hiddenPhrase[i] == '-') {
      hasDash = true;
      break;
    }
  }

  return hasDash;
}

void SecretPhrase::updateHiddenPhrase(string newValue) {
  m_hiddenPhrase = newValue;
}
