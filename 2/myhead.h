struct Image {
	int width;
	int height;
	int color_depth;
	char name[1000];
};
struct Pixel {
	int R;
	int G;
	int B;
	int transparency;
};
struct Filter {
	char name[1000];
	float intensity;
};
struct Layer {
	float opacity;
	bool visible;
};
struct Pallete {
	Pixel[1000];
};
struct File {
	char name[1000];
	char path[1000];
};
struct ColorCorrection {
	float brightness;
	float contrast;
	float saturation;
	float hue;
};
struct BlendMode {
	char type[1000];
	float opacity;
	Pixel;
};


