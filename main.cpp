#include <iostream>
#include "Trees.h"
int main() {
    Tree<float> t;
    t.TREE_insertar_nodo(1);
    t.TREE_insertar_nodo(-1);
    t.TREE_insertar_nodo(3);
    t.TREE_insertar_nodo(2);
    t.TREE_insertar_nodo(4);
    t.TREE_insertar_nodo(0);
    t.TREE_insertar_nodo(-2);
    t.TREE_insertar_nodo(6);
    t.TREE_inOrderImprimir();
    cout<<endl;
    t.TREE_eliminar_nodo(6);

    t.TREE_inOrderImprimir();


    Tree<float> t1;
    t1.TREE_insertar_nodo(1);
    t1.TREE_insertar_nodo(-1);
    t1.TREE_insertar_nodo(3);
    t1.TREE_insertar_nodo(2);
    t1.TREE_insertar_nodo(4);
    t1.TREE_insertar_nodo(0);
    t1.TREE_insertar_nodo(-2);
    cout<<endl;
    t.TREE_SonIdenticos(t1.getroot());

    t1.TREE_insertar_nodo(6);
    t1.TREE_insertar_nodo(7);

    cout<<endl;
    auto a = t1.TREE_Altura();

    delete &t1;

   // cout<<t1.getroot()->key<<endl; da error si es que no esta inicialziado el arbol, por ende, lo ha borrado bien

    cout<<a<<endl;

    t.TREE_nodo_vecino(-1);

    t.TREE_es_completo();

    t.TREE_imprimir_camino();

    t.TREE_es_balanceado();

    t.TREE_isBST();


    return 0;
}
