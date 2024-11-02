// include the header file here
#include "../include/llqueue.h"

// add all your llqueue functions in here.
LLNode *newLLNode(Player *p){
    LLNode *node = new LLNode;
    node->entry = p;
    node->next = nullptr;
    return node;
}

void deleteLLNode(LLNode *lln){
    if (lln != nullptr){
        deletePlayer(lln->entry);
        delete lln;
        return;
    }
}

Queue *newQueue(){
    Queue *q = new Queue;
    q->size = 0;
    q->head = nullptr;
    q->tail = nullptr;
    return q; 
}

void queuePushPlayerEntry(Queue *q, Player *entry){
    LLNode *new_node = newLLNode(entry);
    if (q->size == 0){
        q->head = new_node;
        q->tail = new_node;
    }else{
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->size++;
}

void queuePopPlayerEntry(Queue *q){
    if (q == nullptr || q->size == 0){
        return;
    }else{
        LLNode *temp = q->head;
        q->head = q->head->next;
        q->size--;
        if (q->size == 0){
            q->tail = nullptr;
        }
        temp->next = nullptr;
        delete temp;
        temp = nullptr; 
    }
}

Player *queueFront(Queue *q){
    return q->head->entry;
}

Player *queueBack(Queue *q){
    return q->tail->entry;
}

std::size_t queueSize(const Queue *q){
    return q->size;
}

void printQueue(const Queue *q){
    LLNode *tmp = q->head;
    while (tmp) {
        std::cout << "Player name: " << tmp->entry->name << std::endl;
        std::cout << "Total goals: " << tmp->entry->num_goals << std::endl;
        tmp=tmp->next;
    }
}

void deleteQueue(Queue *q){
    if (q == nullptr) 
        return;
    while (q->head != nullptr) {
        LLNode *nextNode = q->head->next;
        delete q->head;
        q->head = nextNode;
    }
    q->tail = nullptr;
    delete q; 
}
