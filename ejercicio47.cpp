#include <queue>
#include <iostream>

using namespace std;

bool noVacios(queue<int> A, queue<int> B){
  bool noVacio=true;
  if (A.empty()){
    if (B.empty())
      noVacio=false;
  }
  return noVacio;
  }

//Une dos colas ordenadas
queue <int> mergeSortedqueues(queue<int> A, queue<int> B){
    queue<int> aux;
    int num=0;

    //Miranos cual es el numero menor para ir ingresando en la cola
    if(A.front() >= B.front())
      num=B.front();
    else
      num=A.front();

    while(noVacios(A,B)){


      while(num==A.front()){
          aux.push(num);
          A.pop();
      }

      while(num==B.front()){
          aux.push(num);
          B.pop();
      }

      num++;

  }
    return aux;
}//Fin del algoritmo

int main(){
  queue<int>A;
  queue<int>B;
  queue<int>prueba;
  int a,b;

  while(a>=0){
    cout<<"Ingrese un dato en la cola A de menor a mayor (para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>a;
    if(a>=0)
      A.push(a);
  }


  while(b>=0){
    cout<<"\nIngrese un dato en la cola B de menor a mayor(para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>b;
    if(b>=0)
      B.push(b);
  }
      cout<<"El resultado de unir ambas colas es: "<<endl;
      prueba = mergeSortedqueues(A,B);

      while(!prueba.empty()){
        cout<<prueba.front()<<" ";
        prueba.pop();
      }

}
