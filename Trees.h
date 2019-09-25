#ifndef TREES_TREE_H
#define TREES_TREE_H
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Node {
public:
    T key;
    Node<T> *left;
    Node<T> *right;
    Node(T key) { this->key = key; this->left = this->right = nullptr; }
    ~Node() {}
};

template <typename T>class Tree{
public:
    Node<T> * root;
    int height=0;
    Tree(){root=nullptr;}
    Tree(T rootKey){root = new Node<T>(rootKey);}

    ///Metodos
    bool isEmpty(){return root==nullptr;}

    void insert(T data) {
        Node<T>* nodo = new Node<T>(data);
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

Node<T>* deleteNode(Node<T>* root, int value) {

        if (root == nullptr)
            return root;

        if (value < root->key) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->key) {
            root->right = deleteNode(root->right, value);
        } else {

            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr)
                return root->left;

            root->key = inOrderSuccessor(root->right);
            root->right = deleteNode(root->right, root->key);
        }

        return root;

    }

T inOrderSuccessor(Node<T>* root) {

        T minimum = root->key;
        while (root->left != nullptr) {
            minimum = root->left->key;
            root = root->left;
        }
        return minimum;
    }




    Node<T>* getroot(){return root;}

    void inOrderImprimir(Node<T>* node ){
        if (node == nullptr) return;
        inOrderImprimir(node->left);
        cout << node->key << " ";
        inOrderImprimir(node->right);
    }

    void postOrderImprimir(Node<T>* node){
        if (node == nullptr) return;
        postOrderImprimir(node->left);
        postOrderImprimir(node->right);
        cout << node->key << " ";
    }

    void preOrderImprimir(Node<T>* node){
        if (node == nullptr) return;
        cout << node->key << " ";
        preOrderImprimir(node->left);
        preOrderImprimir(node->right);
    }


    void ContarHeightConInOrder(Node<T>* node ){
        if (node == nullptr) return;
        ContarHeightConInOrder(node->left);
        ContarHeightConInOrder(node->right);
        height++;
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

    bool SonIdenticos(Node<T>* rootDelOtroArbol){
      return SonIdenticosAux(root, rootDelOtroArbol);
    }

    int Altura(){
        ContarHeightConInOrder(root);
        height = height/2+1;
        return height;
    }

    

};



#endif //TREES_TREE_H

