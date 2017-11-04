/** \file HasMember.h
  *
  * Very simple C++11 helpers to verify at compile time if a class has
  * a variable or a function. Very useful for creating SFINAE friendly
  * classes or functions
*/

#ifndef HAS_MEMBER_H
#define HAS_MEMBER_H

#include "Helpers.h"


namespace handy
{

/// Helper for variables
#define VAR_HELPER(T, var, ...) std::declval<T>().var

/// Helper for functions
#define FUNC_HELPER(T, func, ...) &T::func


/// Helper for overloaded functions
#define OVERLOADED_FUNC_HELPER(T, func, Args, ...) std::declval<T>().func(std::declval<Args>()...)

/// Extern function helper
#define EXTERN_FUNC_HELPER(T, ext, Args, ...) ext(std::declval<T>(), std::declval<Args>()...)


/// If the class has a variable
#define HAS_VAR(...) EXPAND(HAS_MEMBER(VAR_HELPER, __VA_ARGS__, CONCAT(Has, __VA_ARGS__)))

/// If the class has a function
#define HAS_FUNC(...) EXPAND(HAS_MEMBER(FUNC_HELPER, __VA_ARGS__, CONCAT(Has, __VA_ARGS__)))

/// Extern function
#define HAS_EXTERN_FUNC(...) EXPAND(HAS_MEMBER(EXTERN_FUNC_HELPER, __VA_ARGS__, CONCAT(Has, __VA_ARGS__)))

/// Overloaded function. WARNING: it does not verify explicit overloads
#define HAS_OVERLOADED_FUNC(...) EXPAND(HAS_MEMBER(OVERLOADED_FUNC_HELPER, __VA_ARGS__, CONCAT(has_, __VA_ARGS__)))

// /// Overloaded function
// #define HAS_STRICTLY_OVERLOADED_FUNC(...) EXPAND(HAS_MEMBER(STRICTLY_OVERLOADED_FUNC_HELPER, __VA_ARGS__, CONCAT(has_, __VA_ARGS__)))


/** Here we create functions returning compile time values that tells us
  * if a class has or not a member of the given name. See the examples below.
*/
#define HAS_MEMBER(HELPER, member, Name, ...) \
\
template <typename...> \
constexpr bool CONCAT(Name, Impl) (...) { return false; } \
\
template <typename T, typename... Args> \
constexpr bool CONCAT(Name, Impl) (std::decay_t<decltype(EXPAND(HELPER(T, member, Args)), void())>*) { return true; } \
\
template <typename T, typename... Args>  \
struct Name : public std::integral_constant<bool, CONCAT(Name, Impl) <std::decay_t<T>, Args...>(nullptr)> {};

} // namespace handy


#endif //HAS_MEMBER_H