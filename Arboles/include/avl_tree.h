#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "NodoT.h"
#include "NodoT2.h"
#include "Cola.h"



using namespace std;

template <class T>
class avl_tree
{
    public:
        avl_tree(): m_pRoot(0) {}
        bool add1(T d);
        bool add2(T d);
        void eliminar(T d);
        void imprimir_por_niveles();
        void imprimir_alturas_por_niveles();
        void imprimir_balance_por_niveles();
        void imprimir_camino_nodo(T d);
        virtual ~avl_tree(){};
        bool find1(T,NodoT2<T>**&);
        bool find2(T,NodoT2<T>**&,Cola<NodoT2<T>*>*);
        int nodo_nivel(NodoT2<T>*p);
        void balancear(NodoT2<T>*&p);
        void balancear2(NodoT2<T>**&p);
        void rotacion_left_left(NodoT2<T>**&p);
        void rotacion_right_right(NodoT2<T>**&p);
        void rotacion_left_right(NodoT2<T>**&p);
        void rotacion_right_left(NodoT2<T>**&p);
        bool inclinacion(NodoT2<T>*p);
        int indice_de_balance(NodoT2<T>*p);
        NodoT2<T>* m_pRoot;
    protected:
    private:

};

//------------------funciones find---------------------

template<class T>
bool avl_tree<T>::find1(T d, NodoT2<T>**& p){
    p=&m_pRoot;
    while(*p){
        if((*p)->m_dato==d) return true;
        if((*p)->m_dato<d) p=&((*p)->m_pSon[1]);
        else p=&((*p)->m_pSon[0]);
    }
    return false;
}

template<class T>
bool avl_tree<T>::find2(T d,NodoT2<T>**& p,Cola<NodoT2<T>*>* cola){
    p=&m_pRoot;
    while(*p){
        if((*p)->m_dato==d) return true;
        cola->push(*p);
        if((*p)->m_dato<d) p=&((*p)->m_pSon[1]);
        else p=&((*p)->m_pSon[0]);
    }
    return false;
}


//----------------------------funciones add-------------

template<class T>
bool avl_tree<T>::add1(T d){
    NodoT2<T>**q;
    if(find1(d,q)) return false;
    (*q)= new NodoT2<T>(d);
    nodo_nivel(m_pRoot);
    NodoT2<T>**p=&m_pRoot;
    //balancear2(p);
    balancear(m_pRoot);
    cout<<"-------------"<<endl;
    return true;

}


//----------------------------funciones imprimir-------------

template<class T>
void avl_tree<T>::imprimir_camino_nodo(T d){
    NodoT2<T>*temp=m_pRoot;
    while(temp->m_dato!=d){
        cout<<temp->m_dato<<endl;
        if(temp->m_dato>d) temp=temp->m_pSon[0];
        else temp=temp->m_pSon[1];
    }

}


template<class T>
void avl_tree<T>::imprimir_por_niveles(){
    if(!m_pRoot) return;
    Cola<NodoT2<T>*> cola;
    cola.push(m_pRoot);
    while(!cola.isEmpty()){
        NodoT2<T>*temp=cola.top();
        cola.pop();
        cout<<temp->m_dato<<endl;
        if(temp->m_pSon[0]) cola.push(temp->m_pSon[0]);
        if(temp->m_pSon[1]) cola.push(temp->m_pSon[1]);
    }
}

template<class T>
void avl_tree<T>::imprimir_alturas_por_niveles(){
    if(!m_pRoot) return;
    Cola<NodoT2<T>*> cola;
    cola.push(m_pRoot);
    while(!cola.isEmpty()){
        NodoT2<T>*temp=cola.top();
        cola.pop();
        cout<<temp->m_altura<<endl;
        if(temp->m_pSon[0]) cola.push(temp->m_pSon[0]);
        if(temp->m_pSon[1]) cola.push(temp->m_pSon[1]);
    }
}

template<class T>
void avl_tree<T>::imprimir_balance_por_niveles(){
    if(!m_pRoot) return;
    Cola<NodoT2<T>*> cola;
    cola.push(m_pRoot);
    while(!cola.isEmpty()){
        NodoT2<T>*temp=cola.top();
        cola.pop();
        cout<<indice_de_balance(temp)<<endl;
        if(temp->m_pSon[0]) cola.push(temp->m_pSon[0]);
        if(temp->m_pSon[1]) cola.push(temp->m_pSon[1]);
    }
}


template<class T>
int avl_tree<T>::nodo_nivel(NodoT2<T>*p){
    if(!p) return -1;
    return p->m_altura=1+max(nodo_nivel(p->m_pSon[0]),nodo_nivel(p->m_pSon[1]));
}

template<class T>
void avl_tree<T>::balancear(NodoT2<T>*&p){
    if(!p) return;
    balancear(p->m_pSon[0]);
    balancear(p->m_pSon[1]);
    if(!p->m_pSon[0]&&!p->m_pSon[1]){
        return;
    }
    NodoT2<T>**temp=&p;
    if(p->m_pSon[0]&&p->m_pSon[1]){
        if(indice_de_balance(p)>1){
            if(indice_de_balance(p->m_pSon[0])>0){
                rotacion_left_left(temp);
            }
            else{
                rotacion_left_right(temp);
                rotacion_left_left(temp);
            }
        }
        else if(indice_de_balance(p)<-1){
            if(indice_de_balance(p->m_pSon[1])>0){
                rotacion_right_left(temp);
                rotacion_right_right(temp);
            }
            else{
                rotacion_right_right(temp);
            }
        }
        return;
    }
    else if(p->m_pSon[0]){
        if(indice_de_balance(p)>1){
            if(indice_de_balance(p->m_pSon[0])>0){
                rotacion_left_left(temp);
            }
            else{
                rotacion_left_right(temp);
                rotacion_left_left(temp);
            }
        }
    }
    else if(p->m_pSon[1]){
        if(indice_de_balance(p)<-1){
            if(indice_de_balance(p->m_pSon[1])>0){
                rotacion_right_left(temp);
                rotacion_right_right(temp);
            }
            else{
                rotacion_right_right(temp);
            }
        }
    }
    nodo_nivel(m_pRoot);
}
/*
template<class T>
void avl_tree<T>::balancear2(NodoT2<T>**&p){
    if(!(*p)) return;
    NodoT2<T>**a=&((*p)->m_pSon[0]);
    NodoT2<T>**b=&((*p)->m_pSon[1]);
    balancear2(a);
    balancear2(b);
    if((*p)->m_pSon[0]&&(*p)->m_pSon[1]){
        if(indice_de_balance(*p)<-1){//lado derecha mayor
            int indice=indice_de_balance((*p)->m_pSon[1]);
            if(indice<-1){
                rotacion_right_right(p);
            }
            else if(indice>1){
                rotacion_right_left(p);
                rotacion_right_right(p);
            }
        }
        else if(indice_de_balance(*p)>1){//lado izquierdo mayor
            int indice=indice_de_balance((*p)->m_pSon[0]);
            if(indice<-1){
                rotacion_left_right(p);
                rotacion_left_left(p);

            }
            else if(indice>1){
                rotacion_left_left(p);
            }
        }
    }
    else if((*p)->m_pSon[1]){
        indice_de_balance(*p);
        int indice=indice_de_balance((*p)->m_pSon[1]);
        if(indice<=-1){
            rotacion_right_right(p);
        }
        else if(indice>=1){
            rotacion_right_left(p);
            rotacion_right_right(p);
        }
    }
    else if((*p)->m_pSon[0]){
        int indice=indice_de_balance((*p)->m_pSon[0]);
        if(indice<=-1){
            rotacion_left_right(p);
            rotacion_left_left(p);
        }
        else if(indice>=1){
            rotacion_left_left(p);
        }
    }
    nodo_nivel(m_pRoot);
}
*/
template<class T>
int avl_tree<T>::indice_de_balance(NodoT2<T>*p){
    cout<<p->m_dato<<"->";
    if(!p){
        return 0;
        cout<<"vacio"<<endl;
    }
    if(!p->m_pSon[0]&&!p->m_pSon[1]){
        cout<<0<<endl;
        return 0;
    }
    if(p->m_pSon[0]&&p->m_pSon[1]){
        cout<<p->m_pSon[0]->m_altura-p->m_pSon[1]->m_altura<<endl;
        return p->m_pSon[0]->m_altura-p->m_pSon[1]->m_altura;
    }
    if(p->m_pSon[0]){
        cout<<p->m_pSon[0]->m_altura +1<<endl;
        return p->m_pSon[0]->m_altura +1;
    }
    if(p->m_pSon[1]){
        cout<<-1-p->m_pSon[1]->m_altura<<endl;
        return -1-p->m_pSon[1]->m_altura;
    }

}

template<class T>
void avl_tree<T>::rotacion_left_left(NodoT2<T>**&p){
    NodoT2<T>*temp=(*p);
    (*p)=temp->m_pSon[0];
    if((*p)->m_pSon[1]) temp->m_pSon[0]=(*p)->m_pSon[1];
    else temp->m_pSon[0]=0;
    (*p)->m_pSon[1]=temp;
}

template<class T>
void avl_tree<T>::rotacion_right_right(NodoT2<T>**&p){
    NodoT2<T>*temp=(*p);
    (*p)=temp->m_pSon[1];
    if((*p)->m_pSon[0]) temp->m_pSon[1]=(*p)->m_pSon[0];
    else temp->m_pSon[1]=0;
    (*p)->m_pSon[0]=temp;


}

template<class T>
void avl_tree<T>::rotacion_left_right(NodoT2<T>**&p){
    NodoT2<T>*temp=(*p)->m_pSon[0];
    (*p)->m_pSon[0]=temp->m_pSon[1];
    if(temp->m_pSon[1]->m_pSon[0]) temp->m_pSon[1]=temp->m_pSon[1]->m_pSon[0];
    else temp->m_pSon[1]=0;
    (*p)->m_pSon[0]->m_pSon[0]=temp;
}

template<class T>
void avl_tree<T>::rotacion_right_left(NodoT2<T>**&p){
    NodoT2<T>*temp=(*p)->m_pSon[1];
    (*p)->m_pSon[1]=temp->m_pSon[0];
    if(temp->m_pSon[0]->m_pSon[1]) temp->m_pSon[0]=temp->m_pSon[0]->m_pSon[1];
    else temp->m_pSon[0]=0;
    (*p)->m_pSon[1]->m_pSon[1]=temp;
}

//----------------------------------eliminar------------
template<class T>
void avl_tree<T>::eliminar(T d){
    NodoT2<T>**p;
    if(!find1(d,p)) return;
    NodoT2<T>*temp=*p;
    if(!(*p)->m_pSon[0]&&!(*p)->m_pSon[1]){
        *p=0;
        delete temp;
    }
    else if((*p)->m_pSon[0]&&(*p)->m_pSon[1]){
        p=&(temp->m_pSon[0]);
        while((*p)->m_pSon[1]){
            p=&((*p)->m_pSon[1]);
        }
        temp->m_dato=(*p)->m_dato;
        temp=*p;
        if((*p)->m_pSon[0]) *p=(*p)->m_pSon[0];
        else *p=0;
        delete temp;

    }
    else if((*p)->m_pSon[0]){
        *p=(*p)->m_pSon[0];
        delete temp;
    }
    else if((*p)->m_pSon[1]){
        *p=(*p)->m_pSon[1];
        delete temp;
    }
    nodo_nivel(m_pRoot);
    balancear(m_pRoot);
}

#endif // AVL_TREE_H
