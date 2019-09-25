#ifndef TREES_TREE_H
#define TREES_TREE_H
#include <iostream>
using namespace std;


template <typename T>
class Node {
public:
    T key;
    Node<T> *left;
    Node<T> *right;

    Node(T key) {
        this->key = key;
        this->left = this->right = nullptr;
    }

    ~Node() {

    }
};

template <typename T>class Tree{

public:

    Node<T> * root;

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



   Node<T>* deleteNode(Node<T>* rootaux, int key){

        if (rootaux == nullptr) cout<<endl<<"Tree not initialized"<<endl;

        if (key < rootaux->key)
            rootaux->left = deleteNode(rootaux->left, key);
        else if (key > rootaux->key)
            rootaux->right = deleteNode(rootaux->right, key);
        else{
            if (rootaux->left == NULL){
                Node<T> *temp = rootaux->right;
                free(rootaux);
            }
            else if (rootaux->right == NULL){
                Node<T> *temp = rootaux->left;
                free(rootaux);
            }
            ///TODO : IMPLEMENT MIN
            Node<T>* temp = min(rootaux->right);
            rootaux->key = temp->key;
            rootaux->right = deleteNode(rootaux->right, temp->key);
        }
    }
    Node<T>* getroot(){return root;}

    void inOrderPrint(Node<T>* node ){
        if (node == nullptr) return;
        inOrderPrint(node->left);
        cout << node->key << " ";
        inOrderPrint(node->right);


    }

    void printPreorder(Node<T>* node)
    {
        if (node == nullptr) return;
        cout << node->key << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
    void printPostorder(Node<T>* node)
    {
        if (node == nullptr) return;
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->key << " ";
    }


};



#endif //TREES_TREE_H

