/* 
 * Copyright (C) 2022 Kyle Morris - All Rights Reserved
 * This is C+=, a free C++ toolbox.
 *
 * IPrintable
 * 
 * Interface for classes that can be printed to std::cout.
 */

#pragma once
#ifndef CPE_IPRINT_H
#define CPE_IPRINT_H

#include <string>

namespace cpe {

    /**
     * @brief Interface for classes that can be printed to std::cout.
     * @author Kyle Morris
     */
    class IPrintable {
    public:
        /**
         * @brief Converts this object to a string for printing.
         */
        virtual std::string ToString() const = 0;
    };

};

#endif  /* CPR_IPRINT_H */