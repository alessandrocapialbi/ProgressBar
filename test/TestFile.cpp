//
// Created by alessandro on 28/09/21.
//

#include "gtest/gtest.h"
#include "../File.h"

TEST(TestFile, testNonExistentResource) {
    ASSERT_THROW(File file("../resources/non_existing_file.jpg"), runtime_error);
}

TEST(TestFile, testExistentResource) {
    ASSERT_NO_THROW(File file("../resources/flower.jpeg"));
}

TEST(TestFile, testSizeForExistentFile) {
    File file("../resources/flower.jpeg");
    ASSERT_FALSE(file.getSize() == 0);
}