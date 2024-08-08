//#pragma once
//#ifndef _ALLOCATOR_
//#define _ALLOCATOR_
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <mutex>
//#include <list>
//#include <stdexcept>
//
//namespace ALLOCATOR {
//	class MemoryPool {
//
//	public:
//		//MemoryPool(size_t initialSize = 1024 * 1024) : poolSize(initialSize), used(0) {
//		//	pool = std::malloc(poolSize);
//		//	if (!pool) throw std::bad_alloc();
//		//}
//		MemoryPool(size_t initialSize = 1024 * 1024)
//			: poolSize(initialSize), used(0), pool(nullptr) {
//			pool = std::malloc(poolSize);
//			if (!pool) throw std::bad_alloc();
//			freeList.push_back({ pool, poolSize });
//		}
//		~MemoryPool() {
//			std::free(pool);
//		}
//		void* allocate(size_t size);
//		void deallocate(void* ptr, size_t size);
//		void shrinkIfNeeded();
//		void reset();
//	private:
//		void* pool;
//		size_t poolSize;
//		size_t used;
//		std::mutex mutex;
//		struct FreeBlock {
//			void* ptr;
//			size_t size;
//		};
//		std::list<FreeBlock> freeList;
//		void resize(size_t newSize);
//		void coalesce();
//	};
//
//	class CustomAllocator {
//
//
//	public:
//		CustomAllocator(size_t initialSize = 1024 * 1024) : memoryPool(initialSize) {};
//		void* allocate(size_t size);
//		void deallocate(void* ptr, size_t size);
//		void reset();
//	private:
//		MemoryPool memoryPool;
//	};
//}
//ALLOCATOR::CustomAllocator& globalAllocator() {
//	static ALLOCATOR::CustomAllocator instance((2048*4) * (2048*4));
//	return instance;
//}
//
//void* operator new(size_t size) {
//	return globalAllocator().allocate(size);
//}
//
//void operator delete(void* ptr, size_t size) noexcept {
//	globalAllocator().deallocate(ptr, size);
//}
//
//#endif // !_ALLOCATOR_
