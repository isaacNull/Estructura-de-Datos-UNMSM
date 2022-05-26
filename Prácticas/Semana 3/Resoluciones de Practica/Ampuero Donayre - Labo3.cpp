#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Crea la estructura
struct Node{
    int valor_node;
    struct Node *next_node;
    //Constructores
    Node(){
        next_node = NULL;
    };

    Node(int valor){
        valor_node = valor;
        next_node = NULL;
    }
    ;
    void giveNodeValue(int max_value){
        cout<<"Ingrese un valor para el nuevo nodo."<<endl;
        cout<<"Debe ser menor a "<<max_value<<" y par" <<endl;
        do{
            cout<<"Valor: "<<endl;
            cin>>valor_node;
            if(valor_node > max_value || valor_node % 2 != 0)
                cout<<"El valor ingresado es mayor al maximo permitido o es impar. Ingrese un valor valido."<<endl;

        }while(valor_node > max_value || valor_node % 2 != 0);
    }
};

typedef struct Node *Node_ptr;

void menu(Node_ptr & list_head);
int createRandomPairInt(int max_value, int min_value);
void insertToEnd(Node_ptr & list_head);
void deleteMiddleNode(Node_ptr &list_head);
void deleteNode(Node_ptr &list_head, int pos_to_delete);
void showList(Node_ptr list_head);
void showNodesCount(Node_ptr list_head);
// Main

int main() {
    Node_ptr list_head = NULL;
    menu(list_head);
    delete list_head;
    return 0;
}

// Crea un int random entre 2 limites
int createRandomPairInt(int max_value, int min_value){
    /* initialize random seed: */
    srand (time(NULL));
    int value = rand() % max_value + min_value;
    return value * 2;
}

// Menu
void menu(Node_ptr & list_head){
    int opc;
    cout<<"Elija una opcion: "<<endl;
    cout<<"1. Insertar un nodo con valor par al final de la lista."<<endl;
    cout<<"2. Mostrar la cantidad de nodos ingresados y su suma acumulada."<<endl;
    cout<<"3. Mostrar la lista."<<endl;
    cout<<"4. Eliminar nodo en la posicion del medio"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Opcion: ";
    cin>>opc;

    switch (opc) {
        case 1: {
            insertToEnd(list_head);
            showList(list_head);
            break;
        }
        case 2:{
            showNodesCount(list_head);
            break;
        }
        case 3:{
            showList(list_head);
            break;
        }
        case 4:{
            deleteMiddleNode(list_head);
            showList(list_head);
            break;

        }
        default:{
            break;
        }

    }
    if(opc != 5){
        menu(list_head);
    }
}


// Inserta al final
void insertToEnd(Node_ptr & list_head){

    if(!list_head){ //La lista no tiene ningun nodo
        int value;
        cout<<"Ingrese un valor para el primer nodo"<<endl;
        cin>>value;
        Node_ptr new_node = new Node(value); // Crea un nuevo nodo
        list_head = new_node;
        return;
    }
    Node_ptr list_head_copy = list_head; // Variable temporal

    while(list_head_copy->next_node){ // Recorre la lista hasta el ultimo nodo
        list_head_copy = list_head_copy->next_node;
    }
    int value_last_node = list_head_copy->valor_node;
    Node_ptr new_node = new Node(); // Crea un nuevo nodo
    new_node->giveNodeValue(value_last_node);
    list_head_copy->next_node = new_node;
    cout<<"Agregando nodo con valor "<< new_node->valor_node <<" al final de la lista"<<endl;
}

void deleteNode(Node_ptr &list_head, int pos_to_delete){
    Node_ptr last_node, next_node, list_head_copy = list_head;
    int pos_cont = 1;
    while(list_head && pos_cont < pos_to_delete){
        last_node = list_head_copy; // Se guarda el nodo anterior
        if(!list_head_copy->next_node){ // Cuando se llega al ultimo elemento
            break;
        }
        list_head_copy = list_head_copy->next_node; // Se avanza en la lista
        next_node = list_head_copy->next_node; // se guarda el nodo que siga en la iteraciopb
        pos_cont++; // Aumenta el contador
    }

    if(pos_cont == pos_to_delete){
        cout<<"Eliminando el nodo en la posicion "<< pos_to_delete <<" con valor "<<list_head_copy->valor_node<<"."<<endl;
        last_node->next_node = next_node;
        delete list_head_copy;
    } else {
        cout<<"Posicion no encontrada, la lista solo tiene "<<pos_cont<<" nodos."<<endl;
    }
}

void deleteMiddleNode(Node_ptr &list_head){
    if(!list_head){
        return;
    }

    if(!list_head->next_node){
        cout<<"Eliminando el primer nodo de la lista con valor "<<list_head->valor_node<<"."<<endl;
        list_head = NULL;
        return;
    }
    int nodes_count = 0;
    Node_ptr list_head_copy = list_head;
    while(list_head_copy){
        nodes_count++;
        list_head_copy = list_head_copy->next_node;
    }
    if(nodes_count == 2){
        Node_ptr first_node = list_head;
        list_head = list_head->next_node;
        delete first_node;
        return;
    }
    if(nodes_count % 2 == 0){
        deleteNode(list_head, nodes_count/2);
    } else {
        deleteNode(list_head, (nodes_count + 1) / 2);
    }

}


// Muestra la lista
void showList(Node_ptr list_head){
    if(!list_head){
        cout<<"La lista se encuentra vacia."<<endl;
        return;
    }
    cout<<"Mostrando lista"<<endl;
    while(list_head){
        cout << list_head->valor_node << "->";
        list_head = list_head->next_node;
    }
    cout<<"NULL"<<endl;
}

// Muestra la cantidad de nodos y su suma acumulada
void showNodesCount(Node_ptr list_head){
    if(!list_head){
        cout<<"La lista se encuentra vacia."<<endl;
        return;
    }
    int suma_nodes = 0;
    int cont_nodes = 0;
    while(list_head){
        cont_nodes++;
        suma_nodes += list_head->valor_node;
        list_head = list_head->next_node;
    }
    cout<<"Nodos ingresados: " << cont_nodes <<" | Suma de sus valores acumulados:"<<suma_nodes<<endl;
}


