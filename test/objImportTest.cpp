#include <gtest/gtest.h>
#include "objImporter.cpp"

TEST(objImport, facesTest)
{
    objImporter importer("../../data/test/cube.obj");
    Model import = importer.getModel();

    std::vector<int> vindices = import.getFaces().indices;

    // As per cube.obj
    std::vector<int> compare = {1, 3, 7,   1, 7, 5,
                                1, 2, 4,   1, 4, 3,
                                3, 4, 8,   3, 8, 7,
                                5, 7, 8,   5, 8, 6,
                                1, 5, 6,   1, 6, 2,
                                2, 6, 8,   2, 8, 4};

    ASSERT_EQ(vindices, compare);
}

TEST(objImport, facesTest4VertexIndices)
{
    objImporter importer("../../data/test/cube-4f.obj");
    Model import = importer.getModel();

    std::vector<int> vindices = import.getFaces().indices;

    // As per cube-4d.obj
    std::vector<int> compare = {1, 3, 7,   1, 7, 5,
                                1, 2, 4,   1, 4, 3,
                                3, 4, 8,   3, 8, 7,
                                5, 7, 8,   5, 8, 6,
                                1, 5, 6,   1, 6, 2,
                                2, 6, 8,   2, 8, 4};

    ASSERT_EQ(vindices, compare);
}
