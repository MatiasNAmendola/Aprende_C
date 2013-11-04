#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodo {
      int dato;
      struct nodo *sig;
};

typedef struct nodo NODO; //defino un sinónimo NODOpara la estructura

// Prototipos
NODO* eliminarlista (NODO *p);
NODO* crearlista();
NODO* crearnodo();
NODO* insertarnodo(NODO *aux, NODO *p);
NODO* eliminarprimernodo(NODO *p);
NODO* eliminartodosloselementos(NODO *p);
NODO* insertarnodoordenado(NODO *l,NODO *n);
void eliminarultimonodo (NODO *p);
void imprimirlista ( NODO *l);
NODO* buscarelementoenlista (NODO *p,int n);
int listavacia(NODO *p);

int main()
{
    NODO *lista,*aux;
    int j = 0;
    lista = NULL;
    if(listavacia(lista)==1){
        printf("Lista Vacia\n\n");
    }
    lista = crearlista();
    
    for(j=0;j<2;j++)
    {
         aux = crearnodo();
         lista = insertarnodo(aux,lista);
    }
    imprimirlista(lista);
    
    getch();
    
    lista = eliminartodosloselementos(lista);
    
    
    printf("Presione una tecla para salir...");
    getch();
    return 0;
}

NODO* eliminarlista(NODO *p) {
    if (p->sig == NULL) //es el último nodo
       free(p);
    else {
       printf("NO ES EL ULTIMO");
    }
    return p;
}
NODO* crearlista() {
    NODO *p;
    p = (NODO *)malloc(sizeof(NODO));
    p->dato = 0; //le asigno un valor a la parte datos del nodo
    p->sig = NULL; //el NODO apunta a null
    return p; 
}
NODO* crearnodo() {
    NODO *p;
    p = (NODO *)malloc(sizeof(NODO));
    printf("Ingrese dato: ");
    scanf("%d", &p->dato);//le asigno un valor a la parte datos del nodo
    p->sig = NULL; // el NODO apunta a null
    return p;
}

//inserta un nodo al principio de la lista
NODO* insertarnodo(NODO *aux, NODO *p) {      
     aux->sig = p;
     p = aux;
     return p;
}
int listavacia(NODO *p){
    if (p == NULL)
          return 1;
    
    return 0;
}

NODO* eliminarprimernodo(NODO *p){
    NODO *aux;
    aux = p;
    p = p->sig;
    free(aux);
    return p;
}

NODO* eliminartodosloselementos( NODO *p ) {
    NODO *aux;
    while (p!= NULL) {
        aux = p;
        p = p->sig;
        free(aux); 
    } 
    return p; 
}
/*
lista: se pasa el puntero que guarda la dirección de memoria
en donde COMIENZA la lista.
nodo: se pasa el puntero del nodo aislado que se desea insertar
*/
NODO* insertarnodoordenado(NODO *lista,NODO *nodo){
     NODO *aux;
     /*
      Si el dato del nodo aislado es menor al dato del primer
      nodo de la lista, el puntero del nodo aislado (sig) guarda la
      posicion de memoria correspondiente al principio de la
      lista y devuelve el puntero al nodo insertado que ahora
      se enlazo como inicio de la lista.
      */
    if (nodo->dato < lista->dato){
       nodo->sig = lista;
       return nodo;
    }
    /*
      Si el dato del nodo aislado no es menor al dato del primer
      nodo de la lista debera recorrer la lista para agregar el nodo
      aislado.    
    */
    else{
         /*
           Se conserva en primera instancia la posicion 
         */
        aux = lista;
        while (aux->sig != NULL && (aux->sig->dato < nodo->dato) )
              aux = aux->sig;
        
        if (aux->sig == NULL)
           aux->sig = nodo; //llego al final de la lista
        else{
             nodo->sig=aux->sig;
             aux->sig=nodo;
        }
    }
}

void eliminarultimonodo(NODO *p) {
     NODO *aux, *ant;
     aux = p;
     if (aux->sig == NULL) {
        printf("TIENE UN SOLO NODO");
     } 
     while (aux->sig != NULL){
           printf("entro!\n");
           ant = aux;
           aux = aux->sig;
     } 
     ant->sig=NULL;
     free(aux);
}
void imprimirlista(NODO *lista) {
     if (lista!=NULL) {
        printf("\n****************** display de la lista ******************\n\n");
        while (lista->sig != NULL)
        {
              printf ("| %d ", lista->dato);
              lista = lista->sig;
        }
        printf ("| %d | \n", lista->dato);
        printf("\n****************** display de la lista ******************\n");
     }
}
NODO* buscarelementoenlista(NODO *p,int n){
      int rdo=0;
      while( p !=NULL) {
             if(p->dato==n)
                   break;
             p=p->sig;
      }
      return p;
}