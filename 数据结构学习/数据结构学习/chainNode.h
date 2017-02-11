#pragma once
//chain node

#ifndef CHAINNODE_H_
#define CHAINNODE_H_

/*����һ���ڵ����������*/
template<class T>
class chainNode
{
	//���ݳ�Ա
public:
	T element;
	chainNode<T>* next;
	//����
public:
	chainNode() {}
	chainNode(const T& element) : element{ element } {}
	chainNode(const T& element, chainNode<T>* next) :element{ element }, next{ next } {}
};

#endif // !CHAINNODE_H_
