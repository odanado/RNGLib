/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef INCLUDED_CONFIG_HPP
#define INCLUDED_CONFIG_HPP

#include <cstdint>

#ifdef _MSC_VER

#define RNGLIB_CONSTEXPR 
#define RNGLIB_CONSTEXPR_OR_CONST const
#define RNGLIB_STATIC_CONSTEXPR static
#define RNGLIB_STATIC_CONSTEXPR_OR_CONST static const

#else

#define RNGLIB_CONSTEXPR constexpr
#define RNGLIB_CONSTEXPR_OR_CONST constexpr
#define RNGLIB_STATIC_CONSTEXPR static constexpr
#define RNGLIB_STATIC_CONSTEXPR_OR_CONST static constexpr

#endif
#endif

namespace RNGLib {
    typedef uint64_t u64;
    typedef uint32_t u32;
} // end RNGLib

