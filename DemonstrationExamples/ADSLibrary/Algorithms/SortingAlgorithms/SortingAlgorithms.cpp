#include "SortingAlgorithms.h"

namespace ADSLibrary
{
	namespace Algorithms
	{
		namespace SortingAlgorithms
		{
			inline void Exchange(int & x, int& y)
			{
				int aux = x;
				x = y;
				y = aux;
			}

			void SelectSort(int a[], const int n)
			{
				for (int i = 0; i < n; i++)
				{
					int min = i;
					for (int j = i + 1; j < n; j++)
					{
						if (a[j] < a[min])
						{
							min = j;
						}
					}
					Exchange(a[min], a[i]);
				}
			}

			void InsertSort(int a[], const int n)
			{
				for (int i = 1; i < n; i++)
				{
					int v = a[i];
					int j = i;
					while (j > 0)
					{
						if (a[j - 1] > v)
						{
							a[j] = a[j - 1];
							j -= 1;
						}
						else
						{
							break;
						}
					}
					a[j] = v;
				}
			}

			void BubbleSort0(int a[], const int n)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n - 1; j++)
					{
						if (a[j] > a[j + 1])
						{
							Exchange(a[j], a[j + 1]);
						}
					}
				}
			}

			void BubbleSort1(int a[], const int n)
			{
				for (int i = n - 1; i > 0; i--)
				{
					for (int j = 0; j < i; j++)
					{
						if (a[j] > a[j + 1])
						{
							Exchange(a[j], a[j + 1]);
						}
					}
				}
			}

			void BubbleSort2(int a[], const int n)
			{
				bool AnyExchange;
				do
				{
					AnyExchange = false;
					for (int i = 0; i < n - 1; i++)
					{
						if (a[i] > a[i + 1])
						{
							Exchange(a[i], a[i + 1]);
							AnyExchange = true;
						}
					}
				} while (AnyExchange);
			}
			
			void BubbleSort3(int a[], const int n)
			{
				bool AnyExchange;
				int Right = n - 1;
				do
				{
					AnyExchange = false;
					for (int i = 0; i < Right; i++)
					{
						if (a[i] > a[i + 1])
						{
							Exchange(a[i], a[i + 1]);
							AnyExchange = true;
						}
					}
					Right -= 1;
				} while (AnyExchange);
			}

			void BubbleSort4(int a[], const int n)
			{
				int Right = n - 1;
				int LastExchangeIndex;
				do
				{
					LastExchangeIndex = 0;
					for (int i = 0; i < Right; i++)
					{
						if (a[i] > a[i + 1])
						{
							Exchange(a[i], a[i + 1]);
							LastExchangeIndex = i + 1;
						}
					}
					Right = LastExchangeIndex;
				} while (LastExchangeIndex > 0);
			}

			void ShakerSort(int a[], const int n)
			{
				int ExchangeIndex = 0;
				int Left = 0;
				int Right = n - 1;
				do
				{
					for (int i = Left; i < Right; i++)
					{
						if (a[i] > a[i + 1])
						{
							Exchange(a[i], a[i + 1]);
							ExchangeIndex = i;
						}
					}
					Right = ExchangeIndex;
					for (int i = Right; i > Left; i--)
					{
						if (a[i - 1] > a[i])
						{
							Exchange(a[i - 1], a[i]);
							ExchangeIndex = i;
						}
					}
					Left = ExchangeIndex;
				} while (Left < Right);
			}

			void QuickSortInternal(int a[], const int l, const int r)
			{
				int i = l;
				int j = r;
				int pivot = a[(l + r) / 2];
				do
				{
					while (a[i] < pivot) i += 1;
					while (pivot < a[j]) j -= 1;
					if (i <= j)
					{
						Exchange(a[i], a[j]);
						i += 1;
						j -= 1;
					}
				} while (i <= j);
				if (l < j)
					QuickSortInternal(a, l, j);
				if (i < r)
					QuickSortInternal(a, i, r);
			}

			void QuickSort(int a[], const int n)
			{
				QuickSortInternal(a, 0, n - 1);
			}

			void DownHeap(int a[], int k, int l)
			{
				int v = a[k];
				while (k < l / 2)
				{
					int j = 2 * k;
					if (j < l - 1)
					{
						if (a[j] < a[j + 1])
							j += 1;
					}
					if (v >= a[j])
						break;
					a[k] = a[j];
					k = j;
				}
				a[k] = v;
			}

			void HeapSort(int a[], const int n)
			{
				int i;
				for (i = n / 2; i >= 0; i--)
				{
					DownHeap(a, i, n);
				}
				i = n - 1;
				do
				{
					Exchange(a[0], a[i]);
					i -= 1;
					DownHeap(a, 0, i + 1);
				} while (i > 0);
			}
		}
	}
}
