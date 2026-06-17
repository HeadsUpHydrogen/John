#include "Universe.h"
Universe::Universe() {
	XSize = 1024.f;
	YSize = 1024.f;
}

Universe::Universe(int Width, int Height) {
	XSize = (float) Width;
	YSize = (float) Height;
}

Universe::~Universe() {

}

const int Universe::GetWidth() {return (int) XSize;}

const int Universe::GetHeight() {return (int) YSize;}
