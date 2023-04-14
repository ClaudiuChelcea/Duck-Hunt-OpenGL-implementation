#version 330

// Input
// TODO(student): Get values from vertex shader
in vec3 fragment_position;
in vec3 fragment_normal;
in vec2 fragment_texture;
in vec3 fragment_color;

// Output
layout(location = 0) out vec4 out_color;
layout(location = 1) out vec4 out_normal;
layout(location = 2) out vec3 out_texture;

void main()
{
    // TODO(student): Write pixel out color
    out_color = vec4(fragment_normal, 1);
    out_normal = vec4(fragment_normal, 1);
	out_texture = vec3(fragment_texture, 1);
}
