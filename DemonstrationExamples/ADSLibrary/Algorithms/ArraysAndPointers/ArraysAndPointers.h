#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

namespace ADSLibrary
{
	namespace Algorithms
	{
		namespace ArraysAndPointers
		{
			/**
			 * Inicializace hodnot v poli.
			 * Hodnoty v poli jsou pouze demonstra�n�, nemaj� ��dn� hlub�� v�znam.
			 *
			 * @param a Pole do kter�ho se budou ukl�dat hodnoty
			 * @param N Po�et prvk� v poli
			 */
			void InitArray(int* a, const int N);

			/**
			 * Zm�na hodnot prvk� pole.
			 * Zm�na hodnot v poli je pouze demonstra�n�.
			 * ��elem je zm�nit hodnoty v poli p�i demonstraci kop�rov�n� hodnot.
			 *
			 * @param a Pole, kde budeme m�nit hodnoty.
			 * @param N Po�et prvk� v poli
			 */
			void UpdateArray(int* a, const int N);

			/**
			 * Tisk pole na standardn� v�stup.
			 * Pole je p�ed�v�no jako ukazatel, p�esn�ji �e�eno jako ukazatel na prvn� prvek pole.
			 *
			 * @param a Tisknut� pole
			 * @param N Po�et prvk� v poli
			 */
			void PrintArray1(int* a, const int N);

			/**
			 * Tisk pole na standardn� v�stup.
			 * Pole je p�ed�v�no zp�sobem obvykl�m v C++.
			 *
			 * @param a Tisknut� pole
			 * @param N Po�et prvk� v poli
			 */
			void PrintArray2(int a[], const int N);

			/**
			 * Tisk pole na standardn� v�stup.
			 * Pole je p�ed�v�no jako ukazatel, p�esn�ji �e�eno jako ukazatel na prvn� prvek pole.
			 * Zpracov�n� pole prob�h� pomoc� pointerov� aritmetiky.
			 *
			 * @param a Tisknut� pole
			 * @param N Po�et prvk� v poli
			 */
			void PrintArray3(int* a, const int N);

			/**
			 * Kop�rov�n� hodnot z pole SourceArray do pole DestinationArray.
			 * Ob� pole jsou p�ed�v�na jako ukazatel�, p�esn�ji �e�eno jako ukazatel� na jejich prvn� prvky.
			 * Kop�rov�n� prob�h� pomoc� b�n�ho indexov�n� pole.
			 *
			 * @param SourceArray Zdrojov� pole, �ili "odkud"
			 * @param DestinationArray C�lov� pole, �ili "kam"
			 * @param N Po�et prvk� v poli SourceArray
			 */
			void CopyArray1(int* SourceArray, int* DestinationArray, const int N);

			/**
			 * Kop�rov�n� hodnot z pole SourceArray do pole DestinationArray.
			 * Ob� pole jsou p�ed�v�na jako ukazatel�, p�esn�ji �e�eno jako ukazatel� na jejich prvn� prvky.
			 * Kop�rov�n� prob�h� pomoc� pointerov� artimetiky.
			 *
			 * @param SourceArray Zdrojov� pole, �ili "odkud"
			 * @param DestinationArray C�lov� pole, �ili "kam"
			 * @param N Po�et prvk� v poli SourceArray
			 */
			void CopyArray2(int* SourceArray, int* DestinationArray, const int N);

			/**
			 * Kop�rov�n� hodnot z pole SourceArray do pole DestinationArray.
			 * Ob� pole jsou p�ed�v�na jako ukazatel�, p�esn�ji �e�eno jako ukazatel� na jejich prvn� prvky.
			 * Kop�rov�n� prob�h� pomoc� pointerov� aritmetiky.
			 *
			 * Z�pis pointerov� aritmetiky je v maxim�ln� m��e zhu�t�n,
			 * je vyu�ito v�ech dostupn�ch mo�nost� z�pisu k�du v C++.
			 * Tento zp�sob z�pisu algoritmu je zcela nevhodn� pro za��te�n�ky. Uv�d�m ho zde dvou d�vod� -
			 * jednak pro �plnost (�e je mo�n� i takov� z�pis algoritmu) a jednak jako hlavolam...
			 *
			 * @param SourceArray Zdrojov� pole, �ili "odkud"
			 * @param DestinationArray C�lov� pole, �ili "kam"
			 * @param N Po�et prvk� v poli SourceArray
			 */
			void CopyArray2a(int* SourceArray, int* DestinationArray, const int N);

			/**
			 * Funkce testuj�c� pr�ci s jednorozm�rn�m polem.
			 */
			void TestArray();

			/**
			 * Po�et ��dk� dvourozm�rn�ho pole.
			 */
			const int RowNumber = 4;

			/**
			 * Po�et sloupc� dvourozm�rn�ho pole.
			 */
			const int ColumnNumber = 5;

			/**
			 * Alokace dvourozm�rn�ho pole. C++ zn� jen jednorozm�rn� pole, dvou a v�cerozm�rn� pole je nutn� deklarovat jako pole pointer� na dal�� subpole.
			 * Tak�e dvourozm�rn� pole dynamicky alokovan� je pointer na pole jeho� prvky jsou pointery na po�adovan� datov� typ, �ili dvojn�sobn� pointer, **.
			 *
			 * @param R Po�et ��dk� alokovan�ho dvourozm�rn�ho pole
			 * @param C Po�et sloupc� alokovan�ho dvourozm�rn�ho pole
			 * @return Pointer na dvourozm�rn�ho pole
			 */
			double** AllocateMatrix(const int R, const int C);

			/**
			 * Dealokace dvourozm�rn�ho pole. Pole je postupn� dealokov�no po ��dc�ch. D�lku ��dk� tohoto pole, tj. po�et sloupc�, nen� nutn� uv�d�t,
			 * proto�e dealokace ��dk� matice je provedena pomoc� oper�toru delete[]. Spr�vce pam�ti v tomto p��pad� v�, kolik ka�d� ��dek zab�r� pam�ti.
			 *
			 * @param M Dynamicky alokovan� dvourozm�rn�ho pole
			 * @param R Po�et ��dk� dvourozm�rn�ho pole.
			 */
			void DeallocateMatrix(double** M, const int R);

			/**
			 * Napln�n� dvourozm�rn�ho pole testovac�mi daty.
			 *
			 * @param M Dynamicky alokovan� dvourozm�rn�ho pole
			 * @param R Po�et ��dk� dvourozm�rn�ho pole
			 * @param C Po�et sloupc� dvourozm�rn�ho pole
			 */
			void FillMatrix(double** M, const int R, const int C);

			/**
			 * Tisk dvourozm�rn�ho pole na standardn� v�stup.
			 *
			 * @param M Dynamicky alokovan� dvourozm�rn�ho pole
			 * @param R Po�et ��dk� dvourozm�rn�ho pole
			 * @param C Po�et sloupc� dvourozm�rn�ho pole
			 */
			void PrintMatrix(double** M, const int R, const int C);
		}
	}
}
