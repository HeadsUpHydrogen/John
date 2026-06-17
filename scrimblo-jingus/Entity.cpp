#include "Entity.h"
#include "Debug.h"

Entity::Entity() {
	ERROR("Entities must have a universe! Entity Container is nullptr!")
	XPos = 0.f;
	YPos = 0.f;
	Scale = 32;
	Container = nullptr;
	
}

Entity::Entity(int XSpawn, int YSpawn, int Size, Universe* Context) {
	XPos = (float) XSpawn;
	YPos = (float) YSpawn;
	Scale = Size;
	Container = Context;
}

Entity::~Entity() {

}

const float Entity::GetXPosition() {return XPos;}
const float Entity::GetYPosition() { return YPos; }
const int Entity::GetScale() { return Scale; }

float Entity::SetXPosition(float NewX)
{
	if (NewX < 0.f) { NewX = 0.f; }
	else if (Container != nullptr && NewX + (float) Scale > Container->GetWidth()) { NewX = Container->GetWidth() - (float) Scale; }
	XPos = NewX;
	return XPos;
}

float Entity::SetYPosition(float NewY)
{
	if (NewY < 0.f) { NewY = 0.f; }
	else if (Container != nullptr && NewY + (float) Scale > Container->GetHeight()) { NewY = Container->GetHeight() - (float) Scale; }
	XPos = NewY;
	return YPos;
}

void Entity::SetPosition(float NewX, float NewY) {
	SetXPosition(NewX);
	SetYPosition(NewY);
}

int Entity::SetScale(int NewScale) {
	Scale = NewScale;
	return Scale;
}


