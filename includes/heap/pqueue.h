#ifndef PQUEUE_H
#define PQUEUE_H

#include "../../includes/heap/heap.h"
using namespace std;

template <typename T>
struct info{
    T item;
    int priority;
    int time;

    info():item(T()), priority(0), time(0){

    }
    info(T i, int p):item(i), priority(p), time(0){
    }

    friend ostream& operator <<(ostream& outs, const info<T>& print_me){
        const bool tldr = true;
        outs << "\nItem: " << print_me.item << endl << "Priority: " << print_me.priority << endl <<
        "Time: " << print_me.time << endl;
        return outs;
    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs){
        if (lhs.priority == rhs.priority) {
            return lhs.time > rhs.time;
        }
        return lhs.priority < rhs.priority;
    }
    /*friend bool operator <=(const info<T>& lhs, const info<T>& rhs){
        return lhs.priority <= rhs.priority;
    }
    */
    friend bool operator >(const info<T>& lhs, const info<T>& rhs){
        if (lhs.priority == rhs.priority) {
            return lhs.time < rhs.time;
        }
        return lhs.priority > rhs.priority;
    }
    /*friend bool operator >=(const info<T>& lhs, const info<T>& rhs){
        return lhs.priority >= rhs.priority;
    }
    */

};

template <typename T>
class PQueue
{
public:
    PQueue(){}

    bool push(const T& value, int p);
    T pop();
    info<T> Pop_debug();
    bool is_empty() const;
    int size() const;
    void print_tree() const;
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        outs<<print_me._heap;
        return outs;
    }
    bool verify() const;
private:
    Heap<info<T> > _heap;

};

// Function def

template <typename T>
bool PQueue<T>::push(const T& value, int p) {
    // create timestamp with signature parameters
    info<T> timestamp(value, p);
    // set time to current size
    timestamp.time = _heap.size();
    // push
    _heap.insert(timestamp);

    return true;
}

template <typename T>
T PQueue<T>::pop() {
    return _heap.remove().item;
}

template <typename T>
info<T> PQueue<T>::Pop_debug() {

    return _heap.remove();
}

template <typename T>
bool PQueue<T>::is_empty() const {
    return _heap.is_empty();
}

template <typename T>
int PQueue<T>::size() const {
    return _heap.size();
}

template <typename T>
void PQueue<T>::print_tree() const {
    _heap.print_tree();
}

template <typename T>
bool PQueue<T>::verify() const {
    return _heap.verify();
}

#endif // PQUEUE_H