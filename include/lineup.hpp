#ifndef __LINEUP_MATCHCORE_H__
#define __LINEUP_MATCHCORE_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "version.hpp"
#include "player.hpp"

namespace mc
{
    template<size_t team_size>
    using team = std::array<mc::player, team_size>

    template<size_t team_count, size_t team_size>
    class lineup
    {
        public:
            lineup() {}
            ~lineup() {}

            team get_team(size_t index)
            {
                static_assert(index < team_count);

                return _teams[index];
            }

            mc::player get_player(size_t team_index, int32_t player_id)
            {
                static_assert(index < team_count);

#if __cpp_range_based_for
                for (auto const& p : _teams[index])
                {
                    if (p.get_id() == player_id)
                        return p;
                }
#else
                for (team::iterator it = _teams[index].begin();
                it != _teams[index].end();
                ++it)
                {
                    if (it->get_id() == player_id)
                        return *(it);
                }
#endif
                return mc::player(0);
            }

        private:
            std::array<team<team_size>, team_count> _teams;
    };
}

#endif // __LINEUP_MATCHCORE_H__