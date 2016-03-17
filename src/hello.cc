//hello.cc
#include <node.h>

namespace demo {
	
	using v8::Exception;
	using v8::Number;
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void Method(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Cheesey Cheese sticks!!"));
	}

	void Giggles(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "You done has the giggles!"));
	}

	void Add(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();

		//check for correct number of arguments 2
		if (args.Length() < 2) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Wrong number of arguments!")));
				return;
		}

		//check to make sure arguments are correct type
		if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Wrong kind of arguments!")));
			return;
		}

		//Perform operation
		double value = args[0]->NumberValue() + args[1]->NumberValue();
		Local<Number> num = Number::New(isolate, value);

		args.GetReturnValue().Set(num);
	}

	void init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "hello", Method);
		NODE_SET_METHOD(exports, "giveMeGiggles", Giggles);
		NODE_SET_METHOD(exports, "add", Add);
	}

	NODE_MODULE(addon, init)


}