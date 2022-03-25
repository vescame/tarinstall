#include <memory>
#include <string>

#ifndef PTRS_HPP
#define PTRS_HPP

template<typename T> using sptr = std::shared_ptr<T>;
template<typename T> sptr<T> to_sptr(const T* element) { return std::make_shared<T>(element); };
template<typename T> sptr<T> to_sptr(T* element) { return std::make_shared<T>(element); };
template<typename T> sptr<T> to_sptr(T element) { return std::make_shared<T>(element); };

template<typename T> using uptr = std::unique_ptr<T>;
template<typename T> uptr<T> to_uptr(const T* element) { return std::make_shared<T>(element); };
template<typename T> uptr<T> to_uptr(T* element) { return std::make_shared<T>(element); };
template<typename T> uptr<T> to_uptr(T element) { return std::make_shared<T>(element); };

#endif
