#ifndef DEF_SECRETPHRASE
#define DEF_SECRETPHRASE

#include <iostream>
#include <string>

class SecretPhrase {
  public:
    SecretPhrase();
    ~SecretPhrase();

    std::string getSecret();
    void setSecret(std::string phrase);
    void updateHiddenPhrase(std::string newValue);
    bool hiddenPhraseHasDash();
    std::string getHidden();
    std::string hidePhrase(std::string toHide);

  protected:
    std::string m_secretPhrase;
    std::string m_hiddenPhrase;

};

#endif
