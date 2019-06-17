
#include <gtest/gtest.h>
#include "obj_importer.cc"

TEST(objImport, facesTest) {
  ObjImporter importer("../../data/test/cube.obj");
  Model import = importer.GetModel();

  std::vector<int> vindices = import.GetFaces().indices_;

  // As per cube.obj
  std::vector<int> compare = {1, 3, 7, 1, 7, 5,
                              1, 2, 4, 1, 4, 3,
                              3, 4, 8, 3, 8, 7,
                              5, 7, 8, 5, 8, 6,
                              1, 5, 6, 1, 6, 2,
                              2, 6, 8, 2, 8, 4};

  ASSERT_EQ(vindices, compare);
}

TEST(objImport, facesTest4VertexIndices) {
  ObjImporter importer("../../data/test/cube-4f.obj");
  Model import = importer.GetModel();

  std::vector<int> vindices = import.GetFaces().indices_;

  // As per cube-4d.obj
  std::vector<int> compare = {1, 3, 7, 1, 7, 5,
                              1, 2, 4, 1, 4, 3,
                              3, 4, 8, 3, 8, 7,
                              5, 7, 8, 5, 8, 6,
                              1, 5, 6, 1, 6, 2,
                              2, 6, 8, 2, 8, 4};

  ASSERT_EQ(vindices, compare);
}
