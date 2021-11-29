// g++ -o ejercicio54 ejercicio54.cpp

#include <iostream>
#include <list>
#include <queue>

using namespace std;


void construyeCola(list< queue<int> > &l, queue<int> &c){
    list<queue<int>>::iterator it;                  // Iterador para recorrer la lista de colas

    for(it=l.begin(); it!=l.end(); ++it){           // bucle que recorre la lista, accediendo el iterador a las colas listadas
        while(!it->empty()){                        // mientras que la cola a la que apunte el iterador no este vacía
            c.push(it->front());                   // añade los valores de esa cola a la cola c
            it->pop();                              // borra los valores que ya han sido introducidos
        }
    }
}

int main(){
    // Declaracion de las colas y lista
    list< queue<int> > lista;               
    queue <int> c1, c2 ,c3, c4, c_fin;
    
    //Inicializacion de las colas
    for (int i = 1; i<3; i++){
        c1.push(i);
        c2.push(i+2);
        c3.push(i+4);
        c4.push(i+6);
    }
    
    //Inicializacion de la lista
    lista.push_back(c1);
    lista.push_back(c2);
    lista.push_back(c3);
    lista.push_back(c4);

    //Comprobacion de la inicializacion de las colas y lista
    cout <<"c1 = {"<< c1.front()<< ", " << c1.back() <<"}"<<endl;
    cout <<"c2 = {"<< c2.front()<< ", " << c2.back() <<"}"<<endl;
    cout <<"c3 = {"<< c3.front()<< ", " << c3.back() <<"}"<<endl;
    cout <<"c4 = {"<< c4.front()<< ", " << c4.back() <<"}"<<endl;
    
    cout << "Los primeros valores de las colas insertadas son: "<< endl;
    for(list<queue<int>>::iterator it=lista.begin(); it!=lista.end(); ++it){
        cout << it->front() << " ";                                             // Comprobamos la insercion accediendo al primer valor de cada cola
    }

    //Realizamos la funcion
    construyeCola(lista, c_fin);

    cout << endl << endl;
    // Comprobamos que se hayan insertado todos los valores en la cola imprimiendolos
    cout << " La cola construida es: " << endl;
    while(!c_fin.empty()){
        cout << c_fin.front() << " ";       // Muestra el valor del frente de la cola
        c_fin.pop();                        // Lo elimina para poder acceder al resto de la cola
    }
    
    cout << endl;                           //cout para que en mi terminal no muestre un '%' al final de la ejecucion
    return 0;
}