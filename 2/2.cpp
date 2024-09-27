#include "myhead.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>

int pixel_size(int width, int height){
	return width*height;
}
void increase_property(float* property, float points) {
	if (*property + points < 1) *property += points;
	else *property = 1;
}

void change_name(char* name[], char new_name[]) {
	strcpy(*name, new_name);
};
void change_RGB(int* R, int* G, int* B, int RGB[3]) {
	*R = RGB[0];
	*G = RGB[1];
	*B = RGB[2];
};
void switch_layer_mode(bool* vision) {
	if (*vision == true) *vision = false;
	else *vision = true;
};
void increase_layer(int* number, int total_numb) {
	if (*number < total_numb) *number += 1;

};
void decrease_layer(int* number, int total_numb) {
	if (*number > 0) *number -= 1;
};

int main()
{
	ColorCorrection meow;
	meow.brightness = 0.5;
	increase_property(&meow.brightness, 0.4);
	printf("Новое значение яркости: %f", meow.brightness);


}
