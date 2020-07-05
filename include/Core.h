#include <stdio.h>
#include <iostream>
#include <memory>

#ifdef EXPORT_DLL
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT __declspec(dllimport)
#endif // !EXPORT_DLL