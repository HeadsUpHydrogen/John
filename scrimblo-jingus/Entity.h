#pragma once

#ifdef JOHN_EXPORTS
#define JOHN_API __declspec(dllexport)
#else
#define JOHN_API __declspec(dllimport)
#endif

#include "Universe.h"
class JOHN_API Entity {
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

