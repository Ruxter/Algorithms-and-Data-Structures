#pragma once

namespace ADSLibrary
{
	namespace Algorithms
	{
		namespace ArraySearchingAlgorithms
		{		
			/**
			* Hled�n� prvku v poli.
			*
			* Funkce testuje prostou p��tomnost �i nep��tomnost hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus line�rn�ho vyhled�v�n�. Slo�itost tohoto algoritmu je O(N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param x Hledan� prvek
			* @return Funkce vrac� true pokud se prvek hledan� prvek nach�z� v dan�m poli, jinak false.
			*/
			bool LinearSearch1(const int a[], const int n, const int x);
			
			/**
			* Hled�n� prvku v poli.
			*
			* Funkce hled� prvn� v�skyt hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus line�rn�ho vyhled�v�n�. Slo�itost tohoto algoritmu je O(N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param x Hledan� prvek
			* @return Funkce vrac� index prvn�ho v�skytu hledan�ho prvku v dan�m poli, jinak vrac� -1.
			*/
			int LinearSearch2(const int a[], const int n, const int x);
			
			/**
			* Hled�n� prvku v poli.
			*
			* Funkce testuje prostou p��tomnost �i nep��tomnost hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus line�rn�ho vyhled�v�n� pomoc� rekurze. Slo�itost tohoto algoritmu je O(N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param x Hledan� prvek
			* @param i Aktu�ln� zkouman� index v poli. P�i vol�n� funkce je nutno tento parametr nastavit na 0.
			* @return Funkce vrac� true pokud se hledan� prvek nach�z� v dan�m poli, jinak false.
			*/
			bool LinearSearchRecursive1(const int a[], const int n, const int x, const int i);
			
			/**
			* Hled�n� prvku v poli.
			*
			* Funkce hled� prvn� v�skyt hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus line�rn�ho vyhled�v�n�. Slo�itost tohoto algoritmu je O(N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param x Hledan� prvek
			* @param i Aktu�ln� zkouman� index v poli. P�i vol�n� funkce je nutno tento parametr nastavit na 0.
			* @return Funkce vrac� index prvn�ho v�skytu hledan�ho prvku v dan�m poli, jinak vrac� -1.
			*/
			int LinearSearchRecursive2(const int a[], const int n, const int x, const int i);
			
			/**
			* Hled�n� prvku ve vzestupn� set��d�n�m poli.
			*
			* Funkce testuje prostou p��tomnost �i nep��tomnost hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus vyhled�v�n� p�len�m intervalu. Slo�itost tohoto algoritmu je O(log_{2}N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param x Hledan� prvek
			* @return Funkce vrac� true pokud se hledan� prvek nach�z� v dan�m poli, jinak false.
			*/
			bool BinarySearch1(const int a[], const int n, const int x);
			
			/**
			* Hled�n� prvku ve vzestupn� set��d�n�m poli.
			*
			* Funkce testuje prostou p��tomnost �i nep��tomnost hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus vyhled�v�n� p�len�m intervalu. Slo�itost tohoto algoritmu je O(log_{2}N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param n D�lka prohled�van�ho pole
			* @param x Hledan� prvek
			* @return Funkce vrac� index v�skytu hledan�ho prvku v dan�m poli, jinak vrac� -1.
			*/
			int BinarySearch2(const int a[], const int n, const int x);
						
			/**
			* Hled�n� prvku ve vzestupn� set��d�n�m poli.
			*
			* Funkce testuje prostou p��tomnost �i nep��tomnost hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus vyhled�v�n� p�len�m intervalu pomoc� rekurze. Slo�itost tohoto algoritmu je O(log_{2}N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param l Lev� mez prohled�van�ho �seku pole, inkluzivn�. P�i po��te�n�m vol�n� funkce nastavit tento parametr na 0.
			* @param r Prav� mez prohled�van�ho �seku pole, inkluzivn�. P�i po��te�n�m vol�n� funkce nastavit tento parametr na N-1, kde N je po�et prvk� v poli.
			* @param x Hledan� prvek
			* @return Funkce vrac� true pokud se hledan� prvek nach�z� v dan�m poli, jinak false.
			*/
			bool BinarySearchRecursive1(const int a[], const int l, const int r, const int x);
			
			/**
			* Hled�n� prvku ve vzestupn� set��d�n�m poli.
			*
			* Funkce testuje prostou p��tomnost �i nep��tomnost hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus vyhled�v�n� p�len�m intervalu pomoc� rekurze. Slo�itost tohoto algoritmu je O(log_{2}N), kde N je po�et prvk� v poli.
			* Funkce demonstruje implementaci rekurz�vn�ho vol�n� pomoc� tern�rn�ho oper�toru.
			*
			* @param a Prohled�van� pole
			* @param l Lev� mez prohled�van�ho �seku pole, inkluzivn�. P�i po��te�n�m vol�n� funkce nastavit tento parametr na 0.
			* @param r Prav� mez prohled�van�ho �seku pole, inkluzivn�. P�i po��te�n�m vol�n� funkce nastavit tento parametr na N-1, kde N je po�et prvk� v poli.
			* @param x Hledan� prvek
			* @return Funkce vrac� true pokud se hledan� prvek nach�z� v dan�m poli, jinak false.
			*/
			bool BinarySearchRecursive1a(const int a[], const int l, const int r, const int x);
			
			/**
			* Hled�n� prvku ve vzestupn� set��d�n�m poli.
			*
			* Funkce testuje prostou p��tomnost �i nep��tomnost hledan�ho prvku v dan�m poli.
			* Funkce nezkoum� po�et v�ech v�skyt� hledan�ho prvku v poli ani p��padn� indexy v�ech jeho v�skyt�.
			* Funkce implementuje algoritmus vyhled�v�n� p�len�m intervalu pomoc� rekurze. Slo�itost tohoto algoritmu je O(log_{2}N), kde N je po�et prvk� v poli.
			*
			* @param a Prohled�van� pole
			* @param l Lev� mez prohled�van�ho �seku pole, inkluzivn�. P�i po��te�n�m vol�n� funkce nastavit tento parametr na 0.
			* @param r Prav� mez prohled�van�ho �seku pole, inkluzivn�. P�i po��te�n�m vol�n� funkce nastavit tento parametr na N-1, kde N je po�et prvk� v poli.
			* @param x Hledan� prvek
			* @return Funkce vrac� index v�skytu hledan�ho prvku v dan�m poli, jinak vrac� -1.
			*/
			int BinarySearchRecursive2(const int a[], const int l, const int r, const int x);			
		}
	}
}