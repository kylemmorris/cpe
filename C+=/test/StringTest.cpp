/* 
 * Copyright (C) 2022 Kyle Morris - All Rights Reserved
 * This is C+=, a free C++ toolbox.
 *
 * <filename>
 * 
 * <short description>
 */

#pragma once
#ifndef CPE_STRING_TEST_H
#define CPE_STRING_TEST_H

#include "Toolbox.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

    // TRIM WHITESPACE
    cpe::String s = "  TEST  ";
    std::cout << "Before Trim(): " << s << std::endl;
    s.Trim();
    std::cout << "After Trim(): " << s << std::endl;
    // TRIM ARBITRARY CHARACTER
    s = "$$TEST$";
    std::cout << "Before Trim(): " << s << std::endl;
    s.Trim('$');
    std::cout << "After Trim(): " << s << std::endl;
    // EXTRACTING ONE SEQUENCE
    s = "This should {totally} be extracted";
    std::cout << "Before Extract(): " << s << std::endl;
    auto extracts = s.Extract("{", "}"});
    std::cout << "After Extract(): " << s << std::endl;
    std::cout << "Extracted values:" << std::endl;
    for(cpe::String s1 : extracts) {
        std::cout << s1 << std::endl;
    }
    // EXTRACTING MULTIPLE SEQUENCES
    s = "Read {I} between the {love} lines {you}.";
    std::cout << "Before Extract(): " << s << std::endl;
    auto extracts = s.Extract("{", "}"});
    std::cout << "After Extract(): " << s << std::endl;
    std::cout << "Extracted values:" << std::endl;
    for(cpe::String s1 : extracts) {
        std::cout << s1 << std::endl;
    }
    // SEPARATING A STRING
    s = "Separate() should be useful for tokenization.";
    std::cout << "Before Separate(): " << s << std::endl;
    cpe::Strings group = {};
    if(s.Separate(' ', group)) {
        std::cout << "After Separate(): " << s << std::endl;
        std::cout << "Extracted values:" << std::endl;
        for(cpe::String s1 : group) {
            std::cout << s1 << std::endl;
        }
    }
    else {
        std::cout << "Error: s.Separate(\' \') returned false!" << std::endl;
    }
    // REPLACING STUFF IN A STRING
    s = "I want to replace <this> with that.";
    std::cout << "Before Replace(): " << s << std::endl;
    if(s.Replace("that")) {
        std::cout << "After Replace(): " << s << std::endl;
    }
    else {
        std::cout << "Error: s.Replace(\' \') returned false!" << std::endl;
    }
}

#endif