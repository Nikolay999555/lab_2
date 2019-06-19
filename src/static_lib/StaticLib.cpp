#include "StaticLib.h"
#include <stdexcept>
#include <iomanip>

namespace MyLib
{
	int StaticLib::FileSize(const char* filename)
	{
		std::ifstream file_read;
		file_read.open(filename, std::ios::in);

		char temp[128];
		int size = 0;
		while (file_read >> temp) //циклом получаем количество записанных в файл элементов
		{
			size++;
		}
		file_read.close();
		return size;
	}

	void StaticLib::ReadFile(const char* filename, double* read_array, int& size)
	{
		std::ifstream file_read;
		file_read.open(filename, std::ios::in); //открываем файл для чтения

		char temp[128];
		int i = 0;
		while (file_read >> temp) //циклом считываем в массив read_array данные из файла
		{
			char* end;
			double double_val = strtod(temp, &end);
			if (temp != end)
			{
				read_array[i] = double_val;
				i++;
			}
		}
		size = i;
		file_read.close(); //закрываем файл
	}

	void StaticLib::WriteFile(const char* filename, double* data, int& size)
	{
		std::ofstream file_write;
		file_write.open(filename, std::ios::out); //открываем файл для записи

		for (int i = 0; i < size; i++) //пишем массив в файл
		{
			file_write <<std::fixed<<std::setprecision(10) << data[i] << ' ';
		}
	}
}

