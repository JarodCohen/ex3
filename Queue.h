#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <iostream>

const int DEFAULT_SIZE = 10;
const int INITIAL_INDEX = 0;

template<class T>
class Queue{
public:
    class Iterator;
    class ConstIterator;
    Queue():m_maxSize(DEFAULT_SIZE),
            m_data(new T [DEFAULT_SIZE]),
            m_firstIndex(INITIAL_INDEX),
            m_nextIndex(INITIAL_INDEX)
    {}   
    Queue(const Queue& queue): m_maxSize(queue.m_maxSize),
            m_data(new T [queue.m_maxSize]),
            m_firstIndex(INITIAL_INDEX),
            m_nextIndex(queue.size())
    {
        for(int i = queue.m_firstIndex; i<queue.m_nextIndex; i++){
            m_data[i - queue.m_firstIndex] = queue.m_data[i];
        }
    }
    Queue<T>& operator=(const Queue<T>& queue){
        if(this == &queue){
            return *this;
        }
        m_maxSize = queue.m_maxSize;
        m_firstIndex = INITIAL_INDEX;
        m_nextIndex = queue.size();
        T* newData = new T[m_maxSize];
        T* dataToDelete = m_data;
        for(int i = queue.m_firstIndex; i < queue.m_nextIndex; i++){
            newData[i - queue.m_firstIndex] = queue.m_data[i];
        }
        m_data = newData;
        delete[] dataToDelete;
        return *this;
    }
    void expandTheQueue(){
        if (this->size() < m_maxSize - (DEFAULT_SIZE/2)){
            if (m_firstIndex > INITIAL_INDEX){
                for(int i = m_firstIndex; i<m_nextIndex; i++){
                    newData[i - m_firstIndex] = queue.m_data[i];
                }
            }
        }
        else{
            T* newData = new T [m_maxSize + DEFAULT_SIZE];
            for(int i = m_firstIndex; i<m_nextIndex; i++){
                newData[i - m_firstIndex] = queue.m_data[i];
            }
            T* dataToDelete = m_data;
            m_data = newData;
            delete dataToDelete;
        }
        m_nextIndex = this->size();
        m_firstIndex = INITIAL_INDEX;
    }
    void shrinkTheQueue(){
       T* newData = new T [m_maxSize - DEFAULT_SIZE];
       for(int i = m_firstIndex; i<m_nextIndex; i++){
                newData[i - m_firstIndex] = queue.m_data[i];
            }
        T* dataToDelete = m_data;
        m_data = newData;
        delete dataToDelete;
        m_nextIndex = this->size();
        m_firstIndex = INITIAL_INDEX;
    } 
    
    void pushback(const T& toPush){
        if(m_nextIndex == m_maxSize){
            expandTheQueue()
        }
        m_data[m_nextIndex++] = toPush;
    }
    T front(){
        return m_data[m_firstIndex];
    }
    void popFront(){
        m_firstIndex++;
        if (this->size() < m_maxSize - DEFAULT_SIZE){
            shrinkTheQueue();
        }
    }
    int size(){
        return m_nextIndex - m_firstIndex;
    }


private:
    int m_maxSize;
    T* m_data;
    int m_firstIndex;
    int m_nextIndex;
};

template <class T , class F>
Queue<T> filter(const Queue<T>& queue, F fonction){
    Queue<T> newQueue;
    Queue<T> tmpQueue = queue;
    for(int i = 0; i < queue.size(); i++){
        if(fonction(tmpQueue.front())){
            newQueue.pushback(tmpQueue.front());
        }
        tmpQueue.popFront();
    }
    return newQueue;
}

template <class T , class F>
Queue<T> transform(const Queue<T>& queue, F fonction){
    for(int i = 0; i < queue.size(); i++){
        T actualElement = queue.front();
        fonction (&actualElement);
        queue.popFront();
        queue.pushback(actualElement);
    }
}

template <class T>
class Queue<T>::Iterator{
    const Queue<T> *m_queue;
    int m_index;
    Iterator(const Queue<T> *queue, int index ):m_queue(queue),
                                                m_index(index)
    {}
    friend class Queue<T>;
public:
    const T& operator*() const{
        return m_queue -> m_data[m_index];
    }

    Iterator& operator++(){
        ++m_index;
        return *this;
    }

    Iterator& operator++(int){
        Iterator result = *this;
        ++(*this);
        return result;
   }

    bool operator==(const Iterator& i) const {
        return m_index == i.m_index;
    }

    bool operator!=(const Iterator& i) const {
        return !(*this == i);
    }
};

template <class T>
class Queue<T>::ConstIterator{
    const Queue<T> *m_queue;
    int m_index;
    ConstIterator(const Queue<T> *queue, int index ):m_queue(queue),
                                                m_index(index)
    {}
    friend class Queue<T>;
public:
    const T& operator*() const{
        return m_queue -> m_data[m_index];
    }

    Iterator& operator++(){
        ++m_index;
        return *this;
    }

    Iterator& operator++(int){
        Iterator result = *this;
        ++(*this);
        return result;
   }

    bool operator==(const ConstIterator& i) const {
        return m_index == i.m_index;
    }

    bool operator!=(const ConstIterator& i) const {
        return !(*this == i);
    }
};


#endif //EX3_QUEUE_H