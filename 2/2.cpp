#include "myhead.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
void IncreaseProperty(float* property, float points) {
	if (*property + points < 1) *property += points;
	else *property = 1;
};

void ChangeRGB(Pixel * object, int RGB[3]) {
	object->R = RGB[0];
	object->G = RGB[1];
	object->B = RGB[2];

};

void PixelInfoPrint(Pixel* object) {
	printf("RED: %d, GREEN: %d, BLUE:%d, TRANSPERENCY:%f", object->R, object->G, object->B, object->transparency);
};

void PixelSizeInfo(Image* object) {
	printf("Width: %d, Height: %d, Pixel size: %d", object->width, object->height, (object->height)*(object->width));
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
