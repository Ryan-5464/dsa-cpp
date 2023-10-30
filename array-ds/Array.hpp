#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> 
class Array {
    
    private:
        const _MAX_SIZE_BYTES = 1000000;
        int _length;
        int _size;
        T *_head;

    public:
        Array(int len);
        ~Array();
        void print();
        int length();
        int size();
        T getElement(int idx);
        T setElement(int idx, T val);
};



#endif

