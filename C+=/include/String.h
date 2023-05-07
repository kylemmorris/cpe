/* 
 * Copyright (C) 2022 Kyle Morris - All Rights Reserved
 * This is C+=, a free C++ toolbox.
 *
 * String.h
 * 
 * The cpe::String class is a wrapper for std::string that provides
 * additional functionality while retaining std::strings utility.
 */

#pragma once
#ifndef CPE_STR_H
#define CPE_STR_H

#include "IPrintable.h"
#include <vector>

namespace cpe {

    /**
     * @brief An extension/wrapper for std::string.
     * This class provides additional, optimized functionality for redundant
     * string tasks.
     * @author Kyle Morris
     */
    class String : public IPrintable {
    public:
        /**
         * @brief The default, empty constructor.
         */
        String();
        /**
         * @brief The copy constructor.
         */
        String(const String& str);
        /**
         * @brief Constructor for converting from a string.
         */
        String(const std::string& str);
        /**
         * @brief Constructor for converting from a char array.
         */
        String(const char* str);
        /**
         * @brief Destructor.
         */
        ~String();

        void Trim(char c = ' ');
        void Trim(std::string s = " ");
        std::vector<String> Extract(char begin = '<', char end = '>');
        std::vector<String> Extract(std::string begin = "<", std::string end = ">");
        bool Replace(char replacement, char begin = '<', char end = '>');
        bool Replace(std::string replacement, std::string begin = ">", std::string end = "<");
        bool Separate(char separation, std::vector<String>& outVals) const;
        bool Separate(std::string separation, std::vector<String>& outVals) const;
        bool RemoveAll(char removal);
        bool RemoveAll(const std::string& removal);
        
        virtual std::string ToString() const override {
            return _imp;
        }

        //operator std::string() const { return imp; }
        //operator const char*() const { return imp.data(); }
        //bool operator==(const String& str) {return true;}

    private:
        std::string _imp;
    }

    typedef std::vector<String> Strings;

};

#endif  /* CPE_STR_H */