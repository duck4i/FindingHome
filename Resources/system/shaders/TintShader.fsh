//	TINT FRAGMENT SHADER

#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_color;

void main()
{
	//float x = gl_FragCoord;
	gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
	gl_FragColor.r = cos(gl_FragCoord.x);	
}