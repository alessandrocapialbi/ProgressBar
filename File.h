//
// Created by alessandro on 19/09/21.
//

#ifndef PROGRESSBAR_FILE_H
#define PROGRESSBAR_FILE_H

#include <iostream>
#include <stdio.h>
#include <QString>

using namespace std;

//Class that handles open and closing of files.
class File {
public:
    File(const QString *filename);

    ~File();

    int getSize() const {
        return fileSize;
    }


private:
    FILE *file;
    int fileSize;

};


#endif //PROGRESSBAR_FILE_H
