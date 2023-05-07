/* 
 * Copyright (C) 2022 Kyle Morris - All Rights Reserved
 * This is C+=, a free C++ toolbox.
 *
 * Ranged.h
 * 
 * Contains container classes for ranged numerics.
 */

#pragma once
#ifndef CPE_RANGED_H
#define CPE_RANGED_H

#include "IPrintable.h"

namespace cpe {

    /**
     * @brief A ranged version of a numeric that throws
     * invalid_range_exception when attempting to set it to 
     * a value outside of its range.
     * 
     * @tparam T 
     */
    template<typename T>
    class Ranged : public IPrintable {
    public:
        /**
         * @brief 
         * 
         * @param clamped If true, when this is assigned a value out of range, will 
         * clamp to the highest or lowest value instead of throwing an exception.
         */
        Ranged(bool clamped = false) : _clamp(clamped) {}
    protected:
        bool _clamp;
    };

};

#endif  /* CPE_RANGED_H */