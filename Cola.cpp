#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *siguiente;
};
void insertarCola(Nodo *&frente, Nodo *&fin, int n);
bool cola_vacia(Nodo *frente);
void quitarCola(Nodo *&frente, Nodo *&fin, int &n);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int dato;
	char rep;
	do{
		cout<<"Digite un numero: ";
		cin>>dato;
		insertarCola(frente, fin, dato);
		
		cout<<"Deseas ingresar mas datos s/n ";
		cin>>rep;
	} while((rep=='S')||(rep=='s'));
	
	cout<<"Eliminando elementos de la cola ";
	while(frente != NULL){
		quitarCola(frente, fin, dato);
		
		if(frente != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<" . ";
		}
	}
	getch();
	return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato=n;
	nuevo_nodo -> siguiente =NULL;
	
	if(cola_vacia(frente)){
		frente=nuevo_nodo;
	}
	else{
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	if(frente==NULL){
		return true;
	}
	else{
		return false;
	}
//exactamente lo mismo
//return (frente == NULL)? true : false;
}

void quitarCola(Nodo *&frente, Nodo *&fin, int &n){
	n = frente -> dato;
	Nodo *aux = frente;
	
	if(frente==fin){
		frente= NULL;
		fin = NULL;
	}
	else{
		frente = frente-> siguiente;
	}
	delete aux;
}
