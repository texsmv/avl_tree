#include <iostream>
#include "Binary_tree.h"
#include "avl_tree.h"


using namespace std;

int main()
{
    /*
    Binary_tree<int> tree;
    tree.add2(10);
    tree.add2(7);
    tree.add2(15);
    tree.add2(3);
    tree.add2(9);
    tree.add2(12);
    tree.add2(17);
    NodoT<int>*p=tree.m_pRoot->m_pDer->m_pDer;
    tree.imprimir_pre_orden(tree.m_pRoot);
    NodoT<int>**q;
    */
    //tree.tio_nodo(q,p);
    //cout<<(*q)->m_dato;


    avl_tree<int> cosa;
    cosa.add1(3);
    cosa.add1(6);
    cosa.add1(34);
    cosa.add1(16);
    cosa.add1(25);
    cosa.eliminar(6);
    //cosa.add1(24);
    //cosa.add1(26);

    //cosa.add1(19);
    /*

    NodoT2<int>**p=&cosa.m_pRoot;
    //cosa.add1(2);

    //cosa.add1(25);


    cosa.rotacion_right_right(p);
    cosa.add1(8);
    cosa.add1(12);
    NodoT2<int>**p2=&(cosa.m_pRoot->m_pSon[1]);

    cosa.rotacion_left_right(p2);
    cosa.rotacion_left_left(p2);
    cosa.add1(123);
    NodoT2<int>**p3=&(cosa.m_pRoot);
    cosa.rotacion_right_right(p3);
    */
    cosa.imprimir_por_niveles();
    //cosa.imprimir_camino_nodo(8);
    //cosa.imprimir_alturas_por_niveles();
    //cosa.imprimir_balance_por_niveles();





    return 0;
}
