#include <iostream>
#include <string>
#include <stddef.h>
using namespace std;

struct Stack
{
	Stack* next;
	int value;
};

void add(Stack*& top, int value)
{
	Stack* newElement = new Stack;
	newElement->next = top;
	newElement->value = value;
	top = newElement;
}

void Delete(Stack*& top)
{
	if (top==NULL) return;
	Stack* temp = top->next;
	delete top;
	top = temp;
}

void delete_stack(Stack*& top)
{
	while (top != NULL) Delete(top);
}

void show_stack(Stack* top)
{
	Stack* temp = top;
	for (int i = 0; temp != NULL ; i++, temp = temp->next) cout << "[" << i << "]" << ": " << temp->value << endl;
}

void sort_address(Stack*& top)
{
	add(top, 0);
	for (Stack* temp = top; temp != NULL; temp = temp->next)
	{
		for (Stack* next_temp = temp->next; next_temp; next_temp = next_temp->next)
		{
			if (next_temp->next && temp->next->value > next_temp->next->value)
			{
				Stack* tempElement = next_temp->next;
				next_temp->next = tempElement->next;
				tempElement->next = temp->next;
				temp->next = tempElement;
				next_temp = temp->next;
			}
		}
	}
	Delete(top);
}

void sort_value(Stack* top)
{
	for (Stack* temp = top; temp; temp = temp->next)
	{
		for (Stack* next_temp = temp->next; next_temp; next_temp = next_temp->next)
		{
			if (temp->value > next_temp->value)
			{
				int tempValue = temp->value;
				temp->value = next_temp->value;
				next_temp->value = tempValue;
			}
		}
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	Stack* stack = NULL;

	int size,action, value;
	while (true) 
	{
		cout << "1-Cоздать" << endl << "2-Задание" << endl << "3-Добавить" << endl << "4-Удалить" << endl << "5-Сортировка адресов" << endl << "6-Сортировка значений" << endl<<"7-Завершение"<<endl;
		cin >> action;
		if (action == 7) break;

		switch (action)
		{
		case 1:
		{	
			delete_stack(stack);
			cout << "Введите размер: ";
			cin >> size;
			cout << "Введите значения от 0 и выше:" << endl;
			for (int i = 0; i < size; i++)
			{
				cin >> value;
				cout << "[" << i << "]: " << value << "\n";
				add(stack, value);
			}
			cout << "Итог: " << endl;
		}
			break;
		case 2:
		{
			if (stack == NULL) break;
			int count = 0;
			Stack* min = stack, * max = stack, * last = stack;
			for (Stack* temp = stack->next; temp; temp = temp->next)
			{
				if (temp->value < min->value) min = temp;
				if (temp->value > max->value) max = temp;
				if (min == temp || max == temp) last = temp;
			}
			if (min == max) cout << "Все элементы одинаковы";
			else {

				if (min == last)
				{
					Stack** temp =& max->next;
					while (*temp != min)
					{
						Delete(*temp);
						count++;
					}
				}
				if (max == last)
				{
					Stack** temp =& min->next;
					while(*temp != max)
					{
						Delete(*temp);
						count++;
					}
				}
				cout << "Количество элементов между минимальным и максимальным: " << count << endl;
			
			}
		}
			break;
		case 3:
			cin >> value;
			add(stack, value);
			cout << endl;
			break;
		case 4:
			Delete(stack);
			break;
		case 5:
			sort_address(stack);
			break;
		case 6:
			sort_value(stack);
			break;
		}
		show_stack(stack);
		cout << endl;
	}
}