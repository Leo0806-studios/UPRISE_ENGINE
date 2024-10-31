#include "CORE/BEHAVIOUR/BEHAVIOUR.h";
#include <DEBUG/LOG/LOG.h>
import std;


 std::vector<RefWrapper<CORE::Behaviour,true>> CORE::Behaviour::behaviours;
 std::vector<RefWrapper<CORE::Behaviour,true>> CORE::Behaviour::awakes;
 std::vector<RefWrapper<CORE::Behaviour,true>> CORE::Behaviour::starts;




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
            CORE::Behaviour::AddToUpdate(starts[i]);
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
UPRISE_CORE_API bool CORE::Behaviour::RemoveFromUpdate()
{
    //behaviours.erase(behaviours.begin());
    //TODO: implement
	return true;

}

UPRISE_CORE_API bool CORE::Behaviour::RemoveFromStart()
{
    //TODO: implement

	return true;
}
UPRISE_CORE_API bool CORE::Behaviour::RemoveFromAwake()
{
    //TODO: implement

	return true;

}
void CORE::Behaviour::OnDestroy()
{
    
}
int CORE::Behaviour::currentUpdate = 0;

void CORE::Behaviour::OnDestroyInt(RefWrapper<Object, true> obj)
{
    Log << "Calling OnDestroy\n";
    OnDestroy();
    obj.Destroy();
    
}
