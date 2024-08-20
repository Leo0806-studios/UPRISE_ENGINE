#include "C:/Users/leo08/source/repos/UPRISE_ENGINE/UPRISE_ENGINE/pch.h"
#include "Header/CORE/C_BEHAVIOUR.h"


//	static std::vector<Behaviour*> tester;
//template <class _Ty, class... _Types>
//static std::vector<_Ty> types;

std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::behaviours;
std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::AWAKES;
std::vector<std::shared_ptr<CORE::Behaviour>> CORE::Behaviour::Starts;
CORE::Behaviour::Behaviour():ToBeRemoved(false) {  }
CORE::Behaviour::Behaviour(int remove):ToBeRemoved(true) {  }

 CORE::Behaviour::Behaviour(GameObject* oobj, std::shared_ptr<CORE::Behaviour> trans)
 {
	TrPr(ctx, __func__)
	 Game_Object = oobj;
	 transf = trans;
	 TrPrE(ctx);
 }

 void CORE::Behaviour::updateAll() {
	//std::cout << behaviours.size() << "\n";
	 TrPr(ctx, __func__)
		 //Log << "test HotReload";
		 int i = behaviours.size() - 1;
	 for (; i >= 0; i--) {
		if (behaviours[i]->ToBeRemoved == false) {
			behaviours[i]->Update();

		}
		else {
			behaviours.erase(behaviours.begin() + i);
		}

	}
	TrPrE(ctx);
}

 void CORE::Behaviour::updateAllAWAKE() {
	TrPr(ctx, __func__)
	for (int i = AWAKES.size() - 1; i >= 0; i--) {

		AWAKES[i]->Awake();
		AWAKES.erase(AWAKES.begin() + i);

	}
	TrPrE(ctx);

}

 void CORE::Behaviour::updateAllSTART() {
	TrPr(ctx, __func__)
	for (int i = Starts.size() - 1; i >= 0; i--) {

		Starts[i]->Start();
		Starts.erase(Starts.begin() + i);

	}
	TrPrE(ctx);
}

 using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;
 std::shared_ptr<std::map<std::string, CreatorFunc>> factT::creators;
 std::map<std::string, CreatorFunc> factT::creatorS;
 //using  CreatorFunc = std::function<std::shared_ptr<CORE::Behaviour>()>;
