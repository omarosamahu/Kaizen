// General Headers 
#include <stdio.h>
#include <iostream>
//Third party
//#include <spdlog/spdlog.h>
//#include <spdlog/sinks/stdout_color_sinks.h>
//STL
#include <array>
#include <list>
#include <any>
#include <functional>
#include <unordered_map>
#include <memory>
#include <utility>
#include<typeinfo>
// Types
#include <cstdint>

// Macros
#define MAX_PARAM 4

#ifdef EXPORT_DLL
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT __declspec(dllimport)
#endif // !EXPORT_DLL


using EventId = uint32_t;