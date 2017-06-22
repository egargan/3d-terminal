#include "Model.h"

Model::Model(std::vector<point> points) : vertices{points} {};

Model::~Model() { vertices.clear(); };