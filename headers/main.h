#include <napi.h>
#include "morfeusz2.h"
#include <iostream>
#include <vector>

using namespace morfeusz;

class MorfeuszWrapper {
  private:
    Morfeusz *m;
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
    ResultsIterator* analyze(std::string text);
    void analyze(std::string text, std::vector<MorphInterpretation>& r);
};