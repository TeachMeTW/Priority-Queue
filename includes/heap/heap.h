#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
template <typename T>
class Heap
{
public:
    Heap(): _how_many(0) {}
    void insert(const T& insert_me);    //insert into the heap
    void heaper(int root);
    T remove();                         //remove and return top value 
    T top();                            //return the value at the top of heap
    bool is_empty() const;
    int size() const;
    int capacity() const;
    friend ostream& operator << (ostream& outs, const Heap<T>& print_me){
        print_me.print_tree(outs);
        return outs;
    }
    bool verify() const;                //true if tree is verified to be a heap check if parent is bigger
    T *heap_array();                    //returns a copy of underlying array: 
                                        //  don't forget to delete when done

private:
    static const int CAPACITY = 1000;
    T _heap[CAPACITY]; //static array
    int _how_many; //num used

    void print_tree(ostream& outs = cout) const;
    void print_tree(int root, int level = 0, ostream& outs = cout) const;

    bool verify(int root) const;

    bool is_root(int i) const;
    bool is_leaf(int i) const;
    int parent_index(int i) const;
    int left_child_index(int i)const;
    int right_child_index(int i) const;
    int big_child_index(int i) const;
    void swap_with_parent(int i);
};

// Public Functions


template <typename T>
void Heap<T>::insert(const T& insert_me) {
    // check if full
    if (_how_many == CAPACITY) {
        return;
    }
    
    int i = _how_many;
    _how_many++;
    // inserts at the end
    _heap[i] = insert_me;
    // if not at first and input is greater than parent swap
    while (i != 0 && _heap[i] > _heap[parent_index(i)]) {
        swap_with_parent(i);
        i = parent_index(i);
    }
    
}

template <typename T>
void Heap<T>::heaper(int root) {
    // checks left and right
    int left = left_child_index(root);
    int right = right_child_index(root);
    int largest = root;

    // determines which one is bigger

    if (right <= _how_many && _heap[right] > _heap[largest]) {
        largest = right;
    }
    if (left <= _how_many && _heap[left] > _heap[largest]) {
        largest = left;
    }

    // if largest is not root set to largest and call recursively
    if (largest != root) {
        T temp = _heap[root];
        _heap[root] = _heap[largest];
        _heap[largest] = temp;
        heaper(largest);
    }
}

template <typename T>
T Heap<T>::remove() {
    // check if only 1 value
    if (_how_many == 1) {
        _how_many--;
        return _heap[0];
    }
    T root = _heap[0];
    _heap[0] = _heap[_how_many-1];
    _how_many--;
    // reorganizes 
    heaper(0);
    return root;
}

template <typename T>
T Heap<T>::top() {
    // one after root
    T top = _heap[0];
    return top;
}

template <typename T>
bool Heap<T>::is_empty() const {
    if (_how_many <= 0) {
        return true;
    }
    return false;
}

template <typename T>
int Heap<T>::size() const {
    return _how_many;
}

template <typename T>
int Heap<T>::capacity() const {
    return CAPACITY;
}

template <typename T>
bool Heap<T>::verify() const {
    // verify all members
    for (int i = 0; i < _how_many; i++) {
        verify(i);
    }
}

template <typename T>
T* Heap<T>::heap_array() {
    // creates a copy array and returns
    T* copy = new T[_how_many];
    for (int i = 0; i < _how_many; i++) {
        copy[i] = _heap[i];
    }
    return copy; 

}

// private functions

template <typename T>
void Heap<T>::print_tree(ostream& outs) const {
    print_tree(0, 0);
    /*
    for (int i = 0; i < _how_many/2; i++) {
        outs << "Parent: " <<" [" << _heap[i] <<"]"<< endl;
        outs << "Left: " << " [" << _heap[left_child_index(i)] << "]" << endl;
        outs << "Right: " << " [" << _heap[right_child_index(i)] << "]" << endl;
    }
    */
}

template <typename T>
void Heap<T>::print_tree(int root, int level, ostream& outs) const {
    // checks left root and right
    if (!(root >= _how_many)) {
        print_tree(right_child_index(root), level+1);
        outs << setw(4*level) << "" << "[" << _heap[root] << "]" << endl;
        print_tree(left_child_index(root), level+1); 
    }
}

template <typename T>
bool Heap<T>::verify(int root) const {
    // checks left and right
    int l = left_child_index(root);
    int r = right_child_index(root);
    bool leftsmall = false;
    bool rightsmall = false;
    // determines that they are smaller than root

    if (l < _how_many && _heap[l] < _heap[root]) {
        leftsmall = true;
    }
    if (r < _how_many && _heap[r] < _heap[root]) {
        rightsmall = true;
    }
    // if both smaller return true
    if (rightsmall && leftsmall) {
        return true;
    }
    return false;
}

template <typename T>
bool Heap<T>::is_root(int i) const {
    return i==0;
}

template <typename T>
bool Heap<T>::is_leaf(int i) const {
    if (i > (_how_many/2) && i <= _how_many) {
        return true;
    }
    return false;
}

template <typename T>
int Heap<T>::parent_index(int i) const{
    return ((i-1)/2);
}

template <typename T>
int Heap<T>::left_child_index(int i) const {
    return (2*i + 1);
}

template <typename T>
int Heap<T>::right_child_index(int i) const {
    return (2*i + 2);
}

template <typename T> 
int Heap<T>::big_child_index(int i) const {
    // determines which is bigger
    if (_heap[left_child_index(i)] > _heap[right_child_index(i)]) {
        return left_child_index(i);
    }
    if (_heap[right_child_index(i)] > _heap[left_child_index(i)]) {
        return right_child_index(i);
    }
}

template <typename T>
void Heap<T>::swap_with_parent(int i) {
    // basic swap
    T y = _heap[i];
    T x = _heap[parent_index(i)];
    _heap[parent_index(i)] = y;
    _heap[i] = x;
}

#endif // HEAP_H