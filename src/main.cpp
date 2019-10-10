#include <napi.h>
#include "morfeusz2.h"

using namespace morfeusz;

Morfeusz *m=Morfeusz::createInstance();

Napi::String Version(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string v =  m->getVersion();
  return Napi::String::New(env, v);
}

Napi::String Copyright(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string v =  m->getCopyright();
  return Napi::String::New(env, v);
}

Napi::String DictCopyright(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  std::string v =  m->getDictCopyright();
  return Napi::String::New(env, v);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "version"), Napi::Function::New(env, Version));
  exports.Set(Napi::String::New(env, "copyright"), Napi::Function::New(env, Copyright));
  exports.Set(Napi::String::New(env, "dictCopyright"), Napi::Function::New(env, DictCopyright));
  return exports;
}

NODE_API_MODULE(morfeusz2, Init)
