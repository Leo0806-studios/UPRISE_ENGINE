#include "UPRISE_BASE_EXCEPTION.h"
namespace UPRISE_ENGINE {
    namespace EE {
        std::string  UPRISE_ENGINE::EE::EXCEPTIONS::UpriseBaseException::What_UE() const {
            return _msg;
        }
    }
}
