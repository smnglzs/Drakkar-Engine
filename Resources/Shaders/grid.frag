#version 450 core

layout(binding = 0) uniform sampler2D tex;

uniform vec4 tint = {1.f, 1.f, 1.f, 1.f};
uniform vec2 viewport;

in VS_OUT {
	vec2 uv;
} frag;

out vec4 fragColor;

void main() {        
	vec4 texColor = texture(tex, frag.uv);
    fragColor = texColor * tint;
}