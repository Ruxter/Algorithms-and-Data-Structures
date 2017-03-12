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
				 * Maximální velikost seznamu.
				 */
				const int ListSize = 10;

				/**
				 * Ukazatel neukazující na ádnou poloku.
				 */
				const int Nil = -1;

				/**
				 * \brief Struktura reprezentující poloku v seznamu {@link #ADSLibrary::DataStructures::ArrayBasedStructures::Procedural::List\endlink}
				 */
				struct ListItem
				{
					/**
					 * Hodnota obsaená v poloce.
					 */
					int Value;
					/**
					 * Ukazatel na pøedchozí poloku. Pokud taková poloka neexistuje ukazatel má hodnotu {@link #Nil\endlink}.
					 */
					int Prev;
					/**
					 * Ukazatel na následující  poloku. Pokud taková poloka neexistuje ukazatel má hodnotu {@link #Nil\endlink}.
					 */
					int Next;
				};

				/**
				 * \brief Obousmìrnı seznam implementovanı v poli procedurálním zpùsobem.
				 *
				 * Implementace obousmìrného seznamu v poli. V seznamu je implementován garbage collector a jednoduchı iterátor.
				 * Implementace v poli znamená, e ukazatel je v tomto pøípadì realizován jako èíslo typu int a ukazatel je de-facto index v poli.
				 */
				struct List
				{
					/**
					 * Pole obsahující data uloená do seznamu.
					 */
					ListItem Data[ListSize];
					/**
					 * Hlava seznamu tj. ukazatel na první poloku seznamu v poli {@link #Data\endlink}.
					 */
					int Head;
					/**
					 * Ukazatel na první volnou poloku v poli {@link #Data\endlink}. Pokud taková poloka neexistuje, má ukazatel hodnotu Nil.
					 * Tento ukazatel je vyuíván garbage collectorem.
					 */
					int Free;
					/**
					 * Ukazatel na aktuální poloku pøi iteraci seznamem.
					 */
					int Current;
				};

				/**
				 * Inicializace seznamu.
				 * Protoe je seznam implementovanı v poli, nemusíme provádìt ádnou alokaci pamìti a tudí mùeme
				 * inicializaci seznamu povaovat za vpodstatì smazání pùvodního obsahu.
				 * Pokud bychom pouívali dynamicky alokované pamìové struktury, museli bychom nejprve provést pøípadnou
				 * alokaci potøebné pamìti.
				 *
				 * @param L Inicializovanı seznam
				 */
				void Init(List& L);

				/**
				 * Smazání celého obsahu seznamu. Smazání spoèívá v "zapomenutí" struktury vzájemnıch odkazù prvkù seznamu mezi sebou.
				 *
				 * @param L Seznam
				 */
				void Clear(List& L);

				/**
				 * Vloení prvku do seznamu. Prvek je vloen pøed souèasnou hlavu seznamu tj. stane se novou hlavou seznamu.
				 *
				 * @param L Seznam
				 * @param X Vkládanı prvek
				 */
				void Insert(List& L, const int X);

				/**
				 * Odebrání prvku ze seznamu. Prvek X je nejprve v seznamu nalezen a poté je odpovídající poloka ze seznamu vymazána.
				 *
				 * @param L Seznam
				 * @param X Odebíranı prvek
				 */
				void Delete(List& L, const int X);

				/**
				 * Hledání prvku v seznamu.
				 *
				 * @param L Seznam
				 * @param X Hledanı prvek
				 * @return Funkce vrací true v pøípadì, e je prvek X nalezen, jinak vrací false.
				 */
				bool Search(const List& L, const int X);

				/**
				 * Test je-li seznam prázdnı.
				 *
				 * @param L Seznam
				 * @return Funkce vrací true pokud je seznam prázdnı, jinak false.
				 */
				bool IsEmpty(const List& L);

				/**
				 * Funkce vrací poèet prvkù v seznamu.
				 *
				 * @param L Seznam
				 * @return Poèet prvkù v seznamu.
				 */
				int Count(const List& L);

				/**
				 * Reset iterátoru. Ukazatel na aktuální poloku seznamu bude ukazovat na hlavu seznamu.
				 *
				 * @param L Seznam
				 */
				void Reset(List& L);

				/**
				 * Test ukonèení èinnosti iterátoru.
				 *
				 * @param L Seznam
				 * @return Funkce vrací true pokud je iterace seznamem ukonèena, jinak false.
				 */
				bool IsEnd(const List& L);

				/**
				 * Posun ukazatele aktuální poloky na další poloku v seznamu.
				 *
				 * @param L Seznam
				 */
				void MoveNext(List& L);

				/**
				 * Vrácení prvku z aktuální poloky seznamu pøi iteraci.
				 *
				 * @param L Seznam
				 * @return Funkce vrací prvek z aktuální poloky seznamu pøi iteraci.
				 */
				int Current(const List& L);

				/**
				 * Alokace volné poloky v seznamu. Alokovaná poloka se odebrána z první pozice v garbage collectoru.
				 *
				 * @param L Seznam
				 * @return Funkce vrací ukazatel na alokovanou poloku v seznamu. V pøípadì, e ji nejsou ádné volné poloky k dispozici, funkce vrací Nil.
				 */
				int AllocateItem(List& L);

				/**
				 * Dealokace, uvolnìní, poloky v seznamu.
				 *
				 * @param L Seznam
				 * @param Index Ukazatel na uvolòovanou poloku v seznamu. Uvolnìná poloka je vrácena na první místo v garbage collecotoru.
				 */
				void FreeItem(List& L, int Index);

				/**
				 * Pomocná funkce, která zobrazuje vnitøní strukturu seznamu.
				 *
				 * @param L Seznam
				 */
				void Report(const List& L);
			}
		}
	}
}
