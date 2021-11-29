#include <queue>
#include <iostream>

using namespace std;


  bool Iguales(queue<int> A, queue<int> B){
    bool iguales=false;
    if (A.front()==B.front())
      iguales=true;
    return iguales;
    }


//Crea una nueva cola con la intersección de las otras dos introducidas
queue <int> multi_interseccion(queue<int> A, queue<int> B){
    queue<int> aux;
    int num=0;
    if(A.size() > B.size())
      num=B.size();
    else
      num=A.size();


    for(int i=0; i < num; i++){
      if(Iguales(A,B)){
        aux.push(A.front());
        A.pop();
        B.pop();
      }else if (A.front()<B.front()){
        A.pop();
      }else if (B.front()<A.front()){
        B.pop();
      }
    }


     //Las colas ya estan vacias
    return aux;
}//Fin del algoritmo

int main(){
  queue<int>A;
  queue<int>B;
  queue<int>prueba;
  int a=0,b=0;

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
      prueba = multi_interseccion(A,B);

      while(!prueba.empty()){
        cout<<prueba.front()<<" ";
        prueba.pop();
      }

}
