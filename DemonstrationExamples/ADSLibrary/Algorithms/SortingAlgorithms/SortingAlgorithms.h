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
			 */
			void SelectSort(int a[], const int n);

			/**
			* Insertion sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void InsertSort(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void BubbleSort0(int a[], const int n);

			/**
			* Bubble sort
			* 
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void BubbleSort1(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void BubbleSort2(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void BubbleSort3(int a[], const int n);

			/**
			* Bubble sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void BubbleSort4(int a[], const int n);

			/**
			* Shaker Sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void ShakerSort(int a[], const int n);

			/**
			* Internal metoda pro Quick sort
			*
			* @param a Prohledávané pole
			* @param l Levá mez prohledávaného úseku pole.
			* @param r Pravá mez prohledávaného úseku pole.
			*/
			void QuickSortInternal(int a[], const int l, const int r);

			/**
			* Quick sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void QuickSort(int a[], const int n);

			/**
			* Pomocná metoda pro Heap sort
			*
			* @param a Prohledávané pole
			* @param l Levá mez prohledávaného úseku pole.
			*/
			void DownHeap(int a[], int k, int l);

			/**
			* Heap sort
			*
			* @param a Prohledávané pole
			* @param n Délka prohledávaného pole
			*/
			void HeapSort(int a[], const int n);
		}
	}
}