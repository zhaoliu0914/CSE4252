#ifndef MYALLOC_H
#define MYALLOC_H

#include <cstdlib>
#include <stdexcept>
#include <limits>

template <typename T>
class MyAlloc {
public:
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;

    MyAlloc() = default;

    template <typename U>
    MyAlloc(const MyAlloc<U>&) {}

    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }

    pointer allocate(size_type n, const void* hint = 0) {
        if (n > std::numeric_limits<size_type>::max() / sizeof(T))
            throw std::bad_alloc();
        // Use malloc or mmap here as per the lab requirement
        pointer p = (pointer)malloc(n * sizeof(T));
        if (!p)
            throw std::bad_alloc();
        return p;
    }

    void deallocate(pointer p, size_type n) {
        free(p);
    }

    size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        new((void*)p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* p) {
        p->~U();
    }

    template <typename U>
    struct rebind {
        using other = MyAlloc<U>;
    };
};

#endif // MYALLOC_H
