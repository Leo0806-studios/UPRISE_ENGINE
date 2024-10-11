#include "BEHAVIOUR/BEHAVIOUR.h"



 std::vector<RefWrapper<CORE::Behaviour,true>> CORE::Behaviour::behaviours;
 std::vector<RefWrapper<CORE::Behaviour,true>> CORE::Behaviour::awakes;
 std::vector<RefWrapper<CORE::Behaviour,true>> CORE::Behaviour::starts;


 UPRISE_CORE_API bool CORE::Behaviour::RemoveFromUpdate()
 {
	 return true;

 }

 UPRISE_CORE_API bool CORE::Behaviour::RemoveFromStart()
 {
	 return true;
 }
 UPRISE_CORE_API bool CORE::Behaviour::RemoveFromAwake()
 {
	 return true;

 }

 /// <summary>
/// updates all Scripts 
/// </summary>
/// <returns>void</returns>
UPRISE_CORE_API void CORE::Behaviour::UpdateAll()
{
	TrPr(ctx, __func__)
		//Log << "test HotReload";
		int i = behaviours.size() - 1;
	for (; i >= 0; i--) {
		
			behaviours[i]->Update();

		


	}

	TrPrE(ctx);
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
UPRISE_CORE_API void CORE::Behaviour::UpdateAllAWAKE()
{
	TrPr(ctx, __func__)
		for (int i = awakes.size() - 1; i >= 0; i--) {

			awakes[i]->Awake();
			awakes.erase(awakes.begin() + i);

		}
	TrPrE(ctx);
}

UPRISE_CORE_API void CORE::Behaviour::UpdateAllSTART()
{
	TrPr(ctx, __func__)
		for (int i = starts.size() - 1; i >= 0; i--) {

			starts[i]->Start();
			starts.erase(starts.begin() + i);

		}
	TrPrE(ctx);
}

UPRISE_CORE_API void CORE::Behaviour::UpdateallParallel()
{
   
}

UPRISE_CORE_API bool CORE::Behaviour::AddToUpdate(RefWrapper<CORE::Behaviour,true> behaviour)
{
	behaviours.push_back(behaviour);
	return  true;
}

UPRISE_CORE_API bool CORE::Behaviour::AddToStart(RefWrapper<CORE::Behaviour,true> behaviour)
{
	awakes.push_back(behaviour);
	return true;
}

UPRISE_CORE_API bool CORE::Behaviour::AddToAwake(RefWrapper<CORE::Behaviour,true> behaviour)
{
	starts.push_back(behaviour);
	return true;
}
