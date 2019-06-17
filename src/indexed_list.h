
#ifndef INC_3DTERMINAL_INDEXEDLINELIST_H
#define INC_3DTERMINAL_INDEXEDLINELIST_H

#include <vector>

#include "vec3.h"

// Convenience structure for holding vertices, and indices referring to them.
struct IndexedList {
  std::vector<Vec3f> vertices_;

  // List of integers, parsed as list of n-tuples for representing e.g. edges or polygons
  std::vector<int> indices_;
};

#endif //INC_3DTERMINAL_INDEXEDLINELIST_H