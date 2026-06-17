#define MICHAEL 67

#include <stdio.h>
#include "Universe.h"
#include "Entity.h"

int main(int argc, char* argv[]) {
	
	Universe* JohnUniverse = new Universe();
	printf("Universe created with a width of %d, and a height of %d\n", JohnUniverse->GetWidth(), JohnUniverse->GetHeight());
	Entity* JohnEntity = new Entity(16, 16, 32, JohnUniverse);
	printf("Entity spawned at %f,%f with a size of %d\n", JohnEntity->GetXPosition(), JohnEntity->GetYPosition(), JohnEntity->GetScale());
	JohnEntity->SetPosition(1077.f, 44.9f);
	printf("Entity moved to %f, %f\n", JohnEntity->GetXPosition(), JohnEntity->GetYPosition());
	delete JohnUniverse;
	delete JohnEntity;
	return 0;
}
