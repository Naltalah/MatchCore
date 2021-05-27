#ifndef __RANKING_MATCHCORE_H__
#define __RANKING_MATCHCORE_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <map>
#include <list>
#include <optional>
#include "score.hpp"
#include "version.hpp"

namespace mc
{
    using ranking_map = std::map<int32_t, mc::score>;

    class ranking
    {
    public:
        // Construction / Destruction
        ranking() {}
        ranking(const mc::ranking& rhs)
        {
            _ranking = rhs._ranking;
        }
        ranking& operator=(const ranking& rhs)
        {
            _ranking = rhs._ranking;
        }
        ranking& operator=(ranking&& rhs) 
        {
            _ranking = std::move(rhs._ranking);
        }
        ~ranking() {}

        // STL-esque API
        MC_NODISCARD() 
        ranking_map::iterator begin() MC_NOEXCEPT
        {
            return _ranking.begin();
        }

        MC_NODISCARD() 
        ranking_map::iterator end() MC_NOEXCEPT
        {
            return _ranking.end();
        }

        MC_NODISCARD() 
        size_t size() const
        {
            return _ranking.size();
        }

        // API
#if __cpp_lib_any >= 201606 && __MC_USE_OPTIONAL        
        std::optional<mc::score> get_player_score(int32_t id) const MC_NOEXCEPT
        {
            if (_ranking.count(id) > 0)
            {
                return _ranking.at(id);
            }
            else
            {
                return std::nullopt;
            }
        }
#else
        mc::score get_player_score(int32_t id) const MC_NOEXCEPT
        {
            if (_ranking.count(id) > 0)
            {
                return _ranking.at(id);
            }

            return mc::score();
        }
#endif     

        template<typename lambda>
        MC_NODISCARD()
        std::list<mc::score> get_sorted(lambda l)
        {
            std::list<mc::score> return_list;
            
#if __cpp_range_based_for
            for (auto& data : _ranking)
            {
                return_list.insert(data.second);
            }
#else
            for (ranking_map::iterator it = begin(); it != end(); ++it)
            {
                return_list.insert(it->second);
            }
#endif

            std::sort(return_list.begin(), return_list.end(), l);

            return return_list;
        }

    private:
        ranking_map _ranking;
    };
}

#endif // __RANKING_MATCHCORE_H__