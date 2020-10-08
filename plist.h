// Progrma para consultar casos de COVID-19

#ifndef PLIST_H_
#define PLIST_H_

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;

template <class T> class List;
template <class T> class ListIterator;

//Creamos la clase Link
template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;
	int size;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

// Creamos la clase List
template <class T>
class List {
public:
	List();
	List(const List<T>&);
	~List();
	
	void printList(T val);
	void add(T);
	void search(int,int);
	int find(T val) const;
	void Sort(Link<T>**);
	void printLists(Link<T>*);
	void clear();
	string toString() const;
	void addHead(T val,int New);
	void pushdata(Link<T>**, int);
	void Split(Link<T>*, Link<T>**, Link<T>**);
	//Metodo para ordenamiento
	Link<T> *SortedMerge(Link<T> *a, Link<T> *b){ 
    Link<T> *result = NULL; 
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->size <= b->size) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
	}
	
private:
	Link<T> *head;
	int size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

//Destructor
template <class T>
List<T>::~List() {
	clear();
}

//Metodo simple para imprimir la lista ligada
template <class T>
void List<T>::printList(T val){
	Link<T> *p;
	p = head;

	while(p != 0){
		cout<< p->size << endl;
		p = p->next;
	}
}

//Metodo para agregar elementos a la lista
template <class T>
void List<T>::addHead(T val, int New){
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	newLink->size=New;
	newLink->next = 0;
	
	p=head;
	if(p == 0) head = newLink;
	else
	{
	while(p->next != 0) p = p->next;
	p->next = newLink;
	}
}


//Metodo para ordenar la lista   
template <class T>
void List<T>::Sort(Link<T> **headRef) 
{ 
    Link<T> *head = *headRef; 
    Link <T> *a; 
    Link<T> *b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    Split(head, &a, &b); 
  
    Sort(&a); 
    Sort(&b); 
    *headRef = SortedMerge(a, b); 
} 
  
//Metodo para seprar los elementos de la lista en mitades 
template <class T>
void List<T>::Split(Link<T> *sour, Link<T> **front, Link<T> **back) 
{ 
    Link<T> *f, *s; 
    s = sour; 
    f = sour->next; 
  
    while (f != NULL) { 
        f = f->next; 
        if (f != NULL) { 
            s = s->next; 
            f = f->next; 
        } 
    } 
 
    *front = sour; 
    *back = s->next; 
    s->next = NULL; 
} 

//Metodo para imprimir lista sin hacer uso del file
template <class T>
void List<T>::printLists(Link<T> *node) 
{ 
    while (node != NULL) { 
        cout << node->size << " "; 
        node = node->next; 
    } 
} 
 
//Funcion que agrega elementos al inicio de la lista
template <class T>
void List<T>::pushdata(Link<T> **head_ref, int newd) { 
    Link<T> *newnode = new Link<T>(newd); 
    newnode->size = newd; 
    newnode->next = (*head_ref); 
    (*head_ref) = newnode; 
}
  
//Metodo para encontrar la posicion del elemento buscado
template <class T>
int List<T>::find(T val) const {
	int index;
	Link<T> *p;
	
	index=0;
	p=head;
	
	while (p!=0){
		if (p->value==val){
			return index;
		}
		index ++;
		p=p->next;
	}
	return  -1;
}

//Funcion para buscar un elemento en una lista
template <class T>
void List<T>::search(int find, int size){
	Link<T> *temp,*stn;
	int i=0,flag;
	temp=stn;
	
	if(stn==0){
		cout<<"No hay lista"<<endl;
	}
	
	else{
		while (temp!=NULL){
			if(temp->size==find){
				cout<<"Casos localizados en la posicion: "<<(i+1);
			flag=0;}
		else{
		flag++;}
		i++;
		temp->next;
		}
		if(flag==size){
			cout<<"Numero de casos no disponible";
		}
	}
}

//MEtodo para agregar elementos a la lista
template <class T>
void List<T>::add(T val) {
	Link<T> *newLink, *p;

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

//Metodo para convertir la lista a string
template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}


#endif
