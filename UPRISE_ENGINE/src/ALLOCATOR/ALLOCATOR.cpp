// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//#include "pch.h"


//#include "ALLOCATOR.h"
//
//
//
//
//
//void* ALLOCATOR::MemoryPool::allocate(size_t size) {
//    std::lock_guard<std::mutex> lock(mutex);
//
//    // Check the free list first
//    for (auto it = freeList.begin(); it != freeList.end(); ++it) {
//        if (it->size >= size) {
//            void* ptr = it->ptr;
//            if (it->size > size) {
//                // Adjust the remaining free block
//                it->ptr = static_cast<char*>(it->ptr) + size;
//                it->size -= size;
//            }
//            else {
//                // Remove the block if it perfectly fits
//                freeList.erase(it);
//            }
//            used += size;
//            return ptr;
//        }
//    }
//
//    // Allocate new memory if no suitable block found
//    if (used + size > poolSize) {
//        resize(poolSize * 2);  // Double the pool size when needed
//    }
//    void* ptr = static_cast<char*>(pool) + used;
//    used += size;
//
//    if (!ptr) throw std::bad_alloc();
//    return ptr;
//}
//
//void ALLOCATOR::MemoryPool::deallocate(void* ptr, size_t size) {
//        std::lock_guard<std::mutex> lock(mutex);
//        // Add the block to the free list and coalesce adjacent blocks
//        freeList.push_back({ ptr, size });
//        used -= size;
//        coalesce();
//    }
//void ALLOCATOR::MemoryPool::shrinkIfNeeded() {
//    std::lock_guard<std::mutex> lock(mutex);
//    if (used * 2 < poolSize) {
//        resize(poolSize / 2);  // Halve the pool size if it's twice as big as needed
//    }
//}
//
//void ALLOCATOR::MemoryPool::reset() {
//    std::lock_guard<std::mutex> lock(mutex);
//    used = 0;
//    freeList.clear();
//    freeList.push_back({ pool, poolSize });
//}
//
//
//void ALLOCATOR::MemoryPool::resize(size_t newSize) {
//    void* newPool = std::realloc(pool, newSize);
//    if (!newPool) throw std::bad_alloc();
//    pool = newPool;
//    poolSize = newSize;
//    freeList.push_back({ static_cast<char*>(pool) + used, newSize - used });
//}
//
//void ALLOCATOR::MemoryPool::coalesce() {
//    freeList.sort([](const FreeBlock& a, const FreeBlock& b) {
//        return a.ptr < b.ptr;
//        });
//
//    for (auto it = freeList.begin(); it != freeList.end(); ++it) {
//        auto next = std::next(it);
//        if (next != freeList.end() && (static_cast<char*>(it->ptr) + it->size == next->ptr)) {
//            it->size += next->size;
//            freeList.erase(next);
//            it--; // Recheck the current iterator after merging
//        }
//    }
//}
//
//void* ALLOCATOR::CustomAllocator::allocate(size_t size) {
//    return memoryPool.allocate(size);
//}
//
//void ALLOCATOR::CustomAllocator::deallocate(void* ptr, size_t size) {
//    memoryPool.deallocate(ptr, size);
//    memoryPool.shrinkIfNeeded();
//}
//
//void ALLOCATOR::CustomAllocator::reset() {
//    memoryPool.reset();
//}
