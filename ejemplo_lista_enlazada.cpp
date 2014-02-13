/*
 *  SLL.h
 *  Práctica V
 *
 *  Created by Jonás López Mesa on 04/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
using namespace std;
#include <iostream>
#include <string>



class sll_item {
private:
	int key_;
	sll_item* next_;
	
public:
	sll_item();
	sll_item(int k);
	~sll_item();
	void setnext(sll_item* n);
	sll_item* getnext();
	void setkey(int x);
	int getkey();
	void write();
};

sll_item::sll_item() : next_ (NULL), key_ (0) {}
sll_item::sll_item (int k) : next_ (NULL), key_ (k) {}
sll_item::~sll_item()
{
	next_ = NULL;
}

void sll_item::setnext(sll_item* n)
{
	next_ = n;	
	
}

sll_item* sll_item::getnext()
{
	return next_;
}

void sll_item::setkey(int x)
{
	key_ = x;
}

int sll_item::getkey()
{
	return key_;
}

void sll_item::write()
{
	cout << "el código es:" << key_ << endl;
}


class sll {
private:
	sll_item* inicio_;
	//puntero ultimo
public:
	sll();
	~sll();
	bool empty(); //si esta vacio o no
	void insert_b(sll_item* i); //insertar por el principio
	void insert_e(sll_item* i); //insertar por el final
	void insert(sll_item* P, sll_item* i); //insertar por un lugar específico
	sll_item* remove(sll_item* p);
	sll_item* remove_b();
	sll_item* remove_e();
	void insert_o(sll_item* i); //insertar de forma ordenada
	void imprimir();
};


sll::sll(void) : inicio_(NULL) {} //inicializar la lista
sll::~sll()
{
	sll_item* aux = NULL;
	while (inicio_ != NULL) {
		aux = inicio_;
		inicio_ = inicio_->getnext();
		delete aux;
	}
}

bool sll::empty()
{
	if (inicio_ == NULL) {
		return 1;
	}
	else {
		return 0;
	}
	
}

void sll::insert_b(sll_item* i)
{
	i->setnext(inicio_);
	inicio_ = i;
}

void sll::insert_e(sll_item* i)
{
	i->setnext(NULL);
	if (inicio_ == NULL) {
		inicio_ = i;
	}
	else {
		sll_item* aux = inicio_;
		while (aux->getnext() != NULL) {
			aux = aux->getnext();
		}
		aux->setnext(i);
	}
}

void sll::insert(sll_item* P, sll_item* i)
{
	i->setnext(P->getnext());
	P->setnext(i);
}

sll_item* sll::remove_b()
{
	//si la lista está vacía no extraemos nada
	sll_item* aux = inicio_;
	inicio_ = inicio_->getnext();
	return aux;
}

sll_item* sll::remove(sll_item* prev)
{
	sll_item* aux = prev->getnext();
	prev->setnext(aux->getnext());
	return aux;
}

sll_item* sll::remove_e()
{
	if (inicio_->getnext() == NULL) {
		sll_item* aux = inicio_;
		inicio_ = NULL;
		return aux;
	}
	else {
		sll_item* prev = inicio_;
		while (prev->getnext()->getnext() != NULL) {
			prev = prev->getnext();
		}
		return remove(prev);
	}
}

void sll::insert_o(sll_item* e)
{
	sll_item* aux = inicio_;
	sll_item* aux2 = inicio_;
	unsigned r = 0;
	if (inicio_ == NULL) {
		insert_b(e);
	}
	else if (e->getkey() < inicio_->getkey())
		insert_b(e);
	else {
		while ((aux != NULL) && (r == 0)) {
			aux = aux->getnext();
			if (e->getkey() <= aux->getkey()) {
				e->setnext(aux->getnext());
				aux2->setnext(e);
				r = 1;
			}
			aux2 = aux;
		}
	}
	
}