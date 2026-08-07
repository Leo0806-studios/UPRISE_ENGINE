#pragma once
import std;
namespace UPRISE_ENGINE::CORE::ALLOCATORS {
    class PoolBase {
    public:
        enum class Notification :std::uint8_t {
            N_inc,
            N_dec,
            N_delete
        };

    };
    template<typename _Ty>
    class CompactedPool:public PoolBase {
        friend class Ref;
    public:
        class Ref {
            CompactedPool<_Ty>* pool = nullptr;
            std::uint64_t id;
        public:
            _Ty* operator->();
            _Ty& operator*();

        };
    private:
        struct Node {
            Node* prev;
            Node* next;
            size_t count;
            _Ty* obj = nullptr;
        };

        _Ty* begin;
        _Ty* end;
        std::vector<Node> nodes;
    };


    template<>
    class CompactedPool<void> {

    };
}
