// wget www.inf.ufpr.br/bmuller/CI064/teste.c . 


#include <stdio.h>

main () {
	void *a,*b,*c,*d;

	a=( void * ) meuAlocaMem(100);
	 imprMapa();
	b=( void * ) meuAlocaMem(200);
	 imprMapa();
	c=( void * ) meuAlocaMem(300);
	 imprMapa();
	d=( void * ) meuAlocaMem(400);
	 imprMapa();
	meuLiberaMem(b);
	 imprMapa(); 
	
	b=( void * ) meuAlocaMem(50);
	 imprMapa();
	
	meuLiberaMem(c);
	 imprMapa(); 
	meuLiberaMem(a);
	 imprMapa();
	meuLiberaMem(b);
	 imprMapa();
	meuLiberaMem(d);
	 imprMapa();
}
