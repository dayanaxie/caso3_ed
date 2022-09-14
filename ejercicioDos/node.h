#include <iostream>

#ifndef NODE 

#define NODE 1

class Node {
    private:
        int data;
        Node *siguiente;
    
    public:
        Node() {
            siguiente = NULL;
        }
        int getData() {
            return data;
        }

        void setData(int pData){
            this->data = pData;
        }

        Node* getNext() {
            return siguiente;
        }

        void setNext(Node *pValue) {
            this->siguiente = pValue;
        }
};

#endif


