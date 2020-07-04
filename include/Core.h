#ifdef EXPORT_DLL
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT __declspec(dllexport)
#endif // !EXPORT_DLL