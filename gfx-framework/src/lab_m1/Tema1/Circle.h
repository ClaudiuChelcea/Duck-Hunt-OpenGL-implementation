#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#pragma once

#include <string>
#include <vector>

#include "core/gpu/mesh.h"

#define PI 3.14f

namespace Circle {
    /**
     * Create a circle shape
     * @param circle_name name given to object
     * @param center the center to start drawing from
     * @param radius the radius of the circle
     * @param nrOfTriangles the number of triangles of the circle
     * @param color the color of the circle
     * @result A circle mesh
     */
    Mesh* CreateCircle(const std::string& circle_name = "", glm::vec3 Corner = { 0.0f, 0.0f, 0.0f }, int radius = 0, int nrOfTriangles = 0, glm::vec3 color = { 0.0f, 0.0f, 0.0f });
};

#endif // __CIRCLE_H_


