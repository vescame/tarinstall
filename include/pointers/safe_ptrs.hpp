#include <memory>

#ifndef SAFE_PTRS_HPP
#define SAFE_PTRS_HPP
template<typename T> using sptr = std::shared_ptr<T>;
template<typename T> sptr<T> to_sptr(const T* element);
template<typename T> sptr<T> to_sptr(T* element);
template<typename T> sptr<T> to_sptr(T element);

template<typename T> using uptr = std::unique_ptr<T>;
template<typename T> uptr<T> to_uptr(const T* element);
template<typename T> uptr<T> to_uptr(T* element);
template<typename T> uptr<T> to_uptr(T element);
#endif
