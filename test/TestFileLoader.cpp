//
// Created by alessandro on 28/09/21.
//

#include "gtest/gtest.h"
#include "../FileLoader.h"

TEST(TestLoadFiles, testNoFileNamesProvided) {
    QStringList list;
    FileLoader loader;
    loader.load(list);
    ASSERT_EQ(loader.getFilesNumber(), 0);
}

TEST(TestLoadFiles, fileNamesProvided) {
    QStringList list;
    list.push_back("resources_test/flower.jpeg");
    FileLoader loader;
    loader.load(list);
    ASSERT_EQ(loader.getFilesNumber(), 1);
};