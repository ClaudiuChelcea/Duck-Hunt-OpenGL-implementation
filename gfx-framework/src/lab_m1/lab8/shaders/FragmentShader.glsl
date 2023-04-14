#version 330

// Get color value from vertex shader
in vec3 world_position;
in vec3 world_normal;

// Uniforms for light properties
uniform vec3 light_direction;
uniform vec3 light_position;
uniform vec3 eye_position;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

uniform vec3 object_color;
uniform int type_of_light;
uniform float cut_off_angle;

// Uniforms for light properties
uniform vec3 light_direction2;
uniform vec3 light_position2;
uniform int type_of_light2;

layout(location = 0) out vec4 out_color;

void main()
{
	

	// Compute light
	float light = 0.f;

	if (type_of_light == 1)
	{
		vec3 N = normalize(world_normal);
		vec3 L = normalize(light_position - world_position);
		vec3 V = normalize(eye_position - world_position);
		vec3 H = normalize(L + V);
		vec3 R = normalize(reflect(L, world_normal));

		// Define ambient light component
		float ambient_light = 0.1f;

		// Compute diffuse light component
		float diffuse_light = material_kd * max(dot(normalize(N), L), 0.f);

		// Compute specular light component
		float specular_light = 0.f;

		if (diffuse_light > 0.f)
		{
			specular_light = material_ks * pow(max(dot(N, H), 0), material_shininess);
		}

		float cut_off_rad		= radians(cut_off_angle);
		float spot_light		= dot(-L, light_direction);
		float spot_light_limit	= cos(cut_off_rad);
		
		if (spot_light > spot_light_limit)
		{	 
			// Quadratic attenuation
			float linear_att		= (spot_light - spot_light_limit) / (1.f - spot_light_limit);
			float light_att_factor	= linear_att * linear_att;
			light					= ambient_light + light_att_factor * (diffuse_light + specular_light);
		} else
		{
			light = ambient_light;  // There is no spot light, but there is light from other objects
		}
	} else
	{
		vec3 N = normalize(world_normal);
		vec3 L = normalize(light_position - world_position);
		vec3 V = normalize(eye_position - world_position);
		vec3 H = normalize(L + V);
		vec3 R = normalize(reflect(L, world_normal));

		// Define ambient light component
		float ambient_light = 0.1f;

		// Compute diffuse light component
		float diffuse_light = material_kd * max(dot(normalize(N), L), 0.f);

		// Compute specular light component
		float specular_light = 0.f;

		if (diffuse_light > 0.f)
		{
			specular_light = material_ks * pow(max(dot(N, H), 0), material_shininess);
		}

		float cut_off_rad		= radians(cut_off_angle);
		float spot_light		= dot(-L, light_direction);
		float spot_light_limit	= cos(cut_off_rad);

		float d						= distance(light_position, world_position);
		float attenuation_factor	= 1.f / max(d * d, 1.f);
		light						= ambient_light + attenuation_factor * (diffuse_light + specular_light);
	}






	// Compute light2
	float light2 = 0.f;

	if (type_of_light2 == 1)
	{
		vec3 N = normalize(world_normal);
		vec3 L = normalize(light_position2 - world_position);
		vec3 V = normalize(eye_position - world_position);
		vec3 H = normalize(L + V);
		vec3 R = normalize(reflect(L, world_normal));

		// Define ambient light component
		float ambient_light = 0.1f;

		// Compute diffuse light component
		float diffuse_light = material_kd * max(dot(normalize(N), L), 0.f);

		// Compute specular light component
		float specular_light = 0.f;

		if (diffuse_light > 0.f)
		{
			specular_light = material_ks * pow(max(dot(N, H), 0), material_shininess);
		}

		float cut_off_rad		= radians(cut_off_angle);
		float spot_light		= dot(-L, light_direction2);
		float spot_light_limit	= cos(cut_off_rad);
		
		if (spot_light > spot_light_limit)
		{	 
			// Quadratic attenuation
			float linear_att		= (spot_light - spot_light_limit) / (1.f - spot_light_limit);
			float light_att_factor	= linear_att * linear_att;
			light2					= ambient_light + light_att_factor * (diffuse_light + specular_light);
		} else
		{
			light2 = ambient_light;  // There is no spot light, but there is light from other objects
		}
	} else
	{
		vec3 N = normalize(world_normal);
		vec3 L = normalize(light_position2 - world_position);
		vec3 V = normalize(eye_position - world_position);
		vec3 H = normalize(L + V);
		vec3 R = normalize(reflect(L, world_normal));

		// Define ambient light component
		float ambient_light = 0.1f;

		// Compute diffuse light component
		float diffuse_light = material_kd * max(dot(normalize(N), L), 0.f);

		// Compute specular light component
		float specular_light = 0.f;

		if (diffuse_light > 0.f)
		{
			specular_light = material_ks * pow(max(dot(N, H), 0), material_shininess);
		}

		float cut_off_rad		= radians(cut_off_angle);
		float spot_light		= dot(-L, light_direction2);
		float spot_light_limit	= cos(cut_off_rad);
		float d						= distance(light_position2, world_position);
		float attenuation_factor	= 1.f / max(d * d, 1.f);
		light2						= ambient_light + attenuation_factor * (diffuse_light + specular_light);
	}

	// Write pixel out color
	vec3 colour = object_color * (light + light2);

	out_color = vec4(colour, 1.f);
}
