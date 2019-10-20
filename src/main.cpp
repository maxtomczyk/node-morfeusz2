#include "../headers/main.h"

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

  std::vector<morfeusz::MorphInterpretation> results;
  MorfeuszWrapper::getInstance().setPraet("composite");
  MorfeuszWrapper::getInstance().setWhitespaceHandling(morfeusz::KEEP_WHITESPACES);
  MorfeuszWrapper::getInstance().analyze(v, results);
  // const morfeusz::IdResolver & idr = MorfeuszWrapper::getInstance().getResolver();
  int resultsLen = results.size();
  Napi::Array arr = Napi::Array::New(env, resultsLen);
  int i = 0;
  while(i<resultsLen) {
    morfeusz::MorphInterpretation inter = results[i];
    Napi::Object obj = Napi::Object::New(env);
    obj.Set("startNode", inter.startNode);
    obj.Set("endNode", inter.endNode);
    obj.Set("orth", inter.orth);
    obj.Set("lemma", inter.lemma);
    obj.Set("tagId", inter.getTag(*MorfeuszWrapper::getInstance().getMorfeusz()));
    obj.Set("name", inter.getName(*MorfeuszWrapper::getInstance().getMorfeusz()));
    obj.Set("labels", inter.getLabelsAsString(*MorfeuszWrapper::getInstance().getMorfeusz()));
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
