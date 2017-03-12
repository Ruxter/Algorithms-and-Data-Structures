#pragma once

namespace ADSLibrary
{
	namespace DataStructures
	{
		namespace ArrayBasedStructures
		{
			namespace Procedural
			{
				/**
				 * Maxim�ln� velikost seznamu.
				 */
				const int ListSize = 10;

				/**
				 * Ukazatel neukazuj�c� na ��dnou polo�ku.
				 */
				const int Nil = -1;

				/**
				 * \brief Struktura reprezentuj�c� polo�ku v seznamu {@link #ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::List\endlink}
				 */
				struct ListItem
				{
					/**
					 * Hodnota obsa�en� v polo�ce.
					 */
					int Value;
					/**
					 * Ukazatel na p�edchoz� polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu {@link #Nil\endlink}.
					 */
					int Prev;
					/**
					 * Ukazatel na n�sleduj�c�  polo�ku. Pokud takov� polo�ka neexistuje ukazatel m� hodnotu {@link #Nil\endlink}.
					 */
					int Next;
				};

				/**
				 * \brief Obousm�rn� seznam implementovan� v poli procedur�ln�m zp�sobem.
				 *
				 * Implementace obousm�rn�ho seznamu v poli. V seznamu je implementov�n garbage collector a jednoduch� iter�tor.
				 * Implementace v poli znamen�, �e ukazatel je v tomto p��pad� realizov�n jako ��slo typu int a ukazatel je de-facto index v poli.
				 */
				struct List
				{
					/**
					 * Pole obsahuj�c� data ulo�en� do seznamu.
					 */
					ListItem Data[ListSize];
					/**
					 * Hlava seznamu tj. ukazatel na prvn� polo�ku seznamu v poli {@link #Data\endlink}.
					 */
					int Head;
					/**
					 * Ukazatel na prvn� volnou polo�ku v poli {@link #Data\endlink}. Pokud takov� polo�ka neexistuje, m� ukazatel hodnotu Nil.
					 * Tento ukazatel je vyu��v�n garbage collectorem.
					 */
					int Free;
					/**
					 * Ukazatel na aktu�ln� polo�ku p�i iteraci seznamem.
					 */
					int Current;
				};

				/**
				 * Inicializace seznamu.
				 * Proto�e je seznam implementovan� v poli, nemus�me prov�d�t ��dnou alokaci pam�ti a tud� m��eme
				 * inicializaci seznamu pova�ovat za vpodstat� smaz�n� p�vodn�ho obsahu.
				 * Pokud bychom pou��vali dynamicky alokovan� pam�ov� struktury, museli bychom nejprve prov�st p��padnou
				 * alokaci pot�ebn� pam�ti.
				 *
				 * @param L Inicializovan� seznam
				 */
				void Init(List& L);

				/**
				 * Smaz�n� cel�ho obsahu seznamu. Smaz�n� spo��v� v "zapomenut�" struktury vz�jemn�ch odkaz� prvk� seznamu mezi sebou.
				 *
				 * @param L Seznam
				 */
				void Clear(List& L);

				/**
				 * Vlo�en� prvku do seznamu. Prvek je vlo�en p�ed sou�asnou hlavu seznamu tj. stane se novou hlavou seznamu.
				 *
				 * @param L Seznam
				 * @param X Vkl�dan� prvek
				 */
				void Insert(List& L, const int X);

				/**
				 * Odebr�n� prvku ze seznamu. Prvek X je nejprve v seznamu nalezen a pot� je odpov�daj�c� polo�ka ze seznamu vymaz�na.
				 *
				 * @param L Seznam
				 * @param X Odeb�ran� prvek
				 */
				void Delete(List& L, const int X);

				/**
				 * Hled�n� prvku v seznamu.
				 *
				 * @param L Seznam
				 * @param X Hledan� prvek
				 * @return Funkce vrac� true v p��pad�, �e je prvek X nalezen, jinak vrac� false.
				 */
				bool Search(const List& L, const int X);

				/**
				 * Test je-li seznam pr�zdn�.
				 *
				 * @param L Seznam
				 * @return Funkce vrac� true pokud je seznam pr�zdn�, jinak false.
				 */
				bool IsEmpty(const List& L);

				/**
				 * Funkce vrac� po�et prvk� v seznamu.
				 *
				 * @param L Seznam
				 * @return Po�et prvk� v seznamu.
				 */
				int Count(const List& L);

				/**
				 * Reset iter�toru. Ukazatel na aktu�ln� polo�ku seznamu bude ukazovat na hlavu seznamu.
				 *
				 * @param L Seznam
				 */
				void Reset(List& L);

				/**
				 * Test ukon�en� �innosti iter�toru.
				 *
				 * @param L Seznam
				 * @return Funkce vrac� true pokud je iterace seznamem ukon�ena, jinak false.
				 */
				bool IsEnd(const List& L);

				/**
				 * Posun ukazatele aktu�ln� polo�ky na dal�� polo�ku v seznamu.
				 *
				 * @param L Seznam
				 */
				void MoveNext(List& L);

				/**
				 * Vr�cen� prvku z aktu�ln� polo�ky seznamu p�i iteraci.
				 *
				 * @param L Seznam
				 * @return Funkce vrac� prvek z aktu�ln� polo�ky seznamu p�i iteraci.
				 */
				int Current(const List& L);

				/**
				 * Alokace voln� polo�ky v seznamu. Alokovan� polo�ka se odebr�na z prvn� pozice v garbage collectoru.
				 *
				 * @param L Seznam
				 * @return Funkce vrac� ukazatel na alokovanou polo�ku v seznamu. V p��pad�, �e ji� nejsou ��dn� voln� polo�ky k dispozici, funkce vrac� Nil.
				 */
				int AllocateItem(List& L);

				/**
				 * Dealokace, uvoln�n�, polo�ky v seznamu.
				 *
				 * @param L Seznam
				 * @param Index Ukazatel na uvol�ovanou polo�ku v seznamu. Uvoln�n� polo�ka je vr�cena na prvn� m�sto v garbage collecotoru.
				 */
				void FreeItem(List& L, int Index);

				/**
				 * Pomocn� funkce, kter� zobrazuje vnit�n� strukturu seznamu.
				 *
				 * @param L Seznam
				 */
				void Report(const List& L);
			}
		}
	}
}
