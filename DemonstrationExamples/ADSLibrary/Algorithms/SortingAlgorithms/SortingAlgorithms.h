#pragma once

namespace ADSLibrary
{
	namespace Algorithms
	{
		/**
		* T��d�c� algoritmy v poli.
		*/
		namespace SortingAlgorithms
		{
			/**
			 * Selection sort
			 *
			 * @param a Prohled�van� pole
			 * @param n D�lka prohled�van�ho pole
			 * @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			 * @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			 */
			void SelectSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Insertion sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void InsertSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void BubbleSort0(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			* 
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void BubbleSort1(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void BubbleSort2(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void BubbleSort3(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void BubbleSort4(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Shaker Sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void ShakerSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Internal metoda pro Quick sort
			*
			* @param a Prohled�van� pole
			* @param l Lev� mez prohled�van�ho �seku pole.
			* @param r Prav� mez prohled�van�ho �seku pole.
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void QuickSortInternal(int a[], const int l, const int r, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Quick sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void QuickSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Pomocn� metoda pro Heap sort
			*
			* @param a Prohled�van� pole
			* @param l Lev� mez prohled�van�ho �seku pole.
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void DownHeap(int a[], int k, int l, int& NumberOfComparisons, int& NumberOfExchanges);

			/**
			* Heap sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param NumberOfComparisons V�stupn� parametr - po�et porovn�n�
			* @param NumberOfExchanges V�stupn� parametr - po�et prohozen� prvk�
			*/
			void HeapSort(int a[], const int n, int& NumberOfComparisons, int& NumberOfExchanges);
		}
	}
}