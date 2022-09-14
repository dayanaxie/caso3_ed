
#include "list.h"


template <class T>
class QueueOfStacks {
    private:
        Node* queueOfStacksList;
    public:
        Queue() {
            queueList = NULL;
            stackOne = new List<T>();
            stackTwo = new List<T>();
        }

        // agregar al final
        void enqueue(T* pNewNode) {
            while(!stackOne->isEmpty()){
                for(Node node : stackOne){
                    stackTwo->add(node);        
                    stackOne->remove(node);
                }
            }
            stackOne->add(pNewNode);
            while (!stackTwo->isEmpty()){
                for(Node node : stackTwo){
                    stackOne->add(node);
                    stackTwo->delete(node);
                }
                
            }
        }
        T* dequeue() {
            T* result = NULL;
            if (!stackOne->isEmpty()) {
                Node firstNode = stackOne->getFirst();
                stackOne->delete(firstNode);         
            }
            return result;            
        }
        T* front() {
            T* result = NULL;
            if (!queueOfStacksList->isEmpty()) {
                result = queueOfStacksList->find(0);
            }
            return result;
        }

        bool isEmpty() {
            return queueOfStacksList->isEmpty();
        }


};

