#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <vector>
#include <list>
#include <iterator>
#include "component.h"
#include "BaseFactory.h"
#include "DoublePrint.h"
#include "basePrint.h"
#include "HexPrint.h"
#include "BinaryPrint.h"



class Sort;

class Container {
    protected: 
        Sort* sort_function;
        BaseFactory* v;

    public: 
        /* Cosntructors */
        Container() : sort_function(NULL) { };
        Container(Sort* function); 
        Container(BaseFactory* value);
       

        /* Non Virtual Functions */
        // Set the type of sorting algorithm
        void set_sort_function(Sort* sort_function); 
        void set_TypeofPrint(BaseFactory* factory);

        /* Pure Virtual Functions */
        // insert the top pointer of the tree into the container
        virtual void add_element(Base* element) = 0;
        // iterate through the trees and output values
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm. 
        // Check if sort_function is not null, throw exception if is null
        virtual void sort() = 0;

        /* Essentially the only functions needed to sort */
        // switch tree locations
        virtual void swap(int i,int j) = 0;
        // get top pointer of tree at index i
        virtual Base* at(int i) = 0;
        // return container size;
        virtual int size() = 0;
};


#endif // __CONTAINER_H__