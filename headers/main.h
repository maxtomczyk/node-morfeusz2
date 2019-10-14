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
};