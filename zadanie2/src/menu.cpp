#include "menu.h"

#include "menu.h"
//#include<conio.h>
#include<string>
#include<iostream>
#include "UDirect_Graph_AList.h"
#include "UDirect_Graph_AMatrix.h"
#include "Direct_Graph_AList.h"
#include "Direct_Graph_AMatrix.h"

void menu_mst();
void menu_sp();
void show_path(int* prev, int source, int dest);
void show_all_paths(int* prev, int* dist, int source, int N);

using namespace std;

void menu()
{
	char option;
	do{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.MST" << endl;
		cout << "2.Najkrotsza sciezka" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		cin >> option ;
		cout << endl;

		switch (option){
		case '1':
			menu_mst();
			break;

		case '2':
			menu_sp();
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



void menu_mst()
{
	char opt;
	string fileName;
	int n, dens, a, b;
	UDirect_Graph_AList list_graf{0};
	UDirect_Graph_AMatrix matrix_graf{0};



	do{
		cout << endl;
		cout <<"\tProblem minimalnego drzewa rozpinajacego"<< endl;
		cout << "1.Wczytaj graf z pliku" << endl;
		cout << "2.Wygeneruj graf" << endl;
		cout << "3.Wyswietl" << endl;
		cout << "4.Prim" << endl;
		cout << "5.Kruskal" << endl;
		cout << "6.Wygeneruj i wybierz zakres generowanych wag" << endl;
		cout << "0.Powrot do menu" << endl;
		cout << "Podaj opcje:";

		cin >> opt;
		cout << endl;
		switch (opt){
		case '1':
			cout << " Podaj nazwe pliku:";
			cin >> fileName;
			list_graf.load_from_file(fileName);
			matrix_graf.load_from_file(fileName);

			list_graf.display();
			matrix_graf.display();
			break;

		case '2':
			cout << " podaj liczbe wierzcholkow:";
			cin >> n;
			cout << " podaj gestosc grafu w % :";
			cin >> dens;

			matrix_graf.gen(n, dens);
			list_graf.clone(matrix_graf);


			list_graf.display();
			matrix_graf.display();
			break;

		case '3': //wyswietlanie
			list_graf.display();
			matrix_graf.display();
			break;

		case '4': //prim

			list_graf.display();
			cout << "\nAlgorytm Prima na reprezentacji listowej" << endl;
			list_graf.Prim().display();

			matrix_graf.display();
			cout << "\nAlgorytm Prima na reprezentacji macierzowej" << endl;
			matrix_graf.Prim().display();
			break;

		case '5':  //Kruskal
			list_graf.display();
			cout << "\nAlgorytm Kruskala na reprezentacji listowej" << endl;
			list_graf.Kruskal().display();

			matrix_graf.display();
			cout << "\nAlgorytm Kruskala na reprezentacji macierzowej" << endl;
			matrix_graf.Kruskal().display();


			break;

		case '6':  //tutaj wyświetlanie tablicy

			cout << " podaj liczbe wierzcholkow:";
			cin >> n;
			cout << " podaj gestosc grafu w % :";
			cin >> dens;
			cout << " podaj minimalna wartosc wag:";
			cin >> a;
			cout << " podaj maksymalna wartosc wag:";
			cin >> b;
			matrix_graf.gen(n, dens, a, b);
			list_graf.clone(matrix_graf);

			list_graf.display();
			matrix_graf.display();

			break;

		}

	} while (opt != '0');
}

void menu_sp()
{
	char opt;
	string fileName;
	int n, dens, a, b, start, N;
	int* dist;
	int* prev;
	Direct_Graph_AList list_graf{0};
	Direct_Graph_AMatrix matrix_graf{0};



	do{
		cout << endl;
		cout <<"\tProblem minimalnego drzewa rozpinajacego"<< endl;
		cout << "1.Wczytaj graf z pliku" << endl;
		cout << "2.Wygeneruj graf skierowany" << endl;
		cout << "3.Wyswietl" << endl;
		cout << "4.Dijkstra" << endl;
		cout << "5.Bellamn-Ford" << endl;
		cout << "6.Wygeneruj i wybierz zakres generowanych wag" << endl;
		cout << "0.Powrot do menu" << endl;
		cout << "Podaj opcje:";

		cin >> opt;
		cout << endl;
		switch (opt){
		case '1':
			cout << " Podaj nazwe pliku:";
			cin >> fileName;
			start = list_graf.load_from_file(fileName);
			matrix_graf.load_from_file(fileName);

			list_graf.display();
			matrix_graf.display();
			break;

		case '2':
			cout << " podaj liczbe wierzcholkow:";
			cin >> n;
			cout << " podaj gestosc grafu w % :";
			cin >> dens;

			matrix_graf.gen(n, dens);
			list_graf.clone(matrix_graf);


			list_graf.display();
			matrix_graf.display();
			break;

		case '3': //wyswietlanie
			list_graf.display();
			matrix_graf.display();
			break;

		case '4': //Dijkstra
			N = list_graf.get_n();
			dist = new int[N];
			prev = new int[N];

			list_graf.display();
			cout << "\nAlgorytm Dijkstry na reprezentacji listowej" << endl;
			list_graf.Dijkstra(start, dist, prev);
			show_all_paths(prev, dist, start, N);

			matrix_graf.display();
			cout << "\nAlgorytm Dijkstry na reprezentacji macierzowej" << endl;
			matrix_graf.Dijkstra(start, dist, prev);
			show_all_paths(prev, dist, start, N);

			delete[] dist;
			delete[] prev;

			break;

		case '5':  //BF
			N = list_graf.get_n();
			dist = new int[N];
			prev = new int[N];

			list_graf.display();
			cout << "\nAlgorytm Bellmana-Forda na reprezentacji listowej" << endl;
			if(list_graf.BellmanFord(start, dist, prev))
				cout<< "wykryto ujemny cykl"<<endl;
			else
			{
			show_all_paths(prev, dist, start, N);
			}

			matrix_graf.display();
			cout << "\nAlgorytm Bellmana-Forda na reprezentacji macierzowej" << endl;
			if(matrix_graf.BellmanFord(start, dist, prev))
				cout<< "wykryto ujemny cykl"<<endl;
			else
			{
			show_all_paths(prev, dist, start, N);
			}
			delete[] dist;
			delete[] prev;

			break;

		case '6':  //tutaj wyświetlanie tablicy

			cout << " podaj liczbe wierzcholkow:";
			cin >> n;
			cout << " podaj gestosc grafu w % :";
			cin >> dens;
			cout << " podaj minimalna wartosc wag:";
			cin >> a;
			cout << " podaj maksymalna wartosc wag:";
			cin >> b;
			matrix_graf.gen(n, dens, a, b);
			list_graf.clone(matrix_graf);

			list_graf.display();
			matrix_graf.display();

			break;

		}

	} while (opt != '0');
}

void show_path(int* prev, int source, int dest)
{
	if(dest!=source)
		show_path( prev, source, prev[dest]);
	cout<<" > "<<dest;
}

void show_all_paths(int* prev, int* dist, int source, int N)
{
	cout<<"starting vert: "<<source<<endl;
	for(int i=0; i<N; i++)
	{
		cout<<"path to: " <<i<< " total weight: "<< dist[i]<<" path :";
		show_path(prev, source, i);
		cout<<endl;
	}
}
