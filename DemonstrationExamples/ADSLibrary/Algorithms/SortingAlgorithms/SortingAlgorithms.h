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
			 */
			void SelectSort(int a[], const int n);

			/**
			* Insertion sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void InsertSort(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void BubbleSort0(int a[], const int n);

			/**
			* Bubble sort
			* 
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void BubbleSort1(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void BubbleSort2(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void BubbleSort3(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void BubbleSort4(int a[], const int n);

			/**
			* Shaker Sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void ShakerSort(int a[], const int n);

			/**
			* Internal metoda pro Quick sort
			*
			* @param a Prohled�van� pole
			* @param l Lev� mez prohled�van�ho �seku pole.
			* @param r Prav� mez prohled�van�ho �seku pole.
			*/
			void QuickSortInternal(int a[], const int l, const int r);

			/**
			* Quick sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void QuickSort(int a[], const int n);

			/**
			* Pomocn� metoda pro Heap sort
			*
			* @param a Prohled�van� pole
			* @param l Lev� mez prohled�van�ho �seku pole.
			*/
			void DownHeap(int a[], int k, int l);

			/**
			* Heap sort
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			*/
			void HeapSort(int a[], const int n);
		}
	}
}