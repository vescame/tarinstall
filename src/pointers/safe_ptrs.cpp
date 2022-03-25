#include "../../include/pointers/safe_ptrs.hpp"

template<typename T> sptr<T> to_sptr(const T* element) { return std::make_shared<T>(element); };
template<typename T> sptr<T> to_sptr(T* element) { return std::make_shared<T>(element); };
template<typename T> sptr<T> to_sptr(T element) { return std::make_shared<T>(element); };
template<typename T> uptr<T> to_uptr(const T* element) { return std::make_shared<T>(element); };
template<typename T> uptr<T> to_uptr(T* element) { return std::make_shared<T>(element); };
template<typename T> uptr<T> to_uptr(T element) { return std::make_shared<T>(element); };

