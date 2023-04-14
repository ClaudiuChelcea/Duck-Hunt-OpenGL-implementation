#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_

#pragma once

#include <string>
#include <vector>
#include "core/gpu/mesh.h"

namespace Triangle
{
    /**
     * Create a triangle shape
     * @param triangle_name name given to object
     * @param Corner the corner of the object to start drawing from
     * @param length the lenght of one side of the triangle
     * @param color the color used for the triangle
     * @result A triangle mesh
     */
    Mesh* CreateTriangle(const std::string& triangle_name = "", glm::vec3 Corner = { 0.0f, 0.0f, 0.0f }, float length = 0.0f, glm::vec3 color = { 0.0f, 0.0f, 0.0f });
}

#endif // __TRIANGLE_H_