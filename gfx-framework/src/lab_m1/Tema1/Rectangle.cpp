#include "Rectangle.h"

/**
 * Create a rectangle shape
 * @param rectangle_name name given to object
 * @param Corner the corner of the object to start drawing from
 * @param heoght the height of the rectangle
 * @param length the lenght of one side of the rectangle
 * @param color the color used for the rectangle
 * @result A rectangle mesh
 */
Mesh* Rectangle::CreateRectangle(const std::string& rectangle_name, glm::vec3 Corner, float height, float length, glm::vec3 color, bool fill)
{
    // Create mesh
    Mesh* rectangle = new Mesh(rectangle_name);

    // Set vertices
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(Corner, color),
        VertexFormat(Corner + glm::vec3(length, 0, 0), color),
        VertexFormat(Corner + glm::vec3(length, height, 0), color),
        VertexFormat(Corner + glm::vec3(0, height, 0), color)
    };

    std::vector<unsigned int> indices;
    for (int i = 0; i < vertices.size(); ++i) {
        indices.push_back(i);
    }

    // Draw rectangle
    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }
    rectangle->InitFromData(vertices, indices);

    return rectangle;
}
