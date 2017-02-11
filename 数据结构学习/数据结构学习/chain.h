#pragma once
#ifndef CHAIN_H_
#define CHAIN_H_
#include"linearList.h"
#include"chainNode.h"

template<class T>
class chain :public linearList<T> 
{
public:
	//����Ϳ������캯������������
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	//ADT����
	bool empty() const { return listSize == 0; }
	bool full() const { return 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
	
private:
	void checkIndex(int theIndex) const;//�����Ч���������׳��쳣
	chainNode<T>* firstNode;//ָ������ĵ�һ���ڵ��ָ��
	int listSize;//���Ա��Ԫ�ظ���
};

template<class T>
chain<T>::chain(int initialCapacity)
{//���캯��
	if (initialCapacity < 1)
	{
		cout << "InitialCapacity = " << initialCapacity << "Must be >0" << endl;
		exit(-1);
	}
	firstNode = nullptr;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{//�������Ϊ������
		firstNode = nullptr;
		return;
	}
	//�������ǿ�
	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	while (sourceNode != nullptr)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->element = nullptr;
}

template<class T>
chain<T>::~chain()
{//���������������ɾ����������нڵ�
	while (firstNode != nullptr)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{//ȷ������theIndex��0��listSzie-1֮��
	if (theIndex < 0 || (theIndex >= listSize))
	{
		//ostringstream s;
		cout << "index = " << theIndex << " size = " << listSize;
		exit(-1);
		//throw s;
	}
}

template<class T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	//��������Ҫ�Ľڵ�
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != nullptr&&currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	//ȷ���Ƿ��ҵ�Ԫ��
	if (currentNode == nullptr)
		return -1;
	else
		return index;
}

template<class T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>* deleteNode = firstNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* tmp = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
		{
			tmp = tmp->next;
		}
		deleteNode = tmp->next;
		tmp->next = tmp->next->next;
	}
	listSize--;
	delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T&theElement)
{
	if (theIndex < 0 || (theIndex > listSize))
	{
		//ostringstream s;
		cout << "index = " << theIndex << " size = " << listSize;
		exit(-1);
		//throw s;
	}

	chainNode<T>* insertNode = new chainNode<T>(theElement);
	if (theIndex == 0)
	{
		insertNode->next = firstNode;
		firstNode = insertNode;
	}
	else
	{
		chainNode<T>* temp = firstNode;
		for (int i = 0; i < theIndex-1;i++)
		{
			temp = temp->next;
		}
		insertNode->next = temp->next;
		temp->next = insertNode;
	}
	listSize++;
}

template<class T>
void chain<T>::output(ostream &out) const
{
	for (chainNode<T>* currentNode = firstNode; currentNode != nullptr; currentNode = currentNode->next)
		cout << currentNode->element << " ";
}

////����<<
//template<class T>
//ostream& operator<<(ostream& out, const chain<T>& x)
//{
//	x.output(out);
//	return out;
//}
#endif // !CHAIN_H_
