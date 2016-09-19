#ifndef NODOT2_H
#define NODOT2_H

template<class T>
class avl_tree;

template<class T>
class NodoT2
{
    public:
        NodoT2(T d){ m_pSon[0]=0; m_pSon[1]=0; m_dato=d; m_altura=0;}
        virtual ~NodoT2(){};
        NodoT2<T>* m_pSon[2];
    protected:
    private:

        T m_dato;
        int m_altura;
    friend class avl_tree<T>;
};

#endif // NODOT2_H
