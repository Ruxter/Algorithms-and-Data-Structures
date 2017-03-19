#pragma once

namespace ADSLibrary
{
	namespace Algorithms
	{
		/**
		* Tøídící algoritmy v poli.
		*/
		namespace SortingAlgorithms
		{
			/**
			 * Selection sort
			 *
			 * @param a Prohledávané pole
			 * @param n Délka prohledávaného pole
			 * @param NumberOfComparisons Výstupní parametr - poèet porovnání
			 * @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			 */
			void SelectSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Insertion sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void InsertSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void BubbleSort0(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			* 
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void BubbleSort1(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void BubbleSort2(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void BubbleSort3(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void BubbleSort4(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Shaker Sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void ShakerSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Internal metoda pro Quick sort
			*
			* @param a Prohledávané pole
			* @param l Levá mez prohledávaného úseku pole.
			* @param r Pravá mez prohledávaného úseku pole.
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void QuickSortInternal(int a[], const int l, const int r, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Quick sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void QuickSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Pomocná metoda pro Heap sort
			*
			* @param a Prohledávané pole
			* @param l Levá mez prohledávaného úseku pole.
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void DownHeap(int a[], int k, int l, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Heap sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			* @param NumberOfComparisons Výstupní parametr - poèet porovnání
			* @param NumberOfExchanges Výstupní parametr - poèet prohození prvkù
			*/
			void HeapSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);
		}
	}
}