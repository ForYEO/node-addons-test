#include <node.h>

namespace demo {

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void CallbackMethod(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  Local<String> str = args[0]->ToString();
  Local<Function> cb =Local<Function>::Cast(args[1]);
  
  const unsigned argc = 1;
  Local<Value> argv[argc] = { str };
  
  cb->Call(Null(isolate), argc, argv);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "hello", CallbackMethod);
}

NODE_MODULE(addon, init)

} 
