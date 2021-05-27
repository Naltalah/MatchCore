#ifndef __PLAYER_MATCHCORE_H__
#define __PLAYER_MATCHCORE_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "version.hpp"
#include "score.hpp"
#include <cstdint>
#include <ctime>

namespace mc
{
    enum class combatstate
    {
        wait_combat,
        wait_spawn,
        wait_respawn,
        wait_replace,
        combat,
        no_combat,
    };

    class player
    {
        public:
            player(
                int32_t id,
                combatstate state = combatstate::no_combat,
                int32_t points = 0
            )
            : _id(id), _state(state), _points(points)
            {}
            ~player() {}

            bool operator==(const player& other)
            {
                return _id == other.get_id();
            }

            MC_NODISCARD()
            int32_t get_id(void) const MC_NOEXCEPT
            {
                return _id;
            }

        private:
            int32_t _id;
            combatstate _state;
            score _points;
            time_t _respawn_timer = time(nullptr);
    };
}

#endif // __PLAYER_MATCHCORE_H__