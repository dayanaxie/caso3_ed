#include "QueueOfStacks.h"
using namespace std;

int main(){
    QueueOfStacks<int>*queueOfStacks = new QueueOfStacks<int>();
    queueOfStacks->enqueue(new int(1));
    queueOfStacks->enqueue(new int(2));
    queueOfStacks->enqueue(new int(3));
    while (!queueOfStacks->isEmpty()) {
        cout << *queueOfStacks->dequeue() << endl;
    }


}