#include "Triangle.h"

/**
 * Create a triangle shape
 * @param triangle_name name given to object
 * @param Corner the corner of the object to start drawing from
 * @param length the lenght of one side of the triangle
 * @param color the color used for the triangle
 * @result A triangle mesh
 */
Mesh* Triangle::CreateTriangle(const std::string& triangle_name, glm::vec3 Corner, float length, glm::vec3 color)
{
    // Create mesh
    Mesh* triangle = new Mesh(triangle_name);

    // Set vertices
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(Corner + glm::vec3(0, 0, 0), color),
        VertexFormat(Corner + glm::vec3(length, 0, 0), color),
        VertexFormat(Corner + glm::vec3(0, length, 0), color),
    };

    std::vector<unsigned int> indices;
    for (int i = 0; i < vertices.size(); ++i) {
        indices.push_back(i);
    }

    // Draw triangle
    triangle->SetDrawMode(GL_TRIANGLES);
    triangle->InitFromData(vertices, indices);

    return triangle;
}
