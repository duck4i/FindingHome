//	TINT VERTEX SHADER

uniform vec4 a_color;
uniform vec3 a_position;

varying vec4 v_color;

void main()
{
	//v_color = vec4(0.0, 1.0, 0.0, 1.0);
	v_color = a_color;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;	
}