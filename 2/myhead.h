#include <string.h>
struct Image {
	int width;
	int height;
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
	Image* image;
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

struct Palette {
	Pixel* pixels;
	int size;

};

void IncreaseProperty(float* property, float points, int code);
void ChangeRGB(Pixel* object, int RGB[3]);

void PixelSet(Pixel* object);
void FilterSet(Filter* object);
void LayerSet(Layer* object);
void FileSet(File* object);
void ColorCorrectionSet(ColorCorrection* object);
void BlendModeSet(BlendMode* object);

void DarkFilterApply(Filter* object, ColorCorrection* object2);
void LightFilterApply(Filter* object, ColorCorrection* object2);

void PixelInfoPrint(Pixel* object);
void ImageInfoPrint(Image* object);
void FilterInfoPrint(Filter* object);
void LayerInfoPrint(Layer* object);
void FileInfoPrint(File * object);

void LayerIncrease(Layer* object);
void LayerDecrease(Layer* object);

void CreatePallete(Palette* object, int CurrSize);