//
// Created by alessandro on 19/09/21.
//

#include "File.h"


File::File(const char *filename) : file(fopen(filename, "r")), fileSize(0) {
    if (!file)
        throw runtime_error("Error occurred during file opening");
    else {
        fseek(file, 0, SEEK_END); //Point to the end of the file.
        fileSize = ftell(
                file); //It gives the file size based on the pointer given by fseek (from the beginning to the end).
        cout << "File " << filename << " open successfully!" << ", size: " << fileSize << endl;
    }

}

File::~File() {
    if (fclose(file)) { //If it doesn't return 0, it means that the file hasn't been closed, so throws an exception.
        throw runtime_error("Failed to close file!");
    }
}