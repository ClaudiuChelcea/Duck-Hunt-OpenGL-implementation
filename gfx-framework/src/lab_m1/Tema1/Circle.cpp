#include "Circle.h"

/**
* Create a circle shape
* @param circle_name name given to object
* @param center the center to start drawing from
* @param radius the radius of the circle
* @param nrOfTriangles the number of triangles of the circle
* @param color the color of the circle
* @result A circle mesh
*/
Mesh* Circle::CreateCircle(const std::string& circle_name, glm::vec3 Corner, int radius, int nrOfTriangles, glm::vec3 color)
{
    Mesh* head = new Mesh(circle_name);

    std::vector<VertexFormat> vertices{ Corner };
    std::vector<unsigned int> indices;

    // Create vertices and indices
    int trianglesBuilt = 0;
    while (trianglesBuilt < nrOfTriangles) {
        vertices.emplace_back(glm::vec3(radius * cosf(2.0f * PI * (float(trianglesBuilt) / float(nrOfTriangles))), radius * sinf(2.0f * PI * (float(trianglesBuilt) / float(nrOfTriangles))), 0), color);
        indices.push_back(trianglesBuilt);
        ++trianglesBuilt;
    }

    indices.push_back(nrOfTriangles);
    indices.emplace_back(1);

    head->InitFromData(vertices, indices);
    head->SetDrawMode(GL_TRIANGLE_FAN);

    return head;
}