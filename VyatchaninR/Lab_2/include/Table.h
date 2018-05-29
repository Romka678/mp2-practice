#pragma once
#include"Polynom.h"

using namespace std;

class Record
{
public:
	Polynom data;
	string key;
	Record() { key = "", data = Polynom(); }
	Record(const string str, const Polynom& p) { key = str; data = p; }
	Record& operator = (const Record& r) { data = r.data; key = r.key.substr(0, r.key.length()); return *this; }
};

class Table
{
protected:
	Record*r;
	int max;
	int size;
	int flag;
public:
	Table(int s = 2);
	virtual ~Table() { delete[] r; } // ����������
	virtual void Insert(const string str, const Polynom& p) = 0; // �������
	virtual Polynom Search(const string str) const = 0; // �����
	virtual void Delete(const string str) = 0; // �������� 

	void First(); // ������ ������ �������� �������
	bool Full(); // �������� �� ������� ������
	void Next(); // index++
	Record& GetCurr(); // ������� �������
};