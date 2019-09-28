#ifndef TREES_TREE_H
#define TREES_TREE_H
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class Node {
public:
    T key;
    Node<T> *left;
    Node<T> *right;
    explicit Node(T key) { this->key = key; this->left = this->right = nullptr; }
    ~Node() {}
};

template <typename T>class Tree{
public:
    Node<T> * root;
    int height=0;
    Tree(){root=nullptr;}
    explicit Tree(T rootKey){root = new Node<T>(rootKey);}

    ///Metodos
    ~Tree(){TREE_eliminar_arbol(root);}
    Node<T>* getroot()  {return  root;}
    bool isEmpty(){return root==nullptr;}
//----------------------------------------INSERTAR_NODO

    void TREE_insertar_nodo(T key) {
        auto* nodo = new Node<T>(key);
        if (root == nullptr) {
            root = nodo;
        }
        else if (root != nullptr) {
            for (Node<T>* temp = this->root; temp != nullptr;) {
                if (temp->key > nodo->key) {
                    if (temp->left == nullptr) {
                        temp->left = nodo;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else if (temp->key < nodo->key) {
                    if (temp->right == nullptr) {
                        temp->right = nodo;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }

    }

//----------------------------------------ELIMINAR_NODO
    Node<T>* TREE_eliminar_nodo( int value) {

        return eliminar_nodo(this->root,value);
    }

    Node<T>* eliminar_nodo(Node<T>* &root1, int value) {

        if (root1 == nullptr)
            return root1;

        if (value < root1->key) {
            root1->left = eliminar_nodo(root1->left, value);
        } else if (value > root1->key) {
            root1->right = eliminar_nodo(root1->right, value);
        } else {

            if (root1->left == nullptr) {
                return root1->right;
            } else if (root1->right == nullptr)
                return root1->left;

            root1->key = min(root1->right);
            root1->right = eliminar_nodo(root1->right, root1->key);
        }

        return root1;

    }
    T min(Node<T>* root) {

        T minimum = root->key;
        while (root->left != nullptr) {
            minimum = root->left->key;
            root = root->left;
        }
        return minimum;
    }


//----------------------------------------IN_ORDER_IMPRIMIR

    void TREE_inOrderImprimir(){
        inOrderImprimir(this->root);
    }

    void inOrderImprimir(Node<T>* node ){
        if (node == nullptr) return;
        inOrderImprimir(node->left);
        cout << node->key << " ";
        inOrderImprimir(node->right);
    }

//----------------------------------------POST_ORDER_IMPRIMIR

    void TREE_postOrderImprimir(){
        postOrderImprimir(this->root);
    }

    void postOrderImprimir(Node<T>* node){
        if (node == nullptr) return;
        postOrderImprimir(node->left);
        postOrderImprimir(node->right);
        cout << node->key << " ";
    }
//----------------------------------------PRE_ORDER_IMPRIMIR

    void TREE_preOrderImprimir(){
        preOrderImprimir(this->root);
    }
    void preOrderImprimir(Node<T>* node){
        if (node == nullptr) return;
        cout << node->key << " ";
        preOrderImprimir(node->left);
        preOrderImprimir(node->right);
    }

//----------------------------------------COMPROBAR_SI_2_TREES_SON_IGUALES

    bool TREE_SonIdenticos(Node<T>* rootDelOtroArbol){
        bool aux = SonIdenticosAux(root, rootDelOtroArbol);
        if(aux){
            cout<<"Son identicos"<<endl;
            return true;
        }
        else{
            cout<<"No son identicos"<<endl;
            return false;
        }
    }

    int SonIdenticosAux(Node<T>* rootFromTree1, Node<T>* rootFromTree2){

        if (rootFromTree1 == nullptr && rootFromTree2 == nullptr)
            return 1;
        if (rootFromTree1 != nullptr && rootFromTree2 != nullptr){
            return (rootFromTree1->key == rootFromTree2->key &&
                    SonIdenticosAux(rootFromTree1->left, rootFromTree2->left) &&
                    SonIdenticosAux(rootFromTree1->right, rootFromTree2->right));
        }
        return 0;
    }

//----------------------------------------CALCULAR_ALTURA


    int TREE_Altura(){
        ContarHeightConInOrder(root);

            height = height/2+1;

        return height;
    }
    int TREE_Altura_node(Node<T>* node) {
        ContarHeightConInOrder(node);
        height = height / 2 + 1;
        return height;
    }
    void ContarHeightConInOrder(Node<T>* node ){
        if (node == nullptr) return;
        ContarHeightConInOrder(node->left);
        ContarHeightConInOrder(node->right);
        height++;
    }
//----------------------------------------ELIMINAR_ARBOL

    void TREE_eliminar_arbol(Node<T>* &root1)
    {
        if (root1 == nullptr)
            return;
        TREE_eliminar_arbol(root1->left);
        TREE_eliminar_arbol(root1->right);
        delete root1;
        root1 = nullptr;
    }
//----------------------------------------ENCONTRAR_NODO_VECINO_EN_MISMO_NIVEL

    Node<T>* TREE_nodo_vecino(T value){
        auto aux = search(value,this->root);
        cout<<"Vecino: "<<nodo_vecino(this->root,aux)->key<<endl;
        return nodo_vecino(this->root,aux);
    }

    Node<T>* nodo_vecino(Node<T>* root1, Node<T>* node) {
        if (node == nullptr){
            return node;
        }
        bool in_this_level = false;
        queue< Node<T>* > q;
        q.push(root1);

        while (!q.size()>-1) {
            int cant_nodos = q.size();
            vector< Node<T>* > nodos_en_mismo_nivel(0);

            while (cant_nodos > 0) {
                Node<T>* _node = q.front();
                nodos_en_mismo_nivel.push_back(_node);
                q.pop();
                if (_node->left != nullptr)
                    q.push(_node->left);
                if (_node->right != nullptr)
                    q.push(_node->right);
                --cant_nodos;
            }
            int nodes_in_same_level_size = nodos_en_mismo_nivel.size();
            int indice_nodo;
            for (int i = 0; i < nodes_in_same_level_size; ++i) {
                if (node == nodos_en_mismo_nivel[i]) {
                    in_this_level = true;
                    indice_nodo = i;
                    break;
                }
            }
            if (in_this_level && indice_nodo != nodes_in_same_level_size-1 && nodes_in_same_level_size > 1) {
                return nodos_en_mismo_nivel[indice_nodo+1];
            }

        }
        return node;
    }
    Node<T>* search(T value, Node<T>* node){
        if(node != nullptr){
            if(node->key==value){
                return node;
            } else {
                Node<T>* foundNode = search(value, node->left);
                if(foundNode == nullptr) {
                    foundNode = search(value, node->right);
                }
                return foundNode;
            }
        } else {
            return nullptr;
        }
    }
//----------------------------------------ES_ARBOL_COMPLETO
    bool TREE_es_completo(){
        int i=0;
        bool completo = es_completo(this->root,i,contar_nodos(this->root));
        if(completo){
            cout<<endl<<"Es completo"<<endl;
            return true;
        }
        else{
            cout<<endl<<"No es completo"<<endl;
            return false;
        }
    }

    bool es_completo (struct Node<T>* root1,  int index, int number_nodes)
    {
        if (root1 == nullptr)
            return (true);

        if (index >= number_nodes)
            return (false);

        return (es_completo(root1->left, 2*index + 1, number_nodes) &&
                es_completo(root1->right, 2*index + 2, number_nodes));
    }
    int contar_nodos(struct Node<T>* root1){
        if (root1 == nullptr)
            return (0);
        return (1 + contar_nodos(root1->left) + contar_nodos(root1->right));
    }

    //----------------------------------------IMPRIMIR_CAMINOS
    void TREE_imprimir_camino(){
        cout<<"Root key: "<<this->root->key<<endl;
        imprimir_camino_completo(this->root);
    }

    bool es_Hoja(Node<T>* node){
        return (node->left == nullptr && node->right == nullptr);
    }

    void imprimir_camino(vector<int> const &path){
        for (int i = path.size() - 1; i > 0; i--)
            cout << path.at(i) << " <- ";

        cout << path.at(0) << endl;
    }

    void imprimir_camino_completo(Node<T>* node, vector<int> &path){
        if (node == nullptr)
            return;
        path.push_back(node->key);
        if (es_Hoja(node))
            imprimir_camino(path);
        imprimir_camino_completo(node->left, path);
        imprimir_camino_completo(node->right, path);
        path.pop_back();
    }
    void imprimir_camino_completo(Node<T>* node){
        vector<int> path;
        imprimir_camino_completo(node, path);
    }
//----------------------------------------ENCONTRAR_ANCESTROS
    void TREE_find_ancestors_value(T value){
        if(value!=this->root->key) {
            auto node = search(value, this->root);
            vector<int> path;
            imprimir_camino_completo_a(this->root, path, value);
            cout << "El ancestro es: " << height << endl;
            TREE_Altura();
        }
        else{
            cout<<"La raiz no tiene ancestros"<<endl;
        }

    }
    void TREE_find_ancestors_node(Node<T>* value){
        if(value!=this->root->key) {
            auto node = value;
            vector<int> path;
            imprimir_camino_completo_a(this->root, path, value);
            cout << "El ancestro es: " << height << endl;
            TREE_Altura();
        }
        else{
            cout<<"La raiz no tiene ancestros"<<endl;
        }

    }
    void imprimir_camino_aux1(vector<int> const &path, T key){
        for (int i = path.size() - 1; i > 0; i--){
            if (path.at(i)==key){
                height = path.at(i-1);
            }
        }


    }

    void imprimir_camino_completo_a(Node<T>* node, vector<int> &path, T key){
        if (node == nullptr)
            return;

        path.push_back(node->key);
        if (es_Hoja(node))
            imprimir_camino_aux1(path, key);
        imprimir_camino_completo_a(node->left, path, key);
        imprimir_camino_completo_a(node->right, path, key);
        path.pop_back();
    }

//----------------------------------------ES_BALANCEADO
    bool TREE_es_balanceado(){
        bool aux = es_balanceado(this->root);
        if(aux){
            cout<<"Es balanceado"<<endl;
            return true;
        }
        else{
            cout<<"No es balanceado"<<endl;
            return false;
        }
    }


    bool es_balanceado(Node<T>* root){
        int lh;
        int rh;
        if (root == nullptr)
            return 1;
        lh = TREE_Altura_node(root->left);
        rh = TREE_Altura_node(root->right);
        if (abs(lh - rh) <= 1 && es_balanceado(root->left) && es_balanceado(root->right))
            return 1;

        return 0;
    }
//----------------------------------------ES_BST
    bool TREE_isBST() {
        vector<T> vec;
        inOrderImprimir_a(this->root,vec);
        bool pero_eres_o_no_eres=true;
        for(int i=1;i<vec.size();i++){
            if(vec[i-1]>vec[i]){
                pero_eres_o_no_eres=false;
            }
        }

        if(pero_eres_o_no_eres){
            cout<<"Es bst"<<endl;
            return true;
        }
        else{
            cout<<"No es bst"<<endl;
            return false;
        }
    }
    bool TREE_isBST_node(Node<T>* node) {
        vector<T> vec;
        inOrderImprimir_a(node,vec);
        bool pero_eres_o_no_eres=true;
        for(int i=1;i<vec.size();i++){
            if(vec[i-1]>vec[i]){
                pero_eres_o_no_eres=false;
            }
        }

        if(pero_eres_o_no_eres){
            cout<<"Es bst"<<endl;
            return true;
        }
        else{
            cout<<"No es bst"<<endl;
            return false;
        }

    }

    void inOrderImprimir_a(Node<T>* node,vector<T> &aux ){
        if (node == nullptr) return;
        inOrderImprimir_a(node->left,aux);
        aux.push_back(node->key);
        inOrderImprimir_a(node->right,aux);
    }
};



#endif //TREES_TREE_H

