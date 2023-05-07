/* 
 * Copyright (C) 2022 Kyle Morris - All Rights Reserved
 * This is C+=, a free C++ toolbox.
 *
 * FileReader.h
 * 
 * Contains the FileReader class, a simplified interface for reading
 * from a file.
 */

#pragma once
#ifndef CPE_FILE_READER_H
#define CPE_FILE_READER_H

#include "Path.h"

namespace cpe {

    class FileReader final {
    public:
        FileReader();
        bool LoadFile(Path filePath);
        bool UnloadFile();
        const String* GetNextLine();
        int GetLineNumber() const;
    private:

    }

};

#endif  /* CPE_H */