//	TINT FRAGMENT SHADER

#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_color;

void main()
{
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 0.3) * v_color;
	gl_FragColor = v_color;
}