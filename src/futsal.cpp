// include header file here
#include "../include/futsal.h"
#include "../include/llqueue.h"
// add your findBestInBatch function here (optional helper function)
// to avoid making the teamBestOfBatch function too long
//Player *findBestInBatch(Queue *q, Queue *tmp_q, int batch_size) {

//}

// add your teambestOfBatch function here
Player *teamBestOfBatch(Queue *q, int k){
    if (q->head == nullptr) return nullptr;
    Player *temp = nullptr;
    Player** arr = new Player*[k];
    int best = 0;

    for (int i = 0; i < k; ++i){
        arr[i] = nullptr;
    } 

    for (int i = 0; i < k; ++i){
        if (queueFront(q) != nullptr){
            temp = copyPlayer(queueFront(q));
            arr[i] = temp;
            queuePopPlayerEntry(q);
            if (temp->num_goals > arr[best]->num_goals){
                best = i;
            }
        }
    }

    for (int i = 0; i < k; ++i){
        if (arr[i] != nullptr){
            if (i != best){
                queuePushPlayerEntry(q, arr[i]);
            }
        }
    }
    Player *bestplayer = arr[best];
    delete[] arr;

    return bestplayer;


/*
    LLNode *now = tmp_q->head;
    LLNode *best = tmp_q->head;

    while (now != nullptr) {
        if (best->entry->num_goals < now->entry->num_goals){
            best = now;
        }
        now = now->next;
    }

    now = tmp_q->head;
    
    while (now != nullptr) {
        if (now != best){
            queuePushPlayerEntry(q, now->entry);
        }
        now = now->next;
    }
    Player *best_player_copy = copyPlayer(best->entry);
    deleteQueue(tmp_q);
    now = nullptr
    delete temp;
    return best_player_copy;
*/
}

// add your teamCreateFromBest function here
void teamCreateFromBest(Queue *applicant_q, Queue *welcome_q, int batch_size){
    for (int i = 0; i < 5; ++i){
        queuePushPlayerEntry(welcome_q, teamBestOfBatch(applicant_q, batch_size));
    }
}
