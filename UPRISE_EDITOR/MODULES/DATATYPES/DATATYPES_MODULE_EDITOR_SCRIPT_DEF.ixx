// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
module;
#include "Windows.h"
export module DATATYPES_MODULE_MAIN_DEF:EDITOR_SCRIPT;
import std;
import MISC;
//#include <wrl.h>



export namespace EDITOR {
		struct Ref_Base {

		};
		struct Val_Type {
			enum ot { ot_int, ot_double, ot_char, ot_String, ot_long, ot_short, ot_float } obj;
			union {
				int i;
				double d;
				char ch;
				std::string str;
				long l;
				short sh;
				float f;

			};
			void Set(int i) { this->i = i; this->obj = ot_int; }
			void Set(double d) { this->d = d; this->obj = ot_double; }
			void Set(char ch) { this->ch = ch; this->obj = ot_char; }
			void Set(std::string str) { this->str = str; this->obj = ot_String; }
			void Set(long l) { this->l = l; this->obj = ot_long; }
			void Set(short sh) { this->sh = sh; this->obj = ot_short; }
			void Set(float f) { this->f = f; this->obj = ot_float; }
			~Val_Type() {
				switch (obj) {
				case ot_int: {

				}
				case 1: {

				}
				case 2: {

				}
				case 3: {

				}
				case 4: {

				}
				case 5: {

				}
				case 6: {

				}
				}
			}

		};
		struct Serialized_Ref {
		public:
			template<typename _Tn, class _Obj>
			Serialized_Ref(void* ptr) {
				Obj_Type_info = typeid(_Tn);
				PtrToObject = ptr;
			}
			Serialized_Ref(const Serialized_Ref& other) :Obj_Type_info(other.Obj_Type_info) {
				PtrToObject = other.PtrToObject;

				//Obj_Type_info = other.Obj_Type_info;
			}
			std::string Name;
			UUID Obj_UUID;

			std::type_info& Obj_Type_info;
			void* PtrToObject;
			size_t Size;


			//template<typename _Tn, class _Obj>
			//static Serialized_Ref Create_Serialized_Ref(void* ptr) {
			//	return Serialized_Ref<_Tn>(ptr);
			//}


		};
		struct Serialized_Var {
		public:
			Serialized_Var(const Serialized_Var& other) {
				memcpy(this, &other, sizeof(other));

			}
			Serialized_Var operator=(const Serialized_Var& other) {

				return other;
			}
			std::string Name;
			int activeType;
			void Set(Serialized_Ref& ref) {
				activeType = 0;
				Serialized_Ref tmp(ref);
				memcpy(&this->Ref_Type, &tmp, sizeof(tmp));
				
			}
			void Set(Val_Type val) {
				activeType = 1;
				memcpy(&this->Val_type, &val, sizeof(val));

			}
			union {
				Serialized_Ref Ref_Type;
				Val_Type Val_type;


			};
			~Serialized_Var() {}

		};
		class Serialized_Script {

		public:
			bool FAIL;
			std::string Name;
			std::vector<Serialized_Var> Vars;
			std::string Get_Error()
			{
				return std::string();
			}

		};
	}
