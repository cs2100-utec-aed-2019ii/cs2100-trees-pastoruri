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

    ///Constructores

    Tree():root(nullptr){}

    Tree(T rootKey):root(rootKey){}

    ///Metodos

    void insert_node(T insertNodeKey){

        if(root->key == nullptr){
            root->key == insertNodeKey;
        }
        else{
            auto temp=root;
            Node<T>* aux(insertNodeKey);

            if(insertNodeKey > root->key){
                    Site1:
                    while(temp->key < insertNodeKey){
                        temp = temp->right;
                    }
                    if(temp->left == nullptr){
                        temp->left == aux;
                    }
                    else{
                        temp = temp->left;
                        goto Site1;
                    }
            }

            else if(insertNodeKey < root->key){
                Site2:
                while(temp->key > insertNodeKey){
                    temp = temp->left;
                }
                if(temp->right == nullptr){
                    temp->right == aux;
                }
                else{
                    temp = temp->right;
                    goto Site2;
                }
            }
        }
    }


    void delete_node(T deleteNodeKey){
        if(root->key == nullptr){
            cout<<endl<<"Tree is empty, no node is to be deleted"<<endl;
        }
        else{
            auto temp=root;
            auto newroot=root;
            Site1:
            if(deleteNodeKey > newroot->key){

                while(temp->key <= deleteNodeKey){
                    auto aux = temp;
                    temp = temp->right;
                }

                if(temp == deleteNodeKey){
                    auto aux = temp->left;
                    temp->left = nullptr;
                }
                else{
                    if(temp->left == nullptr) {cout<<endl<<"Given node does not exist"<<endl;}
                    temp = temp->left;
                    newroot=temp;
                    goto Site1;
                }

            }

            else if(deleteNodeKey < newroot->key){

                while(temp->key >= deleteNodeKey){
                    auto aux = temp;
                    temp = temp->left;
                }

                if(temp == deleteNodeKey){
                    auto aux = temp->right;
                    temp->right = nullptr;
                }
                else if(temp->right->key == deleteNodeKey){
                        auto aux1= temp;
                        if(temp->right->left == nullptr){
                            temp->right = temp->right->right;
                        }
                        else{
                            while(aux1->right->right != nullptr){
                                aux1 = aux1->right;
                            }
                            temp = aux1->right;
                            aux1 ->right == nullptr;

                        }

                }
                else{
                    if(temp->right == nullptr) {cout<<endl<<"Given node does not exist"<<endl;}
                    newroot=temp;
                    goto Site1;
                }

            }

        }



    }
};



#endif //TREES_TREE_H

