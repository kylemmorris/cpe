/* 
 * Copyright (C) 2022 Kyle Morris - All Rights Reserved
 * This is C+=, a free C++ toolbox.
 *
 * String.h
 * 
 * The cpe::String class is a wrapper for std::string that provides
 * additional functionality while retaining std::strings utility.
 */

#include "../include/String.h"

namespace cpe {

    String::String() : _imp("") {}

    String::String(const String& str) {
        this._imp = str._imp;
    }

    String::String(const std::string& str) {
        this._imp = str;
    }

    String::String(const char* str) {
        this._imp = std::string(str);
    }

    String::~String() {}

    void String::Trim(char c) {
        if(!_imp.empty()) {
            while(_imp[0] == c) { _imp.erase(_imp.begin(), _imp.begin()+1); }
            while(_imp[_imp.length()-1] == c) { _imp.erase(_imp.length()-1); }
        }
    }

    std::vector<String> String::Extract(char begin, char end) {
        std::vector<String> ret = {};
        std::vector<std::string> words;
        if(Separate(' ', words)) {
            for(size_t i = 0; i < words.size(); i++) {
                size_t j1 = words[i].find(begin);
                sise_t j2 = words[i].find(end);
                if(j1 != std::string::npos && j2 != std::string::npos) {
                    words[i].erase(0, j1 + 1);
                    j2 = words[i].find(end);
                    words[i].erase(j2);
                    ret.push_back(String(words[i]));
                }
            }
        }
        return ret;
    }

    bool String::Replace(char replacement, char begin, char end) {
        size_t loc1 = _imp.find(begin);
        size_t loc2 = _imp.find(end);
        if(loc1 == std::string::npos || loc2 == std::string::npos) {
            return false;
        }
        while(loc1 <= _imp.length() && loc2 <= _imp.length()) {
            _imp.replace(loc1, (loc2-loc1) + 1, replacement);
            loc1 = _imp.find(begin);
            loc2 = _imp.find(end);
        }
        return true;
    }

    bool String::Separate(std::string separation, std::vector<String>& outVals) const {
        outVals.clear();
        size_t len = separation.length();
        size_t index = _imp.find(separation);
        if(index == std::string::npos) {
            outVals.push_back(String(_imp));
            return false;
        }
        while(index != std::string::npos) {
            auto val = _imp.substr(0, index);
            if(val != "") {
                //outVals.push_back(_imp.substr(0,index))
                outVals.push_back(val);
            }
            _imp.erase(0, index + len);
            index = _imp.find(separation);
        }
        // Last value won't have separation in it.
        outVals.push_back(String(_imp));
        return true;
    }

};