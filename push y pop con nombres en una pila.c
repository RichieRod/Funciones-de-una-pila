#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

char nombre[100]; //Variable global

//Crear una pila
typedef char Item;

typedef struct nodo{
	Item elemento;
	struct nodo *siguiente;
}Nodo;

typedef struct{
	struct nodo *cima;
}Pila;

void crearPila(Pila *pila){
	pila->cima = NULL;
}

//verificar si la pila esta vacia o no.1- vacia, 0-con elementos
int isEmpty(Pila pila){
	return (pila.cima==NULL);
}


//Retornar el elemento de la cima de la pila
Item cima(Pila *pila){
	if(isEmpty(*pila)){
		puts("Underflow");
		exit(1);
	}
	else{
		return pila->cima->elemento;
	}
}
//Ingresar un elemento a la pila
void insertar(Pila *pila, Item elemento){
    Nodo *nuevo;
    nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->elemento=elemento;
    nuevo->siguiente=pila->cima;
    pila->cima=nuevo;
}
void push(Pila *pila){
    printf("\nIngrese un nombre: ");
    fflush(stdin);
    fgets(nombre, 100, stdin);
    insertar(pila, nombre);
    printf("Se inserto correctamente el nombre %s en la pila. \n", nombre);
    system("pause");
}



//Eliminar un elemento de la pila
void pop(Pila *pila){
	if(isEmpty(*pila)==0){
		Nodo *f;
		f=pila->cima;
		pila->cima=f->siguiente;
		free(f);
		printf("Se elimino el elemento de la cima de la pila.\n");
	}
	else {
		printf("Pila esta vacia\n\n");
	}
}
	
//Limpiar pila
void limpiarPila(Pila *pila){
	while(!isEmpty(*pila)){
		pop(pila);
	}
}

//Contar cantidad de elementos que tiene la pila
int tamanoPila(Pila pila){
	Nodo *act;
	int cantElementos = 0;
	for(act=pila.cima; act!=NULL; act=act->siguiente){
		cantElementos++;
	}
	return cantElementos;
}

//Menú
int menu(){
	Pila pila;
	char num, i;
	char nom[50];
	system("cls");
	int opc;
	do{
	
	printf("\t\t\t**********Menu de Opciones*********\n\n\n");
	printf("(1) Crear Pila\n");
	printf("(2) Ingresar un elemento a la pila\n");
	printf("(3) Sacar un elemento de la pila\n");
	printf("(4) Tamano de la pila\n");
	printf("(5) Limpiar Pila\n");
	printf("(0) Salir del menu\n");
	printf("\n Ingrese la opcion deseada: ");
	scanf("%i", &opc);
	fflush(stdin);
	switch(opc){
		case 1:crearPila(&pila);
		printf("\nSe ha creado la pila correctamente\n\n");
		break;
		
		case 2: printf("Digite cuantos nombres desea ingresar: ");
		scanf("%i", &num);
		for(i=0; i<num; i++){
		push(&pila);	
		}
		break;
				
		case 3: pop(&pila);
		printf("Se elimino correctamente el primer elemento de la pila");
		fflush(stdin);
		system("pause");
		break;
				
		case 4: printf("La pila tiene %d elementos\n", tamanoPila(pila));
		fflush(stdin);
		system("pause");
		break;
				
		case 5:limpiarPila(&pila);
		fflush(stdin);
		printf("La pila se ha limpiado la pila\n");
		printf("\n La pila tiene %d elementos", tamanoPila(pila));	
		}

	}while(opc!=0);

}


//main
int main(){
	Pila pila;
	system("cls");
	menu();
	
	return 0;
}




