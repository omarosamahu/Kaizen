#pragma once
#ifndef EXPORT_DLL
#define EXPORT_DLL __declspec(dllimport)
#endif // !EXPORT_DLL

namespace Imp {
class  EXPORT_DLL Kaizen  {
public:
	Kaizen();
	~Kaizen();
	void printKaizen();
	};
}