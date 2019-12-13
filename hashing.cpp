#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>

extern "C" {
    #include "scrypt.h"
}

using namespace node;
using namespace v8;

// NODE_MAJOR_VERSION >=13

void scrypt(const FunctionCallbackInfo<Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    if (args.Length() < 4) {
        do {
            isolate->ThrowException(Exception::Error(String::NewFromUtf8(isolate, "You must provide four argument.").ToLocalChecked()));
            return;
        } while (0);
    }

	Local<Context> context = isolate->GetCurrentContext();

    Local<Object> target = args[0]->ToObject(context).ToLocalChecked();
    if(!Buffer::HasInstance(target)) {
        do {
            isolate->ThrowException(Exception::Error(String::NewFromUtf8(isolate, "Argument should be a buffer object.").ToLocalChecked()));
            return;
        } while (0);
    }

    char * input = Buffer::Data(target);
    char output[32];
    uint32_t input_len = Buffer::Length(target);

    unsigned int nValue = args[1]->Uint32Value(context).ToChecked();
    unsigned int rValue = args[2]->Uint32Value(context).ToChecked();
    unsigned int pValue = args[3]->Uint32Value(context).ToChecked();    

    scrypt_256(input, output, nValue, rValue, pValue, input_len);

    args.GetReturnValue().Set(Buffer::Copy(isolate, output, 32).ToLocalChecked());
}



void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "hash", scrypt);
}


NODE_MODULE(hashing, init)
