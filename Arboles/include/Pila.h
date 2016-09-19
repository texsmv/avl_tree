#ifndef PILA_H
#define PILA_H
#include "Nodo.h"

using namespace std;

template<class T>
class Pila
{
    public:
        Pila(): m_phead(0) {}
        virtual ~Pila(){};
        void push(T d);
        void imprimir();
        bool isEmpty();
        T top();
        void pop();
    protected:
    private:
        Nodo<T>*m_phead;
};

template<class T>
void Pila<T>::push(T d){
    Nodo<T>*nuevo= new Nodo<T>(d);
    if(!m_phead) m_phead=nuevo;
    else{
        Nodo<T>*temp=m_phead;
        while(temp->m_psig){
            temp=temp->m_psig;
        }
        temp->m_psig=nuevo;

    }
}

template<class T>
void Pila<T>::imprimir(){
    Nodo<T>*temp=m_phead;
    while(temp){
        cout<<temp->m_dato<<endl;
        temp=temp->m_psig;
    }

}


template<class T>
T Pila<T>::top(){
    if(m_phead){
        Nodo<T>*temp=m_phead;
        while(temp->m_psig){
            temp=temp->m_psig;
        }
        return temp->m_dato;
    }
    else{
        cout<<"lista vacia"<<endl;
    }

}



template<class T>
void Pila<T>::pop(){
    if(!m_phead) return;
    Nodo<T>**temp=&m_phead;
    while((*temp)->m_psig){
        temp=&((*temp)->m_psig);
    }
    Nodo<T>*temp2=(*temp);
    (*temp)=0;
    delete temp2;
}

template<class T>
bool Pila<T>::isEmpty(){
    if(!m_phead) return true;
    return false;
}

#endif // PILA_H
