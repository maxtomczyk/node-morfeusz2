#include "../headers/main.h"

MorfeuszWrapper::MorfeuszWrapper() {
  m = Morfeusz::createInstance();
}

std::string MorfeuszWrapper::getVersion() {
  return m->getVersion();
}

ResultsIterator* MorfeuszWrapper::analyze(std::string text) {
  return m->analyse(text);
}

void MorfeuszWrapper::analyze(std::string text, std::vector<MorphInterpretation>& r) {
  m->analyse(text, r);
}

//// ==================================================================
//// NODE API CALLBACKS

Napi::String Version(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string v = MorfeuszWrapper::getInstance().getVersion();
  return Napi::String::New(env, v);
}

Napi::String Copyright(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string v = MorfeuszWrapper::getInstance().getVersion();
  return Napi::String::New(env, v);
}

Napi::String DictCopyright(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string v = MorfeuszWrapper::getInstance().getVersion();
  return Napi::String::New(env, v);
}

Napi::Array Analyze(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string v = info[0].ToString();
  std::cout << v << std::endl;
  std::vector<MorphInterpretation> results;
  MorfeuszWrapper::getInstance().analyze(v, results);
  int resultsLen = results.size();
  std::cout << resultsLen << std::endl;

  Napi::Array arr = Napi::Array::New(env, resultsLen);
  int i = 0;
  while(i<resultsLen) {
    MorphInterpretation inter = results[i];
    Napi::Object obj = Napi::Object::New(env);
    obj.Set("startNode", inter.startNode);
    obj.Set("endNode", inter.endNode);
    obj.Set("orth", inter.orth);
    obj.Set("lemma", inter.lemma);
    arr[i] = obj;
    i++;
  }

  return arr;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "version"), Napi::Function::New(env, Version));
  exports.Set(Napi::String::New(env, "copyright"), Napi::Function::New(env, Copyright));
  exports.Set(Napi::String::New(env, "dictCopyright"), Napi::Function::New(env, DictCopyright));
  exports.Set(Napi::String::New(env, "analyze"), Napi::Function::New(env, Analyze));
  return exports;
}

NODE_API_MODULE(morfeusz2, Init)
