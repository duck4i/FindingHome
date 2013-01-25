#ifndef __COLOR_SPACE_UTILS__
#define __COLOR_SPACE_UTILS__

typedef struct ColorHSLF
{
	float h;
	float s;
	float l;
	void clear() { h = s = l = 0.0f; }
	bool set() { return h != 0 || s != 0 || l != 0; }
	bool equals(ColorHSLF a) { return h == a.h && s == a.s && l == a.l; }
} ColorHSLF, *LPColorHSLF;

typedef struct ColorHSL
{
	unsigned int h;
	unsigned int s;
	unsigned int l;
	void clear() { h = s = l = 0; }
	bool set() { return h != 0 || s != 0 || l != 0; }
	bool equals(ColorHSL a) { return h == a.h && s == a.s && l == a.l; }
} ColorHSL, *LPColorHSL;

static inline void HSL2RGB(float h, float s, float l, float* outR, float* outG, float* outB)
{
	float			temp1,
  temp2;
	float			temp[3];
	int				i;
	
	// Check for saturation. If there isn't any just return the luminance value for each, which results in gray.
	if(s == 0.0) {
		if(outR)
			*outR = l;
		if(outG)
			*outG = l;
		if(outB)
			*outB = l;
		return;
	}
	
	// Test for luminance and compute temporary values based on luminance and saturation 
	if(l < 0.5)
		temp2 = l * (1.0 + s);
	else
		temp2 = l + s - l * s;
  temp1 = 2.0 * l - temp2;
	
	// Compute intermediate values based on hue
	temp[0] = h + 1.0 / 3.0;
	temp[1] = h;
	temp[2] = h - 1.0 / 3.0;
  
	for(i = 0; i < 3; ++i) {
		
		// Adjust the range
		if(temp[i] < 0.0)
			temp[i] += 1.0;
		if(temp[i] > 1.0)
			temp[i] -= 1.0;
		
		
		if(6.0 * temp[i] < 1.0)
			temp[i] = temp1 + (temp2 - temp1) * 6.0 * temp[i];
		else {
			if(2.0 * temp[i] < 1.0)
				temp[i] = temp2;
			else {
				if(3.0 * temp[i] < 2.0)
					temp[i] = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - temp[i]) * 6.0;
				else
					temp[i] = temp1;
			}
		}
	}
	
	// Assign temporary values to R, G, B
	if(outR)
		*outR = temp[0];
	if(outG)
		*outG = temp[1];
	if(outB)
		*outB = temp[2];
}


static inline void RGB2HSL(float r, float g, float b, float* outH, float* outS, float* outL)
{
  r = r/255.0f;
  g = g/255.0f;
  b = b/255.0f;
  
  
  float h,s, l, v, m, vm, r2, g2, b2;
  
  h = 0;
  s = 0;
  l = 0;
  
  v = MAX(r, g);
  v = MAX(v, b);
  m = MIN(r, g);
  m = MIN(m, b);
  
  l = (m+v)/2.0f;
  
  if (l <= 0.0){
    if(outH)
			*outH = h;
		if(outS)
			*outS = s;
		if(outL)
			*outL = l;
    return;
  }
  
  vm = v - m;
  s = vm;
  
  if (s > 0.0f){
    s/= (l <= 0.5f) ? (v + m) : (2.0 - v - m); 
  }else{
    if(outH)
			*outH = h;
		if(outS)
			*outS = s;
		if(outL)
			*outL = l;
    return;
  }
  
  r2 = (v - r)/vm;
  g2 = (v - g)/vm;
  b2 = (v - b)/vm;
  
  if (r == v){
    h = (g == m ? 5.0f + b2 : 1.0f - g2);
  }else if (g == v){
    h = (b == m ? 1.0f + r2 : 3.0 - b2);
  }else{
    h = (r == m ? 3.0f + g2 : 5.0f - r2);
  }
  
  h/=6.0f;
  
  if(outH)
    *outH = h;
  if(outS)
    *outS = s;
  if(outL)
    *outL = l;
  
}

static inline ColorHSLF HSLDiff(ColorHSLF from, ColorHSLF to, float steps)
{
	ColorHSLF r;
	r.clear();
	r.h = (to.h - from.h) / steps;
	r.s = (to.s - from.s) / steps;
	r.l = (to.l - from.l) / steps;
	return r;
}

static inline void HSLStep(ColorHSLF &target, ColorHSLF s)
{
	target.h += s.h;
	target.s += s.s;
	target.l += s.l;
}

static inline int RGBToInt(int r, int g, int b)
{
	int hexcolor = (r << 16) + (g << 8) + b;
	return hexcolor;
}

static inline int RGBAToInt(int r, int g, int b, int a)
{
	int value = ((a & 0xFF) << 24) | //alpha
            (((int)r & 0xFF) << 16) | //red
            (((int)g & 0xFF) << 8)  | //green
            (((int)b & 0xFF) << 0); //blue
	return value;
}

#endif