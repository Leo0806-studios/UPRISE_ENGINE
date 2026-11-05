#pragma once


#include <exception>
#include <source_location>
#include <string>
#include <utility>
#include <IMPORT_DEFS.h>
#include <MACROS.h>
#include <ANOTATIONS.h>

namespace UPRISE_ENGINE {
    namespace EE {
        namespace EXCEPTIONS {
            class UpriseBaseException : public std::exception {
            private:
                std::string _msg;
                std::source_location _source;

            public:
                explicit UpriseBaseException(std::string msg,std::source_location source = std::source_location::current())noexcept
                    : _msg(std::move(msg)),_source(source) {}

                UpriseBaseException() = default;
                UpriseBaseException(const UpriseBaseException&) = default;
                UpriseBaseException(UpriseBaseException&&) noexcept = default;
                UpriseBaseException& operator=(const UpriseBaseException&) = default;
                UpriseBaseException& operator=(UpriseBaseException&&) noexcept = default;
                ~UpriseBaseException() override = default;

               UE_NODISCARD const char* what() const noexcept override {
                    return _msg.c_str();
                }

               UE_NODISCARD UPRISE_ENGINE_EE_API  virtual std::string What_UE()const;
               UE_NODISCARD UPRISE_ENGINE_EE_API  std::source_location GetSourceLocation()const {
                   return _source;
               }
            };
        }
    }
}