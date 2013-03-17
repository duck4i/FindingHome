//	TINT VERTEX SHADER

uniform vec4 a_color;
uniform vec3 a_position;

varying vec4 v_color;

void main()
{
	gl_FrontColor = gl_Color;
	v_color = gl_FrontColor;
	
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;	
	//gl_Position = gl_Vertex - 0.5;
}