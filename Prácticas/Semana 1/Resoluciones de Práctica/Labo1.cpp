#include <iostream>
#include <vector>
// Para usar random
#include <stdlib.h> 
#include <time.h>       

using namespace std;

void insertToVectors(vector<int> &A, vector<int> &B); // Añade elementos a los vectores A y B
void insertToC(vector<int> &A, vector<int> &B, vector<int> &C); //Añade un elemento al vector c
void showVector(vector<int> vec, char vectorName); //Muestra los elementos de un vector
void menu(vector <int> &A, vector <int> &B, vector <int> &C); //Menu

int main(){
    srand (time(NULL));
    vector <int> array_A;
    vector <int> array_B;
    vector <int> array_C;
    menu(array_A, array_B, array_C);
}

void menu(vector <int> &A, vector <int> &B, vector <int> &C){
    int opc;
    cout<<"\nElija una opcion: "<<endl;
    cout<<"1. Agregar un elemento al array A y B"<<endl;
    cout<<"2. Agregar un elemento al array C"<<endl;
    cout<<"3. Mostrar estado de los arrays A,B y C"<<endl;
    cout<<"4. Salir del programa"<<endl;
    cout<<"Opcion: ";
    cin>>opc;
    switch (opc)
        {
        case 1:{
            insertToVectors(A, B);
            break;
        }    
        case 2:{
            insertToC(A,B,C);
            break;
        }
        case 3:{
            showVector(A, 'A');
            showVector(B, 'B');
            showVector(C, 'C');
            break;
        }
        case 4:{
            break;
        }
    }
    if (opc != 4){
        menu(A,B,C);
    }
}

// Crea un numero random entre 1 y 100
int createRandomNumber(){
    return rand() % 100 + 1;
}

// Añade un elemento a los vectores A y B
void insertToVectors(vector<int> &A, vector<int> &B){
    int rand_A = createRandomNumber() * -1;
    int rand_B = createRandomNumber();
    A.insert(A.begin(), rand_A);
    B.insert(B.begin(), rand_B);
    cout<<"Elemento ["<<rand_A<<"] insertado en el array A"<<endl;
    cout<<"Elemento ["<<rand_B<<"] insertado en el array B"<<endl;
}

// Añade un elemento al vector C
void insertToC(vector<int> &A, vector<int> &B, vector<int> &C){
    if(A.size() == 0){
        cout<<"Los vectores A y B se encuentran vacios. Ingrese valores en ellos antes de agregar valores al array C"<<endl;
        return;
    }
    int elementToInsert = A[0]+ B[0];
    C.insert(C.begin(),(A[0]+ B[0]));
    cout<<"Elemento ["<<elementToInsert <<"] agregado al array C"<<endl;
    cout<<"Elemento ["<<A[0]<<"] eliminado del array A"<<endl;
    cout<<"Elemento ["<<B[0]<<"] eliminado del array B"<<endl;
    A.erase(A.begin());
    B.erase(B.begin());
}


// Muestra los elementos de un vector
void showVector(vector<int> vec, char vectorName){
    int sizeVec = vec.size();
    if(sizeVec == 0){
        cout<<"\nEl array "<<vectorName<<" se encuentra vacio"<<endl;
    } else {
        cout<<"\nMostrando elementos del vector "<<vectorName<<": ";
        cout<<"["; 
        for(int i = 0; i < sizeVec; i++){
            if(i < vec.size() - 1 ){
                cout<<vec[i]<<",";
            } else {
                cout<<vec[i]<<"]";
            }
        }
    }
}
