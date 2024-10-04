﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "myhead.h"


void IncreaseProperty(float property, float points, int code) {
	if (code == 1) {//1 - код свойства, которое не может превышать 1.(Например прозрачность)
		if (property + points < 1) property += points;
		else property = 1;
	}
	if (code == 0)property += points;
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
	object->transparency = 0;
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
		object2->brightness = (0.6 * object->intensity);
		object2->contrast = (1.2 * object->intensity);
		object2->saturation = (1.2 * object->intensity);
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


void CreatePallete(Palette* object, int CurrSize) {
	object->pixels = (Pixel*)malloc(CurrSize * sizeof(Pixel));
	for (int i = 0; i < CurrSize; i++) {
		object->pixels[i].R = 0;
		object->pixels[i].G = 0;
		object->pixels[i].B = 0;
		object->pixels[i].transparency = 0;
	}
};

int main()
{
	//пример использования функции вывода информации об отдельном пикселе
	Pixel* pixel;
	pixel = (Pixel*)malloc(sizeof(Pixel));
	pixel->R = 15;
	pixel->G = 15;
	pixel->B = 15;
	pixel->transparency = 0.4;
	PixelInfoPrint(pixel);
	printf("\n");
	//Изменение цвета пикселя
	int RGB[3] = { 1, 3, 4 };
	ChangeRGB(pixel, RGB);
	PixelInfoPrint(pixel);
	//Создание нового фильтра и вывод информации
	Filter* filter;
	filter = (Filter*)malloc(sizeof(Filter));
	FilterSet(filter);
	FilterInfoPrint(filter);
	//информация об изображении
	printf("\n");
	Image* image;
	image = (Image*)malloc(sizeof(Image));
	image->width = 4;
	image->height = 8;
	strcpy(image->name, "hello");
	ImageInfoPrint(image);
	//увеличение отдельного параметра
	printf("\n");
	IncreaseProperty(pixel->transparency, 0.4, 1);
	printf("%f", pixel->transparency);

}
