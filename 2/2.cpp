#include "myhead.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
void IncreaseProperty(float* property, float points, int code) {
	if (code == 1) {
		if (*property + points < 1) *property += points;
		else *property = 1;
	}
	if (code == 0)*property += points;
};

void ChangeRGB(Pixel * object, int RGB[3]) {
	object->R = RGB[0];
	object->G = RGB[1];
	object->B = RGB[2];

};

void PixelInfoPrint(Pixel* object) {
	printf("RED: %d, GREEN: %d, BLUE:%d, transperency:%f", object->R, object->G, object->B, object->transparency);
};

void ImageInfoPrint(Image* object) {
	printf("Image name: %s, width: %d, height: %d", object->name, object->width, object->height);
};

void FilterInfoPrint(Filter* object) {
	printf("Intensity:%f\n", object->intensity);
	if (object->type == 0)printf("Filter type: NONE");
	if (object->type == 1) printf("Filter type: Dark");
	if (object->type == 2)printf("Filter type : Light");

};

void LayerInfoPrint(Layer* object) {
	printf("Opacity:%f, visible:%d, number:%d", object->opacity, object->visible, object->number);
};

void FileInfoPrint(File* object) {
	printf("Name:%s, path: %s", object->name, object->path);
};
void PixelSet(Pixel* object) {
	object->R = 0;
	object->G = 0;
	object->B = 0;
	object->transparency = 1;
};

void FilterSet(Filter* object) {
	object->type = 0;
	object->intensity = 0;
};

void LayerSet(Layer* object) {
	object->number = 0;
	object->opacity = 1;
	object->visible = 1;

};

void FileSet(File* object) {
	strcpy(object->name, "");
	strcpy(object->path, "");

};

void ColorCorrectionSet(ColorCorrection* object) {
	object->brightness = 1;
	object->contrast = 1;
	object->saturation = 1;
};
void BlendModeSet(BlendMode* object) {
	object->opacity = 1;
	object->type = 0;
};

void DarkFilterApply(Filter* object, ColorCorrection* object2) {
	if (object->type == 1) {
		object2->brightness = 0.6 * object->intensity;
		object2->contrast = 1.2 * object->intensity;
		object2->saturation = 1.2 * object->intensity;
	}
};

void LightFilterApply(Filter* object, ColorCorrection* object2) {
	if (object->type == 2) {
		object2->brightness = 1.2 * object->intensity;
		object2->contrast = 0.6 / object->intensity;
		object2->saturation = 0.7 / object->intensity;
	}
};
void LayerIncrease(Layer* object) {
	object->number++;
};
void LayerDecrease(Layer* object) { 
	if (object->number > 0)object->number--; 
};

int main()
{
	Pixel* pixel;
	pixel = (Pixel*)malloc(sizeof(Pixel));
	pixel->R = 15;
	pixel->G = 15;
	pixel->B = 15;
	pixel->transparency = 0.4;
	PixelInfoPrint(pixel);
}
