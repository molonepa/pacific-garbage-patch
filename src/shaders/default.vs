#version 400

in vec3 vert_position;
in vec2 vert_uv;
in vec3 vert_normal;

out vec4 colour;

void main() {
	gl_Position = vec4(vert_position, 1.0);
	colour = vec4(0.25, 0.8, 0.6, 1.0);
}