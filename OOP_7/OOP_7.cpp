#include <iostream>
#include <windows.h>
using namespace std;

class ArrayList // Vector
{
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data = nullptr; // указатель на динамический массив целых чисел

public:
	ArrayList() : ArrayList(10)
	{
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}

	ArrayList(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

private:
	// приватный метод (он нужен только для правильной работы динамического массива, клиент об этом методе не должен знать)
	void EnsureCapacity() {
		if (size < capacity) return; // если резерв памяти достаточный, то просто выходим отсюда
		else {
			cout << "capacity * 2 !!! " << capacity << "\n";
			Sleep(1000);
			int* temp = new int[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
	}

public:
	~ArrayList()
	{
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void PushBack(int value)
	{
		EnsureCapacity(); // проверка, хватит ли места для нового элемента
		data[size] = value;
		size++;
	}

	void PushFront(int value)
	{
		EnsureCapacity();
		for (int i = size; i > 0; i--) // i = 1
		{
			data[i] = data[i - 1]; // data[1] = data[0]
		}
		data[0] = value;
		size++;
	}
	
	////////////////////////////////МОИ МЕТОДЫ//////////////////////////////////
	void Insert(int value, int index)
	{
		PushBack(value);

		for (int i = size - 1; i > index; --i) {
			swap(data[i], data[i - 1]);
		}
	}

	void RemoveAt(int index)
	{
		for (int i = 0; i < size; i++)
		{
			if (i == index)
			{
				for (int i = index; i < size; i++) {
					swap(data[i], data[i + 1]);
				}
				size--;
			}
		}
	}

	void Remove(int value) 
	{
		for (int i = 0; i < size; i++)
		{
			if (data [i] == value)
			{
				swap(data[i], data[i + 1]);
				size--;
				}
				
			}
	}
	
	void PopFront()
	{
		int index = 0;
		for (int i = index; i < size; i++) {
				swap(data[i], data[i + 1]);
			}
			size--;
	}
	
	void PopBack()
	{
		int index = size-1;
		for (int i = index; i < size; i++) {
			size--;
		}
		
	}
	///////////////////////////////////////////////////////////////////////
	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}

	int GetSize() const {
		return size;
	}

	int GetCapacity() const {
		return capacity;
	}
};

int main()
{
	ArrayList ar;
	/*
	for (int i = 0; i < 10000000; i++)
	{
		ar.PushBack(rand() % 100);
		//cout << "SIZE: " << ar.GetSize() << "\n";
		//cout << "RESERV: " << ar.GetCapacity() << "\n\n";
		// Sleep(100);
	}
	*/
	ar.PushBack(12);
	ar.PushBack(1);
	ar.PushBack(22);
	ar.PushBack(32);
	ar.PushBack(7);
	ar.PushBack(72);
	cout << "SIZE: " << ar.GetSize() << "\n";
	ar.Print();
	ar.Insert(5, 2);
	ar.Print();
	ar.RemoveAt(2);
	ar.Print();
	ar.Remove(7);
	ar.Print();
	ar.PopFront();
	ar.Print();
	ar.PopBack();
	ar.Print();

}