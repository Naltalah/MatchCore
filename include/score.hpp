#ifndef __SCORE_MATCHCORE_H__
#define __SCORE_MATCHCORE_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "version.hpp"

namespace mc
{
    class score
    {
    public:
        score() : _score(0)
        {}
        score(int32_t s) : _score(s)
        {}
        score(const score& other) : _score(other.get())
        {}
        ~score() {};

        MC_NODISCARD()
        int32_t get() const MC_NOEXCEPT
        {
            return _score;
        }

        void add(int32_t s) MC_NOEXCEPT
        {
            _score += s;
        }

    private:
        int32_t _score;
    };
}

#endif // __SCORE_MATCHCORE_H__