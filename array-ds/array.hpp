#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array {

    protected:
        int length;
        int size;
        void *start;
        
    public:
        int getLength();
        int getSize();
        int getElement(int idx);
        int setElement(int idx, int val);

        void printArray();

};

#endif