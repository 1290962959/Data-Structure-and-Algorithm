#pragma once
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include"linearList.h"
#include<iostream>
#include<ostream>
#include<algorithm>   //find()
#include<iterator>
using namespace std;

template<class T>
inline T Min(const T a, const T b)
{
	return a < b ? a : b;
}

/*�1�7�1�7arrayList*/
//�1�7�1�7�1�7�1�7�1�7�1�7linearList�1�7�1�7�1�7�1�7�1�7�1�7
template<class T>
class arrayList :public linearList<T>
{
public:
	//arrayList�1�7�1�7�1�7�0�1�1�7�1�7�4�4�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; }

	//ADT�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
	bool empty() const { return listSize == 0; }
	bool full() const { return listSize == arrayLength; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
	int capacity() const { return arrayLength; }

private:
	void checkIndex(int theIndex) const;	//�1�7�1�7�1�7�1�7�1�7�1�7theIndex�1�7�1�7���1�7�1�7�1�7�1�7�1�7�0�7�1�7�1�7�4�4
	T* element;				//�1�7���1�7�1�7�1�7�0�3�1�7�0�6�1�7�1�3�1�7�0�5�0�4�1�7�1�7�1�7�1�7
	int arrayLength;		//�0�5�0�4�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
	int listSize;				//�1�7�1�7�1�7�0�3�1�7�1�7�1�7�0�6�1�7�1�3�0�0�1�7�1�7�1�7
};

//�1�7�0�3�1�7�0�5�1�7�1�7�0�5�0�4�1�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�1�7
template<class Tc>
void ChangeArrayLength(Tc*& str, int OldLength, int NewLength);

//�1�7�0�3�1�7�0�5�1�7�1�7�0�5�0�4�1�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�1�7
template<class Tc>
void ChangeArrayLength(Tc*& str, int OldLength, int NewLength)   //�1�7�0�4�1�7�1�7�1�7�1�7�1�7�0�8�1�7�0�3�1�7�0�8�1�7�0�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�1�7�1�7�1�7�1�7�0�8�1�7�1�7�0�8�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
{
	if (NewLength < 0)
		throw ("new length must be >= 0");
	int strSize = Min(OldLength, NewLength);
	Tc* temp = new Tc[strSize];

	copy(str, str + strSize, temp);
	delete[] str;
	str = temp;
}

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{//�1�7�1�7�1�7�4�4�1�7�1�7
	if (initialCapacity < 1)
	{
		//ostringstream s;
		cout << "Initial capacity = " << initialCapacity << "Must be >0";
		exit(-1);
		//throw s;
	}
	arrayLength = initialCapacity;
	element = new T[initialCapacity];
	listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + theList.listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{//�0�2�1�7�1�7�1�7�1�7�1�7�1�7theIndex�1�7�1�70�1�7�1�7listSzie-1�0�8�1�7�1�7
	if (theIndex < 0 || theIndex > listSize)
	{
		//ostringstream s;
		cout << "index = " << theIndex << " size = " << listSize;
		exit(-1);
		//throw s;
	}
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{//�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�2theIndex�1�7�1�7�0�6�1�7�1�7
 //�1�7�1�7�0�6�1�7�1�0�1�7�1�7�1�7�1�7�1�3�1�7�1�7�1�7�1�7�0�7�1�7�1�7�4�4
	checkIndex(theIndex);
	return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{//�1�7�1�7�1�7�1�7�0�6�1�7�1�7theElement�1�7�0�7�1�7�0�5�1�7�Ä1�7�1�7�0�5�1�7�1�7�1�7�1�7�1�7
 //�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�0�1�7�0�6�1�7�1�5�1�7�1�7�5�3�1�7-1

 //�1�7�1�7�1�7�1�7�0�6�1�7�1�7theElement
 //find()�1�7�1�7�1�7�0�7�0�6�1�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�8�1�7�1�7�0�8�1�7�1�7�0�6�1�7�1�3�0�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�2�1�7�1�1�1�7�1�7�1�7end�1�7�1�7�1�7�1�7�1�7�1�7
	int theIndex = (int)(find(element, element + listSize, theElement) - element);
	//�0�2�1�7�1�7�0�6�1�7�1�7theElement�1�7�0�9�1�7�1�7�0�9�1�7
	if (theIndex == listSize)
		//�1�7�1�7�1�7�1�7�1�7�1�7�0�4�1�7�0�9�1�7
		return -1;
	else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{//�0�1�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�6�1�7�1�7
 //�1�7�1�7�0�4�1�7�ڄ1�7�0�6�1�7�1�5�1�7�1�7�1�7�1�7�0�7�1�7�1�7�4�4
	checkIndex(theIndex);
	//�1�7�1�7�1�7�1�7�1�7�1�7��
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();  //�0�8�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�6�1�7�1�5�1�7�0�6�1�7�1�6�1�7�1�7�1�7�1�7�1�7�0�5
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{//�1�7�1�7�1�7�1�7�1�7�1�7theIndex�1�7�1�7�1�7�1�7�1�7�1�7�0�6�1�7�1�7theElement
 //�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�3�1�7�1�7�1�7�1�7�0�7�1�7�1�7�4�4
	checkIndex(theIndex);
	//�1�7�1�7���1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�؄1�7�1�7�1�7�1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�7
	if (full())
	{
		ChangeArrayLength(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	//copy_backward(b,e,d):�1�7�1�7�1�7�1�7b,e�1�7�1�7�1�7�1�7���1�7�1�1�1�7�0�6�1�7�1�5�1�7�1�7�1�7�1�7�0�1�1�7�1�7�1�7d�0�2�1�7�0�1�1�7�1�7�1�7�˄1�7�1�7
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{//�1�7�1�7�1�7�1�7�1�7�0�3�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
	copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}
#endif // !ARRAYLIST_H

