#include "AlgorithmsTest.h"
#include <gtest/gtest.h>
#include "../../ADSLibrary/Algorithms/ArraySearchingAlgorithms/ArraySearchingAlgorithms.h"
#include "../../ADSLibrary/Algorithms/SortingAlgorithms/SortingAlgorithms.h"

using namespace ADSLibrary::Algorithms::ArraySearchingAlgorithms;

/*
* Soubor slou��c� k testov�n� algoritm� pro vyhled�v�n�/�azen� v poli
*/

/*
* Pomocn� struktura pro testov�n�
*/
struct AlgStructTest : testing::Test
{
	void ReportArray(int a[], const int n)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << a[i] << "\t";
		}
		std::cout << "\n";
	}
};


/*
* Unit test Algorithms::ArraySearchingAlgorithms::ArraySearchingAlgorithms a Algorithms::SortingAlgorithms::SortingAlgorithms.h
* Test algoritm� pro pole o sud�m po�tu prvk�.
* LinearSearch1, LinearSearch2, LinearSearchRecursive1, LinearSearchRecursive2, InsertSort, BinarySearch1, BinarySearch2, BinarySearch3
* BinarySearchRecursive1, BinarySearchRecursive2, BinarySearchRecursive3
* @param AlgStructTest n�zev struktury,
* @param SearchingAlgTest n�zev unit testu
*/
TEST_F(AlgStructTest, SearchingAlgTest)
{
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	EXPECT_EQ(true, LinearSearch1(a, numOfElements, 2));
	EXPECT_EQ(true, LinearSearch1(a, numOfElements, 1));
	EXPECT_EQ(false, LinearSearch1(a, numOfElements, 33));
	EXPECT_EQ(true, LinearSearch1(a, numOfElements, 68));

	EXPECT_EQ(1, LinearSearch2(a, numOfElements, 2));
	EXPECT_EQ(8, LinearSearch2(a, numOfElements, 1));
	EXPECT_EQ(-1, LinearSearch2(a, numOfElements, 33)); // -1 prvek nen� v dan�m poli
	EXPECT_EQ(5, LinearSearch2(a, numOfElements, 68));

	EXPECT_EQ(true, LinearSearchRecursive1(a, numOfElements, 2, 0));
	EXPECT_EQ(true, LinearSearchRecursive1(a, numOfElements, 1, 0));
	EXPECT_EQ(false, LinearSearchRecursive1(a, numOfElements, 33, 0));
	EXPECT_EQ(true, LinearSearchRecursive1(a, numOfElements, 68,0 ));

	EXPECT_EQ(1, LinearSearchRecursive2(a, numOfElements, 2, 0));
	EXPECT_EQ(8, LinearSearchRecursive2(a, numOfElements, 1, 0));
	EXPECT_EQ(-1, LinearSearchRecursive2(a, numOfElements, 33, 0)); 
	EXPECT_EQ(5, LinearSearchRecursive2(a, numOfElements, 68, 0));


	ADSLibrary::Algorithms::SortingAlgorithms::InsertSort(a, numOfElements); //sort pot�ebn� pro bin�rn� vyhled�v�n�

	EXPECT_EQ(true, BinarySearch1(a, numOfElements, 2));
	EXPECT_EQ(true, BinarySearch1(a, numOfElements, 1));
	EXPECT_EQ(false, BinarySearch1(a, numOfElements, 33));
	EXPECT_EQ(true, BinarySearch1(a, numOfElements, 68));

	EXPECT_EQ(1, BinarySearch2(a, numOfElements, 2));
	EXPECT_EQ(0, BinarySearch2(a, numOfElements, 1));
	EXPECT_EQ(9, BinarySearch2(a, numOfElements, 12071));
	EXPECT_EQ(5, BinarySearch2(a, numOfElements, 47));
	EXPECT_EQ(-1, BinarySearch2(a, numOfElements, 33));
	EXPECT_EQ(6, BinarySearch2(a, numOfElements, 68));

	EXPECT_EQ(1, BinarySearch3(a, numOfElements, 2));
	EXPECT_EQ(0, BinarySearch3(a, numOfElements, 1));
	EXPECT_EQ(9, BinarySearch3(a, numOfElements, 12071));
	EXPECT_EQ(5, BinarySearch3(a, numOfElements, 47));
	EXPECT_EQ(-5, BinarySearch3(a, numOfElements, 33)); //vrac� z�porn� ��slo, je� je bitov�m dopl�kem indexu v poli, kam m��e b�t prvek vlo�en bez naru�en� posloupnosti

	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(false, BinarySearchRecursive1(a, 0, numOfElements - 1, 33));
	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 68));

	EXPECT_EQ(true, BinarySearchRecursive1a(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(true, BinarySearchRecursive1a(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(false, BinarySearchRecursive1a(a, 0, numOfElements - 1, 33));
	EXPECT_EQ(true, BinarySearchRecursive1(a, 0, numOfElements - 1, 68));

	EXPECT_EQ(1, BinarySearchRecursive2(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(0, BinarySearchRecursive2(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(9, BinarySearchRecursive2(a, 0, numOfElements - 1, 12071));
	EXPECT_EQ(5, BinarySearchRecursive2(a, 0, numOfElements - 1, 47));
	EXPECT_EQ(-1, BinarySearchRecursive2(a, 0, numOfElements - 1, 33));
	EXPECT_EQ(6, BinarySearchRecursive2(a, 0, numOfElements - 1, 68));

	EXPECT_EQ(1, BinarySearchRecursive3(a, 0, numOfElements - 1, 2));
	EXPECT_EQ(0, BinarySearchRecursive3(a, 0, numOfElements - 1, 1));
	EXPECT_EQ(9, BinarySearchRecursive3(a, 0, numOfElements - 1, 12071));
	EXPECT_EQ(5, BinarySearchRecursive3(a, 0, numOfElements - 1, 47));
	EXPECT_EQ(-5, BinarySearchRecursive3(a, 0, numOfElements - 1, 33));
}

/*
* Unit test Algorithms::ArraySearchingAlgorithms::ArraySearchingAlgorithms a Algorithms::SortingAlgorithms::SortingAlgorithms.h
* Test algoritm� pro pole o lich�m po�tu prvk�.
* LinearSearch1, LinearSearch2, LinearSearchRecursive1, LinearSearchRecursive2, InsertSort, BinarySearch1, BinarySearch2, BinarySearch3
* BinarySearchRecursive1, BinarySearchRecursive2, BinarySearchRecursive3
* @param AlgStructTest n�zev struktury,
* @param SearchingAlgTest2 n�zev unit testu
*/
TEST_F(AlgStructTest, SearchingAlgTest2)
{
	const int numOfElements = 13;
	int b[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874, 4, 75, 49 };
	EXPECT_EQ(true, LinearSearch1(b, numOfElements, 2));
	EXPECT_EQ(true, LinearSearch1(b, numOfElements, 1));
	EXPECT_EQ(false, LinearSearch1(b, numOfElements, 33));
	EXPECT_EQ(true, LinearSearch1(b, numOfElements, 68));

	EXPECT_EQ(1, LinearSearch2(b, numOfElements, 2));
	EXPECT_EQ(8, LinearSearch2(b, numOfElements, 1));
	EXPECT_EQ(-1, LinearSearch2(b, numOfElements, 33)); // -1 prvek nen� v dan�m poli
	EXPECT_EQ(5, LinearSearch2(b, numOfElements, 68));

	EXPECT_EQ(true, LinearSearchRecursive1(b, numOfElements, 2, 0));
	EXPECT_EQ(true, LinearSearchRecursive1(b, numOfElements, 1, 0));
	EXPECT_EQ(false, LinearSearchRecursive1(b, numOfElements, 33, 0));
	EXPECT_EQ(true, LinearSearchRecursive1(b, numOfElements, 68, 0));

	EXPECT_EQ(1, LinearSearchRecursive2(b, numOfElements, 2, 0));
	EXPECT_EQ(8, LinearSearchRecursive2(b, numOfElements, 1, 0));
	EXPECT_EQ(-1, LinearSearchRecursive2(b, numOfElements, 33, 0));
	EXPECT_EQ(5, LinearSearchRecursive2(b, numOfElements, 68, 0));


	ADSLibrary::Algorithms::SortingAlgorithms::InsertSort(b, numOfElements); //sort pot�ebn� pro bin�rn� vyhled�v�n�

	EXPECT_EQ(true, BinarySearch1(b, numOfElements, 2));
	EXPECT_EQ(true, BinarySearch1(b, numOfElements, 1));
	EXPECT_EQ(false, BinarySearch1(b, numOfElements, 33));
	EXPECT_EQ(true, BinarySearch1(b, numOfElements, 68));

	EXPECT_EQ(1, BinarySearch2(b, numOfElements, 2));
	EXPECT_EQ(0, BinarySearch2(b, numOfElements, 1));
	EXPECT_EQ(12, BinarySearch2(b, numOfElements, 12071));
	EXPECT_EQ(6, BinarySearch2(b, numOfElements, 47));
	EXPECT_EQ(-1, BinarySearch2(b, numOfElements, 33));
	EXPECT_EQ(8, BinarySearch2(b, numOfElements, 68));

	EXPECT_EQ(1, BinarySearch3(b, numOfElements, 2));
	EXPECT_EQ(0, BinarySearch3(b, numOfElements, 1));
	EXPECT_EQ(12, BinarySearch3(b, numOfElements, 12071));
	EXPECT_EQ(6, BinarySearch3(b, numOfElements, 47));
	EXPECT_EQ(-6, BinarySearch3(b, numOfElements, 33)); //vrac� z�porn� ��slo, je� je bitov�m dopl�kem indexu v poli, kam m��e b�t prvek vlo�en bez naru�en� posloupnosti

	EXPECT_EQ(true, BinarySearchRecursive1(b, 0, numOfElements - 1, 2));
	EXPECT_EQ(true, BinarySearchRecursive1(b, 0, numOfElements - 1, 1));
	EXPECT_EQ(false, BinarySearchRecursive1(b, 0, numOfElements - 1, 33));
	EXPECT_EQ(true, BinarySearchRecursive1(b, 0, numOfElements - 1, 68));

	EXPECT_EQ(true, BinarySearchRecursive1a(b, 0, numOfElements - 1, 2));
	EXPECT_EQ(true, BinarySearchRecursive1a(b, 0, numOfElements - 1, 1));
	EXPECT_EQ(false, BinarySearchRecursive1a(b, 0, numOfElements - 1, 33));
	EXPECT_EQ(true, BinarySearchRecursive1(b, 0, numOfElements - 1, 68));

	EXPECT_EQ(1, BinarySearchRecursive2(b, 0, numOfElements - 1, 2));
	EXPECT_EQ(0, BinarySearchRecursive2(b, 0, numOfElements - 1, 1));
	EXPECT_EQ(12, BinarySearchRecursive2(b, 0, numOfElements - 1, 12071));
	EXPECT_EQ(6, BinarySearchRecursive2(b, 0, numOfElements - 1, 47));
	EXPECT_EQ(-1, BinarySearchRecursive2(b, 0, numOfElements - 1, 33));
	EXPECT_EQ(8, BinarySearchRecursive2(b, 0, numOfElements - 1, 68));

	EXPECT_EQ(1, BinarySearchRecursive3(b, 0, numOfElements - 1, 2));
	EXPECT_EQ(0, BinarySearchRecursive3(b, 0, numOfElements - 1, 1));
	EXPECT_EQ(12, BinarySearchRecursive3(b, 0, numOfElements - 1, 12071));
	EXPECT_EQ(6, BinarySearchRecursive3(b, 0, numOfElements - 1, 47));
	EXPECT_EQ(-6, BinarySearchRecursive3(b, 0, numOfElements - 1, 33));
}

using namespace ADSLibrary::Algorithms::SortingAlgorithms;
/*
* Unit test  Algorithms::SortingAlgorithms::SortingAlgorithms.h
* SelectSort
* Test algoritm� t��d�n� pole.
* @param AlgStructTest n�zev struktury,
* @param SelectionSortTest n�zev unit testu
*/
TEST_F(AlgStructTest, SelectionSortTest)
{	
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	SelectSort(a, numOfElements);
	ReportArray(a, numOfElements);
}

/*
* Unit test  Algorithms::SortingAlgorithms::SortingAlgorithms.h
* InsertSort
* Test algoritm� t��d�n� pole.
* @param AlgStructTest n�zev struktury,
* @param InsertionsSortTest n�zev unit testu
*/
TEST_F(AlgStructTest, InsertionsSortTest)
{	
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	InsertSort(a, numOfElements);
	ReportArray(a, numOfElements);
}

/*
* Unit test  Algorithms::SortingAlgorithms::SortingAlgorithms.h
* BubbleSort0, BubbleSort1, BubbleSort2, BubbleSort3, BubbleSort4
* Test algoritm� t��d�n� pole.
* @param AlgStructTest n�zev struktury,
* @param BubbleSortsTest n�zev unit testu
*/
TEST_F(AlgStructTest, BubbleSortsTest)
{	
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	int b[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	int c[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	int d[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	int e[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };

	ReportArray(a, numOfElements);
	BubbleSort0(a, numOfElements);
	ReportArray(a, numOfElements);

	ReportArray(b, numOfElements);
	BubbleSort1(b, numOfElements);
	ReportArray(b, numOfElements);

	ReportArray(c, numOfElements);
	BubbleSort2(c, numOfElements);
	ReportArray(c, numOfElements);

	ReportArray(d, numOfElements);
	BubbleSort3(d, numOfElements);
	ReportArray(d, numOfElements);

	ReportArray(e, numOfElements);
	BubbleSort4(e, numOfElements);
	ReportArray(e, numOfElements);
}

/*
* Unit test  Algorithms::SortingAlgorithms::SortingAlgorithms.h
* ShakerSort
* Test algoritm� t��d�n� pole.
* @param AlgStructTest n�zev struktury,
* @param InsertionsSortTest n�zev unit testu
*/
TEST_F(AlgStructTest, ShakerSortTest)
{
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	ShakerSort(a, numOfElements);
	ReportArray(a, numOfElements);
}

/*
* Unit test  Algorithms::SortingAlgorithms::SortingAlgorithms.h
* QuickSort
* Test algoritm� t��d�n� pole.
* @param AlgStructTest n�zev struktury,
* @param InsertionsSortTest n�zev unit testu
*/
TEST_F(AlgStructTest, QuickSortTest)
{
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	QuickSort(a, numOfElements);
	ReportArray(a, numOfElements);
}

/*
* Unit test  Algorithms::SortingAlgorithms::SortingAlgorithms.h
* HeapSort
* Test algoritm� t��d�n� pole.
* @param AlgStructTest n�zev struktury,
* @param InsertionsSortTest n�zev unit testu
*/
TEST_F(AlgStructTest, HeapSortTest)
{	
	const int numOfElements = 10;
	int a[numOfElements] = { 16, 2, 77, 40, 12071, 68, 32, 47, 1, 5874 };
	ReportArray(a, numOfElements);
	HeapSort(a, numOfElements);
	ReportArray(a, numOfElements);
}

AlgorithmsTest::AlgorithmsTest()
{
	
}

AlgorithmsTest::~AlgorithmsTest()
{
}