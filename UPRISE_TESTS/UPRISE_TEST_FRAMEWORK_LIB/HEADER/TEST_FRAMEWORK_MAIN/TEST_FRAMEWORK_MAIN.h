#pragma once
#ifndef UE_TEST_FRAMEWORK_MAIN_
#define UE_TEST_FRAMEWORK_MAIN_
#include <assert.h>
import std;
struct RegisterdTestObj;
struct Summary {
    unsigned long long Fails = 0;
    unsigned long long Succseses = 0;
    std::vector<const char*> FailedTests;
};
struct Testinfo {
    const char* testname{ nullptr };
    const char* type{ nullptr };
    const char* TestFile{ nullptr };
    size_t Line{ 0 };
};
struct RegisterdTestObj {
    void(*TestFunctionLambda)(void) { nullptr };
    Testinfo info{};
    void operator()(void) {
        if (TestFunctionLambda) {
            TestFunctionLambda();
            return void();
        }
        throw std::runtime_error("TestunctionLambd is nullptr");
    }
    std::string Testinfo()const {
        std::string ret("Testname is: ");
        ret += info.testname;
        ret += "\n";

        ret += " returntype is: ";
        ret+=info.type;
        ret += "\n";
        ret += " in file: ";
        ret += info.TestFile;
        ret += "\n";
        ret += " at line: ";
        ret += std::to_string(info.Line);
        ret += "\n"; 

        return ret;
    }
};
struct Global {
    static std::unordered_map<std::string, Summary>& Summaries_Obj() {
        static std::unordered_map<std::string, Summary> Map;
        return Map;
    }
    static std::vector<RegisterdTestObj>& RegisterdTests_OBJ() {
        static std::vector<RegisterdTestObj> vector;
        return vector;
    }
    static void addToRegisterdTests(RegisterdTestObj obj) {
        RegisterdTests_OBJ().push_back(obj);
    }
#pragma warning(disable:4514)

    static void ExecuteTests(){
        std::string lastTestFile = "";
        for (size_t i = RegisterdTests_OBJ().size(); i > 0; i--) {
            try {
                if (i == 0 || i-1 >= RegisterdTests_OBJ().size()) {
                    throw std::runtime_error("Index out of bounds");
                }
                if (lastTestFile != std::string(RegisterdTests_OBJ()[i - 1].info.TestFile)) {
                    lastTestFile = RegisterdTests_OBJ()[i - 1].info.TestFile;
                    std::cout << "\033[33mRunning tests in file: " << lastTestFile << "\033[0m\n";
                    Summaries_Obj()[lastTestFile];
                }
                try {

                    try{
                        RegisterdTests_OBJ()[i - 1].operator()();
                        std::cout << RegisterdTests_OBJ()[i - 1].Testinfo();
                        std::cout << "\033[32mtest Succsesfull" << " test id: " << std::to_string(i - 1) << "\033[0m\n";
                    }
                    catch (Testinfo info) {
                        std::cout << "\033[31mtest faild!" << " test id: " << std::to_string(i - 1) << "\n message: " << info.testname << "\n file: "<<info.TestFile<<"\n line: "<<info.Line << "\033[0m\n";
                    }
                    catch (std::exception eeee) {
                        std::cout << "\033[31mtest faild!" << " test id: " << std::to_string(i - 1) << "message: " << eeee.what() << "\033[0m\n";
                    }

                }
                catch (std::runtime_error ee) {
                    std::cout << "\033[31mtest invalid\033[0m\n";
                }
            }
            catch (std::runtime_error e) {
                std::cout << e.what() << '\n';
            }
    }
    }
};

template<int i,const char* file,const char* Name,const  char* Type,size_t line> 
struct InternalTestRegisterObj {
    using TestFunclambd = decltype([](void) {});
    InternalTestRegisterObj(void (*TestFuncLambda)(void)) {
        RegisterdTestObj obj;
        obj.TestFunctionLambda = TestFuncLambda;
        obj.info = Testinfo(Name,Type,file,line);
        Global::addToRegisterdTests(obj);
    }


};


#ifndef DONTINCLUDEMACROS

#define _TEST(Name,diff)\
void Name(void); \
namespace Name##diff{\
constexpr const char FILENAME[sizeof(__FILE__)]=__FILE__;\
constexpr const char TEST_NAME[sizeof(# Name)]=# Name;\
constexpr const char Type[sizeof("not implemented")]="not implemented";\
InternalTestRegisterObj<__LINE__,FILENAME,TEST_NAME,Type,__LINE__> RegisterTest= Name;\
}\
void Name(void)
#define TEST(Name) _TEST(Name,__COUNTER__)
#endif


#define ASSERT_CONDITION(condition) if(!(condition)){\
throw Testinfo(__FUNCTION__,"not implemented",__FILE__,static_cast<size_t>(__LINE__));\
}

#define ASSERT_FLOAT_EQ(a,b,epsilon) ASSERT_CONDITION(std::abs(a-(b))<epsilon)
//throw std::runtime_error("assertion failed at line: "+std::to_string(__LINE__)+" failed assertion: "+# condition+"  File: "+ __FILE__);\
//}
#define ASSERT_EXCEPTION(ThingToTry, Expected) try{\
ThingToTry; \
}\
catch(Expected e){\
return void();\
}\
catch(std::exception& e){\
throw std::runtime_error("Expected exception of type: "+std::string( #Expected)+" but got a different exception deriving from std::exception. type:"+ typeid(e).name()+" at line: "+std::to_string(__LINE__)+" FIle: "+__FILE__);\
return void();\
}\
catch(...){\
throw std::runtime_error("Expected exception of type: "+ std::string(#Expected) +" but got a different exception");\
return void();\
}\
throw std::runtime_error("Expected exception of type: "+std::string(#Expected)+" but got no exception at line: "+std::to_string(__LINE__)+" File: "+__FILE__);
#endif // !UE_TEST_FRAMEWORK_MAIN_
