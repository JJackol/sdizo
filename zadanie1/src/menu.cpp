#include "menu.h"
//#include<conio.h>
#include<string>
#include<iostream>
#include "SL_List.h"
#include "DL_List.h"
#include "DArray.h"
#include "Max_Heap.h"

using namespace std;

void menu()
{
	char option;
	do{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		cin >> option ;
		cout << endl;

		switch (option){
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
		}

	} while (option != '0');

	return;
}

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}



void menu_table()
{
	char opt;
	string fileName;
	int index, value;

	DArray myTab;

	do{
		displayMenu("--- TABLICA ---");
		cin >> opt;
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytywanie  tablicy z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			myTab.load_from_file(fileName);
			myTab.print();
			break;

		case '2': //tutaj usuwanie elementu z tablicy
			cout << " podaj index:";
			cin >> index;
			myTab.remove_at(index);
			myTab.print();
			break;

		case '3': //tutaj dodawanie elementu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj waertosc:";
			cin >> value;

			myTab.insert(index,value);
			myTab.print();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj waertosc:";
			cin >> value;
			if (myTab.find(value) >= 0 )
				cout << "poadana wartosc jest w tablicy";
			else
				cout << "poadanej wartosci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow tablicy:";
			cin >> value;

			myTab.clear();
			myTab.generate_arr(value);

			myTab.print();
			break;

		case '6':  //tutaj wyświetlanie tablicy
			myTab.print();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
			      // można sobie tu dodać własne case'y
			break;
		}

	} while (opt != '0');
}

void menu_list()
{
    char opt;
	string fileName;
	int index, value;

	DL_List lista;

	do{
		displayMenu("--- LISTA ---");
		cin >> opt;
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytywanie  tablicy z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			lista.load_from_file(fileName);
			lista.print();
			lista.print_rev();
			break;

		case '2': //tutaj usuwanie elementu z tablicy
			cout << " podaj wartosc:";
			cin >> value;
			lista.remove_val(value);
			lista.print();
			lista.print_rev();
			break;

		case '3': //tutaj dodawanie elementu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj waertosc:";
			cin >> value;

			lista.insert(index,value);
			lista.print();
			lista.print_rev();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj waertosc:";
			cin >> value;
			if (lista.find(value) >= 0 )
				cout << "poadana wartosc jest na liscie";
			else
				cout << "poadanej wartosci NIE ma na liscie";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow listy:";
			cin >> value;

			lista.clear();
			lista.generate_list(value);

			lista.print();
			lista.print_rev();
			break;

		case '6':  //tutaj wyświetlanie tablicy
			lista.print();
			lista.print_rev();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
			      // można sobie tu dodać własne case'y
			break;
		}

	} while (opt != '0');
}

void menu_heap()
{
	//analogicznie jak menu_table()
    char opt;
	string fileName;
	int index, value;

	Max_Heap kopiec;

	do{
		displayMenu("--- KOPIEC ---");
		cin >> opt;
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytywanie  kopca z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			kopiec.load_from_file(fileName);
			kopiec.print();
			break;

		case '2': //tutaj usuwanie elementu z kopca
			cout << " podaj klucz:";
			cin >> value;
			kopiec.remove_key(value);
			kopiec.print();
			break;

		case '3': //tutaj dodawanie elementu do kopca
			cout << " podaj wartosc:";
			cin >> value;

			kopiec.push(value);
			kopiec.print();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (kopiec.search_for(value))
				cout << "podana wartosc jest w kopcu";
			else
				cout << "podanej wartosci NIE ma w kopcu";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow kopca:";
			cin >> value;

			kopiec.clear();
			kopiec.generate_heap(value);

			kopiec.print();
			break;

		case '6':  //tutaj wyświetlanie tablicy
			kopiec.print();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
			      // można sobie tu dodać własne case'y
			break;
		case '8': //pop_root
			kopiec.pop_root();
			kopiec.print();
			break;
		}

    } while (opt != '0');
}


