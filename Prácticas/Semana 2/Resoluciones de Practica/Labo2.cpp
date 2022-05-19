#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct Node{
    int valor_node;
    struct Node *next_node;
    Node(int valor){
        valor_node = valor;
        next_node = NULL;
    }
    Node(int valor, Node *next){
        valor_node = valor;
        next_node = next;
    }
};

typedef struct Node *TpNode;

void menu(TpNode & cabecera);
int createRandomInt(int min_value, int max_value);
void insertRandomNode(TpNode & cabecera);
void insertToStart(TpNode & cabecera);
void insertToEnd(TpNode & cabecera);
void insertToPos(TpNode & cabecera, int pos);
void showList(TpNode cabecera);

int main() {
    TpNode cabecera = new Node(createRandomInt(1,100));
    cout<<"Nodo cabecera con valor " <<cabecera->valor_node<<endl;
    menu(cabecera);
    delete cabecera;
    return 0;
}

int createRandomInt(int min_value, int max_value){
    /* initialize random seed: */
    srand (time(NULL));
    return rand() % max_value + min_value;

}

void menu(TpNode & cabecera){
    int opc;
    cout<<"Elija una opcion: "<<endl;
    cout<<"1. Insertar un Node en una posicion aleatoria"<<endl;
    cout<<"2. Mostrar la lista simple y la suma de sus valores"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opcion: ";
    cin>>opc;

    switch (opc) {
        case 1:{
            insertRandomNode(cabecera);
            break;
        }
        case 2:{
            showList(cabecera);
            break;
        }
        case 3:{
            return ;
            break;
        }
        default:{
            menu(cabecera);
        }
    }
    if(opc != 3){
        menu(cabecera);
    }
}

void insertRandomNode(TpNode& cabecera){
    int insert_mode = createRandomInt(1,3);
    switch (insert_mode) {
        case 1:{
            insertToStart(cabecera);
            break;
        }
        case 2:{
            cout<<"Agregando nodo al final de la lista"<<endl;
            insertToEnd(cabecera);
            break;
        }
        default:{
            int pos;
            cout<<"En que posicion desea agregar un nodo?"<<endl;
            cout<<"Nota:Las posiciones inician de 0)"<<endl;
            cout<<"Posicion: ";
            cin>>pos;
            insertToPos(cabecera, pos);
        }

    }

}

void insertToStart(TpNode& cabecera){
    // Creating new Node;
    TpNode new_node = new struct Node(createRandomInt(1,100), NULL);
    new_node->next_node = cabecera;
    cabecera = new_node;
    cout<<"Agregando nodo con valor "<< new_node->valor_node <<" al inicio de la lista"<<endl;
    showList(cabecera);
}


void insertToEnd(TpNode & cabecera){
    // Creating new Node;
    TpNode new_node = new Node(createRandomInt(1,100));
    TpNode temp = cabecera;
    cout<<"Agregando nodo con valor "<< new_node->valor_node <<" al final de la lista"<<endl;
    if(temp->next_node == NULL){
        temp->next_node = new_node;
        return;
    }
    while(temp->next_node != NULL){
        temp = temp->next_node;
    }
    temp->next_node = new_node;
    showList(cabecera);
}

void insertToPos(TpNode & cabecera, int pos){
    if(pos == 0){
        insertToStart(cabecera);
        return;
    }
    int pos_cont = 0;
    TpNode last_node, cabecera_copy = cabecera, temp_node;
    TpNode new_node = new Node(createRandomInt(1,100));

    while(cabecera != NULL && pos_cont < pos){
        last_node = cabecera_copy;
        if(cabecera_copy->next_node == NULL){
            break;
        }
        cabecera_copy = cabecera_copy->next_node;
        pos_cont++;
    }
    if(pos_cont == pos){
        temp_node = cabecera_copy;
        last_node->next_node = new_node;
        (last_node->next_node)->next_node = temp_node;
        cout<<"Agregando nodo con valor "<< new_node->valor_node <<" en la posicion"<<pos<<endl;
    } else {
        cout<<"Posicion no encontrada. Agregando al final"<<endl;
        cabecera_copy->next_node = new_node;
        cout<<"Agregando nodo con valor "<< new_node->valor_node <<" al final."<<endl;
    }
    showList(cabecera);

}

void showList(TpNode cabecera){
    int suma_nodes = 0;
    cout<<"Mostrando lista"<<endl;
    while(cabecera != NULL){
        cout<<cabecera->valor_node<<"->";
        suma_nodes += cabecera->valor_node;
        cabecera = cabecera->next_node;
    }
    cout<<"NULL"<<endl;
    cout<<"Suma de los valores de la lista: "<<suma_nodes<<endl;
}


