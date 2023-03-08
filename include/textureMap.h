#ifndef TEXTUREMAP_H
#define TEXTUREMAP_H
#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>
#include <cstring>
#include <omp.h>

#include "BounderVoxel.h"
#include "SOM.h"
#include "logger.h"

void createTexture();
void deleteTextureVoxel(std::vector<VoxData_b>&  bounderVoxelData, int bounderNum);
float distance(glm::fvec3 len);
float inner_product(glm::fvec3 l1, glm::fvec3 l2);
glm::fvec3 normalization(glm::fvec3 vector);
glm::fvec3 cross_product(glm::fvec3 l1, glm::fvec3 l2);
glm::fvec2 find_point(glm::fvec3 point, glm::fvec3 t0, glm::fvec3 t1, glm::fvec3 t2, float& minDist, glm::fvec2& mincoord, glm::fvec2 coord, int ud);
glm::fvec3 find_nearest_edge_point(glm::fvec3 point, glm::fvec3 t0, glm::fvec3 t1);
glm::fvec2 find_nearest_point(glm::fvec3 point, glm::fvec3 t, glm::fvec2 coord, glm::fvec2 mincoord, float minDist, int ud);
glm::fvec2 lattice_coord(int h, int w, glm::fvec3 coord);

extern unsigned int texture;
extern bool del;
extern int delNum;

#endif