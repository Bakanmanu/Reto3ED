// g++ -o ejercicio50 ejercicio50.cpp

#include <iostream>
#include <list>

using namespace std;

bool esPar(int v){
    bool par=false;
    if(v%2==0)
        par=true;
return par;
}

void deja1solo(list<int> &L){
    list<int>  aux;                     // Lista en la que se almacenara la lista resultado
    list<int>::iterator it;             // Iterador con el que operaremos con la lista

    bool anterior_par = esPar(L.front());       // Comprobamos si el primer valor de la lista es par o no
    aux.push_back(L.front());                   // Ya que este lo introducimos siempre

    for(it=L.begin(); it!=L.end();++it){
        if(anterior_par){                       // Si el anterior numero introducido en la nueva lista es par, buscamos un numero impar y viceversa 
            if(!esPar(*it)){                    // Si cumple que es impar, 
                aux.push_back(*it);             // lo introduce en la lista auxiliar y
                anterior_par = false;           // permuta anterior_par
            }   
        }else{                                  // Realiza lo mismo en caso de que el anterior entero sea impar,
            if(esPar(*it)){                     // Comprueba si es par,
                aux.push_back(*it);             // lo introduce en caso afirmativo
                anterior_par = true;            // y permuta anterior_par
            }
        }
    }

    L.swap(aux);                                // Una vez terminado el bucle, intercambia la lista auxiliar con la original    
    aux.clear();                                // Y limpiamos la lista auxiliar
}

int main(){
    int enteros1[] = {5,4,5,3,4,9,10,4,9,3,2,10,3,7,5,3};           // Vectores que contienen los datos de prueba
    int enteros2[] = {10,10,1,9,7,4,4,10,7,1,1,4,10,1,1,7};

    list<int> lista1, lista2;
    lista1.assign(enteros1, enteros1+16);                           //Inicializacion de las listas con los valores de los vectores anteriores
    lista2.assign(enteros2, enteros2+16);

// Impresion de los valores iniciales en las listas

    cout <<"Datos iniciales de Lista1:"<< endl;
    for(list<int>::iterator it=lista1.begin(); it!=lista1.end(); ++it)
        cout << *it << " "; 


    cout << endl <<"Datos iniciales de Lista2:"<< endl;
    for(list<int>::iterator it=lista2.begin(); it!=lista2.end(); ++it)
        cout << *it << " "; 

    cout << endl << endl;

//Ejecutamos la funcion a las listas

    deja1solo(lista1);
    deja1solo(lista2);

//Mostramos el resultado de la funcion anterior

    cout <<"Datos finales de Lista1:"<< endl;
    for(list<int>::iterator it=lista1.begin(); it!=lista1.end(); ++it)
        cout << *it << " "; 


    cout << endl <<"Datos finales de Lista2:"<< endl;
    for(list<int>::iterator it=lista2.begin(); it!=lista2.end(); ++it)
        cout << *it << " "; 

    cout << endl;                   //Este endl es para evitar que se imprima en mi terminal un % al final de la ejecucion
    return 0;
}