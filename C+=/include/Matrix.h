/* 
 * Copyright (C) 2022 Kyle Morris - All Rights Reserved
 * This is C+=, a free C++ toolbox.
 *
 * Matrix.h
 * 
 * Class that represents an M x N matrix, with appropriate mathematical
 * algorithms and definitions.
 */

#pragma once
#ifndef CPE_MATRIX_H
#define CPE_MATRIX_H

#include "IPrintable.h"
#include <vector>

namespace cpe {

    /**
     * @brief Represents a matrix of any numeric value.
     * Definitions Matrixi, Matrixf, and Matrixd use this class.
     * 
     * @tparam T The numeric type.
     */
    template<typename T>
    class Matrix : public IPrintable {
    public:
        /**
         * @brief Constructor.
         * 
         * @param dimM The 'M' dimension, i.e. # of rows.
         * @param dimN The 'N' dimension, i.e. # of columns.
         */
        Matrix(size_t dimM, size_t dimN);
        ~Matrix();
        /**
         * @brief Get the number of rows.
         */
        size_t GetDimM() const;
        /**
         * @brief Get the number of columns.
         */
        size_t GetDimN() const;

        std::vector<T> GetRow(size_t dimM) const;
        std::vector<T> GetColumn(size_t dimN) const;

        virtual std::string ToString() const override {
            return "";
        }
    private:
        size_t _m;
        size_t _n;
        std::vector<std::vector<T>> _imp;
    };

    /**
     * @brief A matrix of integers.
     */
    typedef Matrix<int> Matrixi;
    /**
     * @brief A matrix of floats.
     */
    typedef Matrix<float> Matrixf;
    /**
     * @brief A matrix of doubles.
     */
    typedef Matrix<double> Matrixd;

};

#endif  /* CPE_H */