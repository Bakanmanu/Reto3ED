#include <stack>
#include <iostream>

using namespace std;



stack <int> coctel(stack<int> &A, stack<int> &B){
    stack<int> aux;
    int tam;
    int tam_max=A.size()+B.size();
    if(A.size() > B.size())
      tam=B.size();
    else
      tam=A.size();

    for (int i =0; i<tam_max;i++ ){
      if(i<=tam){
          if(i%2==0){
            aux.push(B.top());
            B.pop();
          }else if(i%2!=0){
            aux.push(A.top());
            A.pop();
          }
      }else if(!B.empty()){
        aux.push(B.top());
        B.pop();
      }else if(!A.empty()){
        aux.push(A.top());
        A.pop();
      }

    }
    return aux;
}//Fin del algoritmo

int main(){
  stack<int>A;
  stack<int>B;
  stack<int>prueba;
  int a=0,b=0;

  while(a>=0){
    cout<<"Ingrese un dato en la pila A (para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>a;
    if(a>=0)
      A.push(a);
  }

  while(b>=0){
    cout<<"\nIngrese un dato en la pila B (para terminar con el ingreso introduzca un valor negativo)"<<endl;
    cin>>b;
    if(b>=0)
      B.push(b);
  }

      cout<<"El resultado de unir ambas pilas es: "<<endl;
      prueba = coctel(A,B);

      while(!prueba.empty()){
        cout<<prueba.top()<<" ";
        prueba.pop();
      }

}
