#include <napi.h>
#include "morfeusz2.h"
#include <iostream>
#include <vector>

class MorfeuszWrapper {
  private:
    morfeusz::Morfeusz *m;
    MorfeuszWrapper();
    MorfeuszWrapper( const MorfeuszWrapper & );

  public:
    static MorfeuszWrapper & getInstance() {
      static MorfeuszWrapper singleton;
      return singleton;
    }

    // methods
    std::string getVersion();
    std::string getCopyright();
    std::string getDictCopyright();
    morfeusz::ResultsIterator* analyze(std::string text);
    void analyze(std::string text, std::vector<morfeusz::MorphInterpretation>& r);

    const morfeusz::IdResolver& getResolver();
    const morfeusz::Morfeusz* getMorfeusz();

    void setAggl(std::string param);
    void setPraet(std::string param);
    void setWhitespaceHandling(morfeusz::WhitespaceHandling param);
};

MorfeuszWrapper::MorfeuszWrapper() {
  m = morfeusz::Morfeusz::createInstance();
}

std::string MorfeuszWrapper::getVersion() {
  return m->getVersion();
}

morfeusz::ResultsIterator* MorfeuszWrapper::analyze(std::string text) {
  return m->analyse(text);
}

void MorfeuszWrapper::analyze(std::string text, std::vector<morfeusz::MorphInterpretation>& r) {
  m->analyse(text, r);
}

const morfeusz::IdResolver& MorfeuszWrapper::getResolver() {
  return m->getIdResolver();
}

const morfeusz::Morfeusz* MorfeuszWrapper::getMorfeusz() {
  return m;
}

void MorfeuszWrapper::setAggl(std::string param) {
  m->setAggl(param);
} 

void MorfeuszWrapper::setPraet(std::string param) {
  m->setPraet(param);
}

void MorfeuszWrapper::setWhitespaceHandling(enum morfeusz::WhitespaceHandling param) {
  m->setWhitespaceHandling(param);
}