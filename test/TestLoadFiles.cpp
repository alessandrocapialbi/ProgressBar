//
// Created by alessandro on 28/09/21.
//

#include "gtest/gtest.h"
#include "../LoadFiles.h"

TEST(TestLoadFiles, testNoFileNamesProvided) {
    QStringList list;
    LoadFiles loader;
    loader.load(list);
    ASSERT_EQ(loader.getFilesNumber(), 0);
}

TEST(TestLoadFiles, fileNamesProvided) {

    QStringList list;
    list.push_back("../resources/flower.jpeg");
    LoadFiles loader;
    loader.load(list);
    ASSERT_FALSE(loader.getFilesNumber() == 0);
};