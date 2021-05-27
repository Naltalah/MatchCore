#ifndef __SCOREPROCESSOR_MATCHCORE_H__
#define __SCOREPROCESSOR_MATCHCORE_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "version.hpp"
#include "player.hpp"

namespace mc
{
    template<size_t size>
    class score_processor
    {
        public:
            score_processor() 
            {
                _players.resize(size);
            };
            ~score_processor() {};

            // pure virtual, supply your own implementation
            virtual void ProcessPlayers() = 0;

            // default event handler, supply your own implementation
            virtual void OnEvent(const mc::player& p1, const mc::player& p2) 
            {
            }

            MC_NODISCARD()
            bool add_player(const mc::player& p)
            {
                if (_players.size() >= size)
                    return false;

                _players.emplace_back(p);

                return true;
            }

            void remove_player(const mc::player& p)
            {
                _players.erase(
                    std::remove(_players.begin(), _players.end(), p)
                );
            }

            // STL-esque API
            std::vector<mc::player>::iterator begin()
            {
                return _players.begin();
            }
            std::vector<mc::player>::iterator end()
            {
                return _players.end();
            }
            MC_NODISCARD()
            size_t size() MC_NOEXCEPT
            {
                return _players.size();
            }

        private:
            std::vector<mc::player> _players;
    };
}

#endif // __SCOREPROCESSOR_MATCHCORE_H__