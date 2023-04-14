#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#pragma once

#include <string>
#include <vector>
#include "core/gpu/mesh.h"

namespace Rectangle
{
    /**
     * Create a rectangle shape
     * @param rectangle_name name given to object
     * @param Corner the corner of the object to start drawing from
     * @param heoght the height of the rectangle
     * @param length the lenght of one side of the rectangle
     * @param color the color used for the rectangle
     * @result A rectangle mesh
     */
    Mesh* CreateRectangle(const std::string& rectangle_name = "", glm::vec3 Corner = { 0.0f, 0.0f, 0.0f }, float height = 0.0f, float width = 0.0f, glm::vec3 color = { 0.0f, 0.0f, 0.0f }, bool fill = false);
}

#endif // __RECTANGLE_H_