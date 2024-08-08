// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Header/DEBUG/DEBUG_LOGGER.h"
#include "DLL-ENGINE-LINK.h"
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
extern "C" {
	 class  __declspec(dllexport)   test  {
	public:
		int i=1;
		test() {
			i = i;
			std::cout << "mem test" << (int)((long)(void*)(this)+4)<<"\n";
			std::cout << "mem adr of this " << this << " alingof i " << (((int)&(this->i)) - (int)(this)) << "i is " << i << "mem addr of i " << &(this->i) << "\n";
		}
		//std::shared_ptr<test> der;
		static void Print(test* in) {
			//in->der->prnt();
		}
		virtual void prnt() {
			
		}
	};

	class __declspec(dllexport) Dtest :public test {
	public:
		void prnt()override {
			std::cout << "hello from derived. i is "<<i;
		}
	};
	
}

extern "C" {
	
	std::shared_ptr<DATALINK> DATA;
	__declspec(dllexport)void _PRINT(test* in) {
		test::Print(in);
	}
		   __declspec(dllexport)void INITIALIZE() {
			    DATA = std::make_shared<DATALINK>();
		}
		   __declspec(dllexport)test* _CREATE() {
			   auto a = new test();
			   std::cout << "mem adr of this " << a << " alingof i " << (((int)&(a->i)) - (int)(a)) << "i is " << a->i << "mem addr of i " << &(a->i) << "\n";
			  // a->der = std::make_shared< Dtest>();
			   return a;
		   }

	

}
extern "C" {
	__declspec(dllexport) std::shared_ptr<DATALINK> GetDatabase()
	{
		return DATA;
	}
	__declspec(dllexport) void SetDatabase(std::shared_ptr<DATALINK> in) {
		DATA = in;
	}

}
extern "C" {

}

