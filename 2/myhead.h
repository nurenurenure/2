#include <string.h>
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
	float transparency;
};
struct Filter {
	char name[1000];
	float intensity;
};
struct Layer {
	float opacity;
	bool visible;
	int number;
};
struct Pallete {
	int colors[1000][1000];

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
};

int pixel_size(int width, int height);
void increase_property(float* property, float points);
void change_name(char* name[], char new_name[]);
void change_RGB(int* R, int* G, int* B, int RGB[3]);
void switch_layer_mode(bool* vision);
void increase_layer(int* number, int total_numb);
void decrease_layer(int* number, int total_numb);




