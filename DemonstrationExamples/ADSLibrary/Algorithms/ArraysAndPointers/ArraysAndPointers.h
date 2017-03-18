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
			 * Hodnoty v poli jsou pouze demonstraèní, nemají žádný hlubší význam.
			 *
			 * @param a Pole do kterého se budou ukládat hodnoty
			 * @param N Poèet prvkù v poli
			 */
			void InitArray(int* a, const int N);

			/**
			 * Zmìna hodnot prvkù pole.
			 * Zmìna hodnot v poli je pouze demonstraèní.
			 * Úèelem je zmìnit hodnoty v poli pøi demonstraci kopírování hodnot.
			 *
			 * @param a Pole, kde budeme mìnit hodnoty.
			 * @param N Poèet prvkù v poli
			 */
			void UpdateArray(int* a, const int N);

			/**
			 * Tisk pole na standardní výstup.
			 * Pole je pøedáváno jako ukazatel, pøesnìji øeèeno jako ukazatel na první prvek pole.
			 *
			 * @param a Tisknuté pole
			 * @param N Poèet prvkù v poli
			 */
			void PrintArray1(int* a, const int N);

			/**
			 * Tisk pole na standardní výstup.
			 * Pole je pøedáváno zpùsobem obvyklým v C++.
			 *
			 * @param a Tisknuté pole
			 * @param N Poèet prvkù v poli
			 */
			void PrintArray2(int a[], const int N);

			/**
			 * Tisk pole na standardní výstup.
			 * Pole je pøedáváno jako ukazatel, pøesnìji øeèeno jako ukazatel na první prvek pole.
			 * Zpracování pole probíhá pomocí pointerové aritmetiky.
			 *
			 * @param a Tisknuté pole
			 * @param N Poèet prvkù v poli
			 */
			void PrintArray3(int* a, const int N);

			/**
			 * Kopírování hodnot z pole SourceArray do pole DestinationArray.
			 * Obì pole jsou pøedávána jako ukazatelé, pøesnìji øeèeno jako ukazatelé na jejich první prvky.
			 * Kopírování probíhá pomocí bìžného indexování pole.
			 *
			 * @param SourceArray Zdrojové pole, èili "odkud"
			 * @param DestinationArray Cílové pole, èili "kam"
			 * @param N Poèet prvkù v poli SourceArray
			 */
			void CopyArray1(int* SourceArray, int* DestinationArray, const int N);

			/**
			 * Kopírování hodnot z pole SourceArray do pole DestinationArray.
			 * Obì pole jsou pøedávána jako ukazatelé, pøesnìji øeèeno jako ukazatelé na jejich první prvky.
			 * Kopírování probíhá pomocí pointerové artimetiky.
			 *
			 * @param SourceArray Zdrojové pole, èili "odkud"
			 * @param DestinationArray Cílové pole, èili "kam"
			 * @param N Poèet prvkù v poli SourceArray
			 */
			void CopyArray2(int* SourceArray, int* DestinationArray, const int N);

			/**
			 * Kopírování hodnot z pole SourceArray do pole DestinationArray.
			 * Obì pole jsou pøedávána jako ukazatelé, pøesnìji øeèeno jako ukazatelé na jejich první prvky.
			 * Kopírování probíhá pomocí pointerové aritmetiky.
			 *
			 * Zápis pointerové aritmetiky je v maximální míøe zhuštìn,
			 * je využito všech dostupných možností zápisu kódu v C++.
			 * Tento zpùsob zápisu algoritmu je zcela nevhodný pro zaèáteèníky. Uvádím ho zde dvou dùvodù -
			 * jednak pro úplnost (že je možný i takový zápis algoritmu) a jednak jako hlavolam...
			 *
			 * @param SourceArray Zdrojové pole, èili "odkud"
			 * @param DestinationArray Cílové pole, èili "kam"
			 * @param N Poèet prvkù v poli SourceArray
			 */
			void CopyArray2a(int* SourceArray, int* DestinationArray, const int N);

			/**
			 * Funkce testující práci s jednorozmìrným polem.
			 */
			void TestArray();

			/**
			 * Poèet øádkù dvourozmìrného pole.
			 */
			const int RowNumber = 4;

			/**
			 * Poèet sloupcù dvourozmìrného pole.
			 */
			const int ColumnNumber = 5;

			/**
			 * Alokace dvourozmìrného pole. C++ zná jen jednorozmìrné pole, dvou a vícerozmìrné pole je nutné deklarovat jako pole pointerù na další subpole.
			 * Takže dvourozmìrné pole dynamicky alokované je pointer na pole jehož prvky jsou pointery na požadovaný datový typ, èili dvojnásobný pointer, **.
			 *
			 * @param R Poèet øádkù alokovaného dvourozmìrného pole
			 * @param C Poèet sloupcù alokovaného dvourozmìrného pole
			 * @return Pointer na dvourozmìrného pole
			 */
			double** AllocateMatrix(const int R, const int C);

			/**
			 * Dealokace dvourozmìrného pole. Pole je postupnì dealokováno po øádcích. Délku øádkù tohoto pole, tj. poèet sloupcù, není nutné uvádìt,
			 * protože dealokace øádkù matice je provedena pomocí operátoru delete[]. Správce pamìti v tomto pøípadì ví, kolik každý øádek zabírá pamìti.
			 *
			 * @param M Dynamicky alokované dvourozmìrného pole
			 * @param R Poèet øádkù dvourozmìrného pole.
			 */
			void DeallocateMatrix(double** M, const int R);

			/**
			 * Naplnìní dvourozmìrného pole testovacími daty.
			 *
			 * @param M Dynamicky alokované dvourozmìrného pole
			 * @param R Poèet øádkù dvourozmìrného pole
			 * @param C Poèet sloupcù dvourozmìrného pole
			 */
			void FillMatrix(double** M, const int R, const int C);

			/**
			 * Tisk dvourozmìrného pole na standardní výstup.
			 *
			 * @param M Dynamicky alokované dvourozmìrného pole
			 * @param R Poèet øádkù dvourozmìrného pole
			 * @param C Poèet sloupcù dvourozmìrného pole
			 */
			void PrintMatrix(double** M, const int R, const int C);
		}
	}
}
