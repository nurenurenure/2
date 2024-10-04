#include <string.h>
struct Image {
	int width;
	int height;
	float color_depth;
	char name[1000];
};
struct Pixel {
	int R;
	int G;
	int B;
	float transparency;
};
struct Filter {
	int type;
	float intensity;
};
struct Layer {
	float opacity;
	bool visible;
	int number;
};
struct File {
	char name[1000];
	char path[1000];
};
struct ColorCorrection {
	float brightness;
	float contrast;
	float saturation;
};
struct BlendMode {
	int type;
	float opacity;
};

void IncreaseProperty(float* property, float points);
void ChangeRGB(Pixel* object, int RGB[3]);
void PixelInfoPrint(Pixel* object);
void PixelSizeInfo(Image* object);
void PixelSet(Pixel* object);
void FilterSet(Filter* object);
void LayerSet(Layer* object);
void FileSet(File* object);
void ColorCorrectionSet(ColorCorrection* object);
void BlendModeSet(BlendMode* object);

