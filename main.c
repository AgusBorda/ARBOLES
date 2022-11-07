#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct arbol{
char nombre[25];
int edad;
char tipo[25];
};
///GENERAL
void menu(struct arbol arb[]);
///CREAR
struct arbol crearArbolParametro(char n[], int e, char t[]);
struct arbol crearArbolManual();
void crearMuchosArboles(struct arbol a[], int cant);
void crearMuchosArboles2(struct arbol a[], int cant);
///MOSTRAR
void mostrarArbol(struct arbol a);
void mostrarArboles(struct arbol a[], int cant);
void queArbolModificar(struct arbol a[], int cant);
///MODIFICAR
struct arbol modificarArbol(struct arbol *a, char n[],int e, char t[]);
int main()
{
    struct arbol arb[8];
    menu(arb);
    return 0;
}
struct arbol crearArbolParametro(char n[], int e, char t[]){
struct arbol a;
strcpy(a.nombre,n);
strcpy(a.tipo,t);
a.edad=e;
return a;
}
void mostrarArbol(struct arbol a){
printf("\n--ARBOL--");
printf("\n %s", a.nombre);
printf("\n %i", a.edad);
printf("\n %s", a.tipo);
}
struct arbol modificarArbol(struct arbol *a, char n[],int e, char t[]){
strcpy(a->nombre,n);
strcpy(a->tipo,t);
a->edad=e;
return *a;
}
struct arbol crearArbolManual(){
struct arbol a;
printf("\nNombre del arbol:");
fflush(stdin);
gets(a.nombre);
printf("\nEdad:");
scanf("%i", &a.edad);
printf("\nTipo de arbol:");
fflush(stdin);
gets(a.tipo);
system("cls");
return a;
}
void crearMuchosArboles(struct arbol a[], int cant){
int e;
for(e=0;e<cant;e++){
    a[e]=crearArbolManual();
}
}
void crearMuchosArboles2(struct arbol a[], int cant){


    a[cant]=crearArbolManual();

}
void mostrarArboles(struct arbol a[], int cant){
int e;
for(e=0;e<cant;e++){
    printf("\n --ARBOL-- %i",e+1);
    mostrarArbol(a[e]);
}
    printf("\n");
    system("pause");
    system("cls");
}
void queArbolModificar(struct arbol a[], int cant){
int e,h;
char n[25];
char t[25];
int ed;
for(e=0;e<cant;e++){
    printf("\n --ARBOL-- %i",e+1);
    mostrarArbol(a[e]);
}
printf("\nQue arbol deseas modificar?: ");
scanf("%i", &h);
printf("\n");
system("pause");
system("cls");
printf("\n");
mostrarArbol(a[h-1]);
printf("\n\nNuevo nombre:");
fflush(stdin);
gets(n);
printf("\nEdad:");
scanf("%i", &ed);
printf("\n\nNuevo tipo:");
fflush(stdin);
gets(t);
modificarArbol(&a[h-1],n,ed,t);
}
///GENERAL
void menu(struct arbol arb[]){
int a;
int cantArboles=0;
while(a!=5){
printf("\n1. Crear arbol");
printf("\n2. Ver arboles");
printf("\n3. Modificar arbol");
printf("\n4. Buscar arbol");
printf("\n5. Salir");
printf("\nElija una opcion:");
scanf("%i", &a);
switch(a){
case 1:crearMuchosArboles2(arb,cantArboles);
cantArboles=cantArboles+1;
break;
case 2:mostrarArboles(arb,cantArboles);
break;
case 3:queArbolModificar(arb,cantArboles);
break;

  }
 }
}
