#pragma once
#ifndef STACK_H_
#define STACK_H_

#include"chainNode.h"
#include"myExceptions.h"
#include<iostream>

using namespace std;

template<class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual bool empty() const = 0;
	virtual bool full() const = 0;
	virtual int size() const = 0;
	//����ջ��Ԫ�ص�����
	virtual const T& top() const = 0;
	//ɾ��ջ��Ԫ��
	virtual void pop() = 0;
	//��ջ����
	virtual void push(const T&) = 0;
};

/********************Array stack************************/
//����������Ϊջ�ף���һ��Ϊջ��
template<class T>
class ArrayStack: public Stack<T>
{
public:
	ArrayStack(int initial_capacity = 10)
	{
		if (initial_capacity < 1)
			throw ThrowException("initial capacity should > 1");
		element = new T[initial_capacity];
		stack_top = -1;
		stack_size_ = 0;
	}
	~ArrayStack()
	{
		delete[] element;
	}
	bool empty() const { return stack_top_ == -1; }
	bool full() const { return stack_size_ == stack_top_ + 1; }
	int size() const { return stack_size_; }
	T& top() const
	{//����ջ��Ԫ��
		if (empty())
			throw ThrowException("top error : stack is empty");
		return element[stack_top_];
	}
	void pop()
	{//����ջ��Ԫ��
		if (empty())
			throw ThrowException("top error : stack is empty");
		element[stack_top_--].~T();  
	}
	void push(const T& the_element)
	{
		if (full())
			throw ThrowException("push error: stack is full");
		element[++stack_top_] = the_element;
	}
private:
	T *element;
	int stack_top_;
	int stack_size_;
};


/*********************************************************/

/***********************list stack***************************/
//����������Ϊջ����ʱ�临�Ӷ�Ϊo(1)
template<class T>
class ListStack: public Stack<T>
{
public:
	ListStack(){ stack_top_ = nullptr; stack_size_ = 0; }
	~ListStack()
	{
		chainNode<T>* current_node = stack_top_->next;
		while (stack_top_ != nullptr)
		{
			delete stack_top_;
			stack_top_ = current_node;
			current_node = current_node->next;
		}
	}
	bool empty() const { return stack_size_ == 0; }
	int size() const { return stack_size_; }
	T& top() const
	{
		if (stack_size_ == 0)
			throw ThrowException("stack is empty");
		return stack_top_->element;
	}
	void pop()
	{
		chainNode<T>* old_stack_top_next = stack_top_->next;
		delete stack_top_;
		stack_top_ = old_stack_top_next;
		stack_size_--;
	}
	void push(const T& the_element)
	{
		stack_top_ = new chainNode<T>(the_element, stack_top_);
		stack_size_++;
	}
private:
	chainNode<T>* stack_top_;
	int stack_size_;
};

/*********************************************************/

#endif // !STACK_H_
