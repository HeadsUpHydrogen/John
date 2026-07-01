#pragma once

#ifdef JOHN_EXPORTS
#define JOHN_API __declspec(dllexport)
#else
#define JOHN_API __declspec(dllimport)
#endif

class JOHN_API Universe {

public:
	/// <summary>Default constructor for the Universe will default to a size of 1024x1024</summary>
	Universe();

	/// <summary>Defines a Universe of a custom size</summary>
	///<param name="Width">The X Size of the Universe</param>
	///<param name="Height">The Y Size of the Universe</param>
	Universe(int Width, int Height);

	/// <summary>Not defining this idec</summary>
	~Universe();

protected:
	float XSize;
	float YSize;
public:
	/// <summary>Gets the width of the Universe</summary>
	/// <returns>Universe width</returns>
	const int GetWidth();

	/// <summary>Gets the height of the Universe</summary>
	/// <returns>Universe height</returns>
	const int GetHeight();
};

