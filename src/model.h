
#ifndef INC_3DTERMINAL_MODEL_H
#define INC_3DTERMINAL_MODEL_H

#include <vector>

#include "mat3.h"
#include "vec3.h"
#include "indexed_list.h"

// Contains member vectors storing model's vertices and face polygons.
// Faces are represented as tuples of indices referring to vertex list.
class Model {

 public:

  // Constructs model with given vertices
  explicit Model(std::vector<Vec3f> points) : vertices_{std::move(points)}, location_{0, 0, 0} {};

  // Constructs empty model
  Model() : location_{0, 0, 0} {};

  // Clears model vertex list
  ~Model() { vertices_.clear(); };

  // Returns IndexedList of edges defining model's shape.
  // Unless overriden, will return a list of edges connecting every single vertex - override me!
  virtual IndexedList GetLines() const {
    std::vector<int> edges;

    for (int i = 0; i < vertices_.size(); i++) {
      for (int j = i + 1; j < vertices_.size(); j++) {
        edges.push_back(i);
        edges.push_back(j);
      }
    }
    return {vertices_, edges};
  };

  // todo - if we have faces, create GetLines to return the lines that make them up

  // Returns list of vertices, and 3-tuples of vertex indices representing model made up of triangles
  virtual IndexedList GetFaces() const {
    return {vertices_, faces_};
  };

  std::vector<Vec3f> vertices_;

  // Stored as actual member, as opposed to model lines, as the model importer needs a target for its output.
  // List of integers parsed as 3-tuples representing model made up of triangles.
  std::vector<int> faces_;

  // 3D coordinate representing model's location in the 'world'
  Vec3f location_;

};

#endif //INC_3DTERMINAL_MODEL_H
