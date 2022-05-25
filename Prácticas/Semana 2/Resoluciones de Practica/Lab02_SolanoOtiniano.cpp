#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct nodo;
typedef struct nodo *TpLista; //Pseudonimo

void insertaInicio(TpLista &lista, int a);
void insertaFinal(TpLista &lista, int a);
void inserta2da(TpLista &lista, int a);
void verLista(TpLista lista);

void menu();

int main(){
    TpLista lista=NULL;
    int opcMenu, n,opcGen;
    do{
        menu();
        cin>>opcMenu;

        switch (opcMenu)
        {
        case 0: cout<<" Saliendo del programa ^^)/"<<endl<<endl;
            break;

        case 1:{
            //Generacion de Nodo y Opcion Random
            srand(time(0));
            n=(rand()% 100)+1;
            opcGen=(rand()% 3)+1;

            cout<<"  >Nodo Creado     -->"<<n<<endl;
            cout<<"  >Opcion Generada -->"<<opcGen<<endl;

            switch(opcGen){
                case 1:{
                    insertaInicio(lista,n);
                }break;
                case 2:{
                    insertaFinal(lista,n);
                }break;
                case 3:{
                    inserta2da(lista,n);
                }break;
            }

            } break;

        case 2:{
            verLista(lista);
            } break;

        default: cout<<"\n !Opcion no valida!";
            break;
        }

        system("pause");
    }while(opcMenu !=0);

    return 0;
}


//ESTRUCTURA DE NODOS
struct nodo{
    int nro;
    nodo *sgte;
};

//MENU
void menu(){

    system("CLS");
    cout<<"\n\t LABORATORIO SESION 2\n\n";
    cout<<"1.- Creacion de Nodos"<<endl;
    cout<<"2.- Vizualizacion de Lista"<<endl;
    cout<<"0.- Salir"<<endl<<endl;

    cout<<"Ingresar Opcion ---> ";
}

//Mostrar Lista & Sumatoria
void verLista(TpLista lista){
    int i=0;
    int suma=0;
    if(lista==NULL) cout<<" No hay Nodos para Mostrar"<<endl;
    else{
    cout<<"\n\n\tINICIO -> ";
    while(lista != NULL){
        suma+=lista->nro;
        cout<<lista->nro<<" -> ";
        lista=lista->sgte;
        i++;
    } 
    cout<<"NULL"<<endl;
    cout<<"\tAcumulado de Nodos : "<<suma<<endl<<endl;
    }
}

//----------------------FUNCIONES DE OPCIONES GENERADAS-------------------------------
//Insertar Inicio
void insertaInicio(TpLista &lista, int a){
    TpLista q=NULL;
    q=new(struct nodo);
    q->nro=a;
    q->sgte=lista;
    lista=q;
}

//Insertar Final
void insertaFinal(TpLista &lista, int a){
    TpLista q=NULL;
    TpLista p=lista;
    if(p!=NULL){
    //crear nodo
    q=new(struct nodo);
    q->nro=a;
    q->sgte=NULL;

    
    while(p->sgte != NULL){
        p=p->sgte;
    }
    p->sgte=q;
    } else insertaInicio(lista,a);
}

//Insertar 2da Posicion
void inserta2da(TpLista &lista, int a){
    TpLista q=NULL;
    TpLista r=lista;

    if(lista!=NULL){
    q=new(struct nodo);
    q->nro=a;
    q->sgte=r->sgte;
    r=q;
    lista->sgte=r;
    } else insertaFinal(lista,a);
}
