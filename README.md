# MatchCore
A C++ library that can be ingested with User/World objects in games to act like a baseline match processing, either PVP or PVE. Intentional design is for Fly For Fun, but baseline can be generic.

# Development State

Started: May 27th, 2021 \
Status: Incomplete

# Configuration Defines
In version.hpp, you can find several configurations for this library.
The following list contains all options and a short explanation.

| Configuration | Default Value | Explanation |
| :---: | :---: | :---: |
| __MC_USE_OPTIONAL | false | If true, enables std::optional return types. `Requires C++17` |
| __MC_USE_NOEXCEPT | true | If true, enables function declaration as noexcept. `Requires C++11` |

# Changelog

*May 27th*
- Added baseline implementation for all classes except core and match
