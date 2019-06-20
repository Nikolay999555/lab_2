#include <iostream>
#include <windows.h>
#include "../src/static_lib/StaticLib.h"
#include "../src/qsort/QSort.h"
#include <gtest/gtest.h>
using namespace std;


TEST(FullSizeFile, empty)
{
	int temp_size = 0;
	temp_size = MyLib::StaticLib::FileSize("..//..//files//file_empty.txt");
	EXPECT_EQ(0, temp_size);
}
TEST(FullSizeFile, numbers)
{
	int temp_size = 0;
	temp_size = MyLib::StaticLib::FileSize("..//..//files/file_numbers.txt");
	EXPECT_EQ(11, temp_size);
}
TEST(FullSizeFile, numbers_and_characters)
{
	int temp_size = 0;
	temp_size = MyLib::StaticLib::FileSize("..//..//files//numbers_and_characters.txt");
	EXPECT_EQ(15, temp_size);
}
//
TEST(ReadFile, empty)
{
	int temp_size = 0;
	double* temp_read_array = nullptr;
	MyLib::StaticLib::ReadFile("..//..//files//file_empty.txt", temp_read_array, temp_size);
	EXPECT_EQ(0, temp_size);
	delete[] temp_read_array;
}
TEST(ReadFile, numbers)
{
	int temp_size = 11;
	double* temp_read_array = new double[temp_size];
	MyLib::StaticLib::ReadFile("..//..//files//file_numbers.txt", temp_read_array, temp_size);

	double array_comparison[11] = { 12 ,4.5 ,- 90 ,67 ,11.00001 ,9.54 ,- 5.45 ,0 ,0.001 ,- 0.001 ,0 };
	for (int i=0;i<temp_size;i++)
	{
		EXPECT_EQ(array_comparison[i], temp_read_array[i]);
	}

	delete[] temp_read_array;
}
TEST(ReadFile, numbers_and_characters)
{
	int temp_size = 9;
	double* temp_read_array = new double[temp_size];
	MyLib::StaticLib::ReadFile("..//..//files//numbers_and_characters.txt", temp_read_array, temp_size);
	double array_comparison[9] = {90,-90,0.1,0.2,0.3,0.2,0.2,1,0};

	for (int i = 0; i < temp_size; i++)
	{
		EXPECT_EQ(array_comparison[i], temp_read_array[i]);
	}
	delete[] temp_read_array;
}
//
TEST(QSort,numbers)
{
	double array_comparison[11] = { 12 ,4.5 ,-90 ,67 ,11.00001 ,9.54 ,-5.45 ,0 ,0.001 ,-0.001 ,0 };
	QuickSort(array_comparison, 0, 10);
	for (int i=0;i<10;i++)
	{
		ASSERT_LE(array_comparison[i], array_comparison[i+1]);
	}
}
TEST(QSort, numbers_and_characters)
{
	double array_comparison[9] = { 90,-90,0.1,0.2,0.3,0.2,0.2,1,0 };
	QuickSort(array_comparison, 0, 8);
	for (int i = 0; i < 8; i++)
	{
		ASSERT_LE(array_comparison[i], array_comparison[i + 1]);
	}
}
//
TEST(WriteFile,numbers)
{
	int temp_size = 11;
	double array_comparison[11] = { 12 ,4.5 ,-90 ,67 ,11.1111111 ,9.54 ,-5.45 ,0 ,0.001 ,-0.001 ,0 };
	MyLib::StaticLib::WriteFile("..//..//files//file_numbers_out.txt", array_comparison, temp_size);
	double* temp_read_array = new double[temp_size];
	MyLib::StaticLib::ReadFile("..//..//files//tests/file_numbers_out.txt", temp_read_array, temp_size);
	for (int i=0;i<temp_size;i++)
	{
		ASSERT_DOUBLE_EQ(array_comparison[i], temp_read_array[i]);
	}
}
TEST(WriteFile, numbers_and_characters)
{
	int temp_size = 9;
	double array_comparison[9] = { 90,-90,0.1,0.2,0.3,0.2,0.2,1,0 };
	MyLib::StaticLib::WriteFile("..//..//files//file_numbers_and_characters_out.txt", array_comparison, temp_size);
	double* temp_read_array = new double[temp_size];
	MyLib::StaticLib::ReadFile("..//..//files//file_numbers_and_characters_out.txt", temp_read_array, temp_size);
	for (int i = 0; i < temp_size; i++)
	{
		ASSERT_DOUBLE_EQ(array_comparison[i], temp_read_array[i]);
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
//
	int size = 0;
	double* read_array = nullptr;
	size=MyLib::StaticLib::FileSize("..//..//files//file_in.txt");
	read_array=new double[size];
	MyLib::StaticLib::ReadFile("..//..//files//file_in.txt",read_array,size);
	QuickSort(read_array, 0, size - 1);
	MyLib::StaticLib::WriteFile("..//../files//file_out.txt", read_array, size);
	delete[] read_array;
//
	cout << "//////\nFile_in.txt successfully sorted"<<endl;
	system("pause");
	return 0;
}
