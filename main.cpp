#include <iostream>
#include <fstream>
#include <vector>
#include "plist.h"
#include<stdio.h> 
#include<stdlib.h> 

using namespace std;

int main(int argc, char* argv[]){
	List<int> l2;
	Link<int> *res=NULL;
	Link<int> *b=NULL;
	
	l2.pushdata(&b, 212710692);
	l2.pushdata(&b, 212710692);
	l2.pushdata(&b, 19132514);
	l2.pushdata(&b, 50936262);
	l2.pushdata(&b, 1381344997);
	l2.pushdata(&b, 84097623);
	l2.pushdata(&b, 129066160);
	l2.pushdata(&b, 221295851);
	l2.pushdata(&b, 33016319);
	l2.pushdata(&b, 145940924);
	l2.pushdata(&b, 34865919);
	l2.pushdata(&b, 59381566);
	l2.pushdata(&b, 46756648);
	l2.pushdata(&b, 67922029);
	l2.pushdata(&b, 331198130);
	
	int option;
	
	cout<<"----- MENU ------"<<endl;
	cout<<"1. Leer Archivo"<<endl;
	cout<<"2. Ordenar por numero de casos"<<endl;
	cout<< "Introduzca la opcion: "<<endl;; 
	cin >> option;
	switch(option){
		case 1:{
			List<int> li;
			int a;
			ifstream fin;
			ofstream fout;
			int head = 0;
			string country;
			country ="['Brazil','Chile','Colombia','India','Iran','Mexico','Pakistan','Peru','Rusia','Arabia Saudi','Sudafrica','Espana','UK','USA']";
			fin.open("Cov.txt");

			while(fin>>a) li.addHead(head,a);

			fin.close();

			cout<< "El archivo leido incluye la cantidad de casos de COVID-19  " << endl;
			cout<<"de los 15 paises con mayor cantidad de casos a nivel mundial siendo "<<endl;
			cout<<country<<" ordenados respectivamente en la lista de abajo: "<<endl;

			li.printList(head);
		}
		break;
		
		case 2:{	
			cout<<"Casos ordenados de Menor a Mayor"<<endl;
			l2.Sort(&b);
			l2.printLists(b);
		}
		break;

	}
}



