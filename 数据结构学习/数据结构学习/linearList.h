#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<iostream>
using namespace std;

/*���Ա�ĳ�����*/
template<class T>
class linearList
{
public:
	virtual ~linearList() {};
	virtual bool empty() const = 0;
	//����ture�����ҽ������Ա�λ��
	virtual bool full() const=0;
	//����ture�����ҽ������Ա�����
	virtual int size() const = 0;
	//�������Ա��Ԫ�ظ���
	virtual T& get(int theIndex) const = 0;
	//��������ΪtheIndex��Ԫ��
	virtual int indexOf(const T& theElement) const = 0;
	//����Ԫ��theElement��һ�γ���ʱ������
	virtual void erase(int theIndex) = 0;
	//ɾ������theIndex��Ԫ��
	virtual void insert(int theIndex, const T& theElement) = 0;
	//��theElement���뵽���Ա�������ΪtheIndex��λ����
	virtual void output(ostream& out) const = 0;
	//�����Ա���������out
};
#endif // !LINEARLIST_H
