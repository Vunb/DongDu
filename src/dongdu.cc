/**
 * vntk/dongdu addon - written by Vunb, @Delamy 2016.
 * Date: 07/09/2016
 */

#include <nan.h>
#include <iostream>
#include <fstream>
//#include <unistd.h>

#include "Machine.h"
#include "FeaturesSelection.h"

using namespace std;    

void Segment(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  if (info.Length() < 1) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsString()) {
    Nan::ThrowTypeError("Wrong type of arguments");
    return;
  }

  v8::String::Utf8Value arg0(info[0]->ToString());
  std::string input = std::string(*arg0);
  
    Machine predictor(3, "", PREDICT);
    if (!predictor.load()) {
        cout << "Failed to load data from dongdu.model and dongdu.map" << endl;
        return;
    }
    
    cout << "Start segmenting ..." << endl;
    std::string output = predictor.segment(input);
	cout << "End segmenting." << endl;

  v8::Local<v8::String> result = v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), output.c_str());

  info.GetReturnValue().Set(result);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("segment").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Segment)->GetFunction());
}

NODE_MODULE(dongdu, Init)
