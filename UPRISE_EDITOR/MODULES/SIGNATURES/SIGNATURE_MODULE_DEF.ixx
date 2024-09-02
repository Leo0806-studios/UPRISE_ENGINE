export module SIGNATURE_MODULE_DEF;
import std;
export{
	namespace EDITOR {
		class FuncSig {
		public:
			FuncSig(std::string name, std::string Namespace_class_List, std::string Return_Type, std::string Parameter, std::string Qualifier, std::string Qualifier1, std::string Visibility, std::string FunctType) :name(name), Namespace_class_List(Namespace_class_List), Return_Type(Return_Type), Parameter(Parameter), Qualifier(Qualifier), Qualifier1(Qualifier1), Visibility(Visibility), FunctType(FunctType) {}
			std::string name;
			std::string Namespace_class_List;
			std::string Return_Type;
			std::string Parameter;
			std::string Qualifier;
			std::string Qualifier1;

			std::string Visibility;
			std::string FunctType;


		};
		class VarSig {
		public:
			VarSig(std::string Name, std::string Type, std::string Namespace_class_List, std::string  Inti_Val, std::string Visibility, std::string FunctType, std::string Type_Mod) :Name(Name), Namespace_class_List(Namespace_class_List), Type(Type), Inti_Val(Inti_Val), Visibility(Visibility), FunctType(FunctType), Type_Mod(Type_Mod) {}
			std::string Name;
			std::string Namespace_class_List;
			std::string Type;
			std::string  Inti_Val;
			std::string Visibility;
			std::string FunctType;
			std::string Type_Mod;
		};
	};
}