
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

template<class T=int>
class Array {
	template <class V>
	friend ostream& operator<<(ostream&, const Array<V>&);
	public:
		//constructor
		Array();	
		//destructor
		~Array();
		
		//other
		void add(T);
		void operator+=(T);
		void operator-=(T);
		void remove(T);
		T operator[](int index);
		T operator[](int index) const;
		int size() const;
		bool isFull();
		void clear();
	
	private:
		int numElements;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(T t){
	if (numElements >= MAX_ARRAY)   return;
  	elements[numElements++] = t;
}

template <class T>
void Array<T>::operator+=(T t){
	Array<T>::add(t);
}

template <class T>
void Array<T>::remove(T t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
}

template<class T>
void Array<T>::operator-=(T t){
	Array<T>::remove(t);
}

template <class T>
int Array<T>::size() const{
	return numElements;
}

template <class T>
bool Array<T>::isFull(){
	return numElements >= MAX_ARRAY;
}

template<class T>
T Array<T>::operator[](int index){
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template<class T>
T Array<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template<class T>
void Array<T>::clear(){
	for(int i=0; i<= numElements; ++i){
		elements[i] = NULL;
	}
	numElements = 0;
}

template<class T> 
ostream& operator<<(ostream& ost, const Array<T>&){
	for(int i = 0; i < Array<T>::numElements; ++i){
		ost << Array<T>::elements[i] << endl;
	}
	return ost;
}

#endif
