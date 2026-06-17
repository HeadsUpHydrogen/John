#pragma once

#include "Universe.h"
class Entity {
	public:
		Entity();
		Entity(int XSpawn, int YSpawn, int Size, Universe* Context);
		~Entity();

	protected:
		float XPos, YPos;
		int Scale;
		Universe* Container;

	public:
		const float GetXPosition();
		const float GetYPosition();
		const int GetScale();

		float SetXPosition(float NewX);
		float SetYPosition(float NewY);
		void SetPosition(float NewX, float NewY);
		int SetScale(int NewScale);
};

