#include "ArraysAndPointers.h"

namespace ADSLibrary
{
	namespace Algorithms
	{
		namespace ArraysAndPointers
		{
			void InitArray(int* a, const int N)
			{
				for (int i = 0; i < N; i++)
				{
					a[i] = 2 * i + 3;
				}
			}

			void UpdateArray(int* a, const int N)
			{
				for (int i = 0; i < N; i++)
				{
					a[i] += 2;
				}
			}

			void PrintArray1(int* a, const int N)
			{
				for (int i = 0; i < N; i++)
				{
					cout << i << "\t" << a[i] << endl;
				}
			}

			void PrintArray2(int a[], const int N)
			{
				for (int i = 0; i < N; i++)
				{
					cout << i << "\t" << a[i] << endl;
				}
			}

			void PrintArray3(int* a, const int N)
			{
				for (int *p = a; p != a + N; p++)
				{
					cout << p - a << "\t" << *p << endl;
				}

			}

			void CopyArray1(int* SourceArray, int* DestinationArray, const int N)
			{
				for (int i = 0; i < N; i++)
				{
					DestinationArray[i] = SourceArray[i];
				}
			}

			void CopyArray2(int* SourceArray, int* DestinationArray, const int N)
			{
				int* SPtr = SourceArray;
				int* DPtr = DestinationArray;
				int* EndPtr = SourceArray + N;
				while (SPtr != EndPtr)
				{
					*DPtr = *SPtr;
					SPtr += 1;
					DPtr += 1;
				}
			}

			void CopyArray2a(int* SourceArray, int* DestinationArray, const int N)
			{
				for (int *SPtr = SourceArray, *DPtr = DestinationArray; SPtr != SourceArray + N; *DPtr++ = *SPtr++);
			}

			void TestArray()
			{
				const int Size = 5;
				int *A = new int[Size];
				int *B = new int[Size];

				InitArray(A, Size);
				cout << "Tisk pole" << endl;
				cout << "Pole predano jako pointer" << endl;
				PrintArray1(A, Size);
				cout << endl;

				cout << "Pole predano C++ zpusobem" << endl;
				PrintArray2(A, Size);
				cout << endl;

				cout << "Pole predano jako pointer, pointerova aritmetika" << endl;
				PrintArray3(A, Size);
				cout << endl;

				cout << "Kopirovani pole" << endl;
				cout << "Pole predana jako pointer" << endl;
				CopyArray1(A, B, Size);
				PrintArray1(B, Size);
				cout << endl;

				cout << "Pole predana jako pointer, pointerova aritmetika" << endl;
				UpdateArray(A, Size);
				CopyArray2(A, B, Size);
				PrintArray1(B, Size);
				cout << endl;

				cout << "Pole predana jako pointer, maximalne zhustena pointerova aritmetika" << endl;
				UpdateArray(A, Size);
				CopyArray2a(A, B, Size);
				PrintArray1(B, Size);
				cout << endl;

				delete[]A;
				delete[]B;
			}

			double** AllocateMatrix(const int R, const int C)
			{
				double **a = new double*[R];
				for (int i = 0; i < R; i++)
				{
					a[i] = new double[C];
				}
				return a;
			}

			void DeallocateMatrix(double** M, const int R)
			{
				for (int i = 0; i < R; i++)
				{
					delete[]M[i];
				}
				delete M;
			}

			void FillMatrix(double** M, const int R, const int C)
			{
				for (int i = 0; i < R; i++)
				{
					for (int j = 0; j < C; j++)
					{
						M[i][j] = (i + j) % R;
					}
				}
			}

			void PrintMatrix(double** M, const int R, const int C)
			{
				for (int i = 0; i < R; i++)
				{
					for (int j = 0; j < C; j++)
					{
						cout << M[i][j] << "  ";
					}
					cout << endl;
				}
			}
		}
	}
}
