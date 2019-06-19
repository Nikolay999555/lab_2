#include <fstream>

namespace MyLib
{
	class StaticLib {
	public:
		static int FileSize(const char* filename);
		static void ReadFile(const char* filename, double* read_array, int& size);
		static void WriteFile(const char* filename, double* data, int& size);
	};
}