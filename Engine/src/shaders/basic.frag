#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_pos;

//in vec4 pos;

in DATA 
{
	vec4 position;
	vec4 color;
}fs_in;
	
void main() {
	float dist		= length(fs_in.position.xy - light_pos);
	float brightness 	= dist * (-0.00001);
	float alpha		= 1.0 / (dist * 0.01);  
	
	float intensity 	= 1.0 / dist;
	color = fs_in.color * intensity;	
	
	//color = fs_in.color * alpha + brightness;	
}





