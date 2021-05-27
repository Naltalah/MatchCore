#ifndef __VERSION_MATCHCORE_H__
#define __VERSION_MATCHCORE_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

/*
    Configuration Defines
    
    Change these before to enable/disable
    certain language or library features.

    A full list can be found in the README file

*/

////////////// MATCHCORE FEATURES //////////////

//////////////  LANGUAGE FEATURES //////////////
#define         __MC_USE_OPTIONAL           false   // Requires C++17 or higher
#define         __MC_USE_NOEXCEPT           true    // Requires C++11 or higher

////////////// CPP VERSION CHECKS //////////////

#ifndef __has_cpp_attribute
#define __has_cpp_attribute(x) 0
#endif

#if __cpp_noexcept_function_type >= 201510 && __MC_USE_NOEXCEPT
#define MC_NOEXCEPT noexcept
#else
#define MC_NOEXCEPT
#endif

#if __has_cpp_attribute(nodiscoard) >= 201907
#define MC_NODISCARD(msg) [[nodiscard(msg)]]
#elif __has_cpp_attribute(nodiscard) >= 201603
#define MC_NODISCARD(msg) [[nodiscard]]
#else
#define MC_NODISCARD(msg)
#endif

#endif // __VERSION_MATCHCORE_H__