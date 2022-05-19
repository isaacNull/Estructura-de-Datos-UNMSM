#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Crea la estructura
struct Node{
    int valor_node;
    struct Node *next_node;
    //Constructores
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

// Main
int main() {
    TpNode cabecera = new Node(createRandomInt(1,100));
    cout<<"Nodo cabecera con valor " <<cabecera->valor_node<<endl;
    menu(cabecera);
    delete cabecera;
    return 0;
}

// Crea un int random entre 2 limites
int createRandomInt(int min_value, int max_value){
    /* initialize random seed: */
    srand (time(NULL));
    return rand() % max_value + min_value;

}

// Menu
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

// Elige una opcion aleatoria entre 1 y 3 para añadir un nodo
void insertRandomNode(TpNode& cabecera){
    int insert_mode = createRandomInt(1,3);
    switch (insert_mode) {
        case 1:{
            cout<<"Agregando nodo al inicio de la lista"<<endl;
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
            cout<<"Nota:Las posiciones inician de 0"<<endl;
            cout<<"Posicion: ";
            cin>>pos;
            insertToPos(cabecera, pos);
        }

    }

}

// Inserta un nodo al inicio
void insertToStart(TpNode& cabecera){
    TpNode new_node = new struct Node(createRandomInt(1,100), NULL); // Crea un nodo nuevo
    new_node->next_node = cabecera; // El puntero del nuevo nodo apunta a la cabecera
    cabecera = new_node; // cabecera se iguala al nuevo nodo
    cout<<"Agregando nodo con valor "<< new_node->valor_node <<" al inicio de la lista"<<endl;
    showList(cabecera);
}


// Inserta al final
void insertToEnd(TpNode & cabecera){
    // Creating new Node;
    TpNode new_node = new Node(createRandomInt(1,100)); // Crea un nuevo nodo
    TpNode cabecera_copy = cabecera; // Variable temporal
    cout<<"Agregando nodo con valor "<< new_node->valor_node <<" al final de la lista"<<endl;
    if(cabecera_copy->next_node == NULL){ // En caso solo se tenga un nodo en la lista
        cabecera_copy->next_node = new_node;
        return;
    }
    while(cabecera_copy->next_node != NULL){ // Recorre la lista hasta el ultimo nodo
        cabecera_copy = cabecera_copy->next_node;
    }
    cabecera_copy->next_node = new_node;
    showList(cabecera);
}

// Inserta un nodo en una posicion dada
void insertToPos(TpNode & cabecera, int pos){
    if(pos == 0){ // Cuando la posicion es 0
        insertToStart(cabecera);
        return;
    }
    int pos_cont = 0;
    TpNode last_node, cabecera_copy = cabecera, temp_node;
    TpNode new_node = new Node(createRandomInt(1,100));

    // Recorre la lista hasta que se llegue al ultimo elemento O se llegue a la posicion ingresada
    while(cabecera != NULL && pos_cont < pos){
        last_node = cabecera_copy; // Se guarda el nodo anterior
        if(cabecera_copy->next_node == NULL){ // Cuando se llega al ultimo elemento
            break;
        }
        cabecera_copy = cabecera_copy->next_node; // Se avanza en la lista
        pos_cont++; // Aumenta el contador
    }

    if(pos_cont == pos){ // Si la lista contiene la posicion dada
        temp_node = cabecera_copy; // Se guarda en una variable temporal el nodo en la posicion dada
        last_node->next_node = new_node; // El nodo anterior a la posicion dada apunta al nuevo nodo a insertar
        (last_node->next_node)->next_node = temp_node; // El nuevo nodo insertado apunta al nodo que antes estaba en su posicion
        cout<<"Agregando nodo con valor "<< new_node->valor_node <<" en la posicion"<<pos<<endl;
    } else {
        cout<<"Posicion no encontrada. Agregando al final"<<endl;
        cabecera_copy->next_node = new_node;
        cout<<"Agregando nodo con valor "<< new_node->valor_node <<" al final."<<endl;
    }
    showList(cabecera);

}

// Muestra la lista
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


