#include <iostream>
#include <string>
using namespace std;

struct ListElement
{
	ListElement* next = NULL;
	ListElement* prev = NULL;
	int value;
};

struct List
{
	ListElement* begin = NULL;
	ListElement* end = NULL;
};

void AddToBegin(List* list, int value)
{
	ListElement* new_element = new ListElement;
	new_element->next = list->begin;
	new_element->value = value;
	if (list->begin != NULL) list->begin->prev = new_element;
	if (list->end==NULL) list->end = new_element;
	list->begin = new_element;
}

void AddToEnd(List* list, int value)
{
	ListElement* new_element = new ListElement;
	new_element->prev = list->end;
	new_element->value = value;
	if (list->end!=NULL) list->end->next = new_element;
	if (list->begin==NULL) list->begin = new_element;
	list->end = new_element;
}

void Delete(ListElement* element, List* list)
{
	if (element == list->begin && element == list->end)
	{
		list->begin = list->end = NULL;
	}
	else if (element == list->begin)
	{
		list->begin = element->next;
		list->begin->prev = NULL;
	}
	else if (element == list->end)
	{
		list->end = element->prev;
		list->end->next = NULL;
	}
	else
	{
		element->next->prev = element->prev;
		element->prev->next = element->next;
	}
	delete element;
}

void DeleteList(List* list)
{
	while (list->begin) Delete(list->begin, list);
}

void from_begin(List* list)
{
	ListElement* temp = list->begin;
	for (int i = 0; temp!=NULL; i++, temp = temp->next) cout << "[" << i << "]" << ": " << temp->value << "\n";
}

void from_end(List* list)
{
	ListElement* temp = list->end;
	for (int i = 0; temp; i++, temp = temp->prev) cout << "[" << i << "]" << ": " << temp->value << "\n";
}


int main()
{
	system("chcp 1251");
	system("cls");
	List* list = new List;
	while (true)
	{
		int size, value, action;
		cout << "1-Создать" << endl << "2-Задание" << endl << "3-Добавить в начало" << endl << "4-Добавить в конец" << endl << "5-Просмотр с начала" << endl << "6-Просмотр с конца" << endl << "7-Завершение"<<endl;
		cin >> action;
		if (action == 7) break;
		switch (action)
		{
		case 1:
		{
			DeleteList(list);
			cout << "Введите размер списка: ";
			cin >> size;
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				cin >> value;
				AddToEnd(list, value);
			}
			cout << endl << "Итог:" << endl;
			from_begin(list);
			break;
		}
		case 2:
		{
			if (list->begin == NULL) break;
			int count = 0;
			ListElement* min = list->begin, * max = list->begin, * last = list->begin;
			for (ListElement* temp = list->begin->next; temp != NULL; temp = temp->next)
			{
				if (temp->value < min->value) min = temp;
				if (temp->value > max->value) max = temp;
				if (min == temp || max == temp) last = temp;
			}
			if (min == max) cout << "Все элементы одинаковы";

			else
			{	
				AddToEnd(list, 0);
				ListElement* temp;
					if (min == last)
					{
						temp = max->next->next;
						while (temp->prev != min )
						{
							Delete(temp->prev, list);
							count++;
							temp = temp->next;
						}
					}
					if (max == last)
					{
						temp = min->next->next;
						while (temp->prev != max)
						{
							Delete(temp->prev, list);
							count++;
							temp = temp->next;
						}
					}
			}
				Delete(list->end, list);
				cout << "Количество элементов между минимальным и максимальным: " << count << endl;
				from_begin(list);

		}
			break;
		case 3:
			cout << "Значение элемента: ";
			cin >> value;
			AddToBegin(list, value);

			break;
		case 4:
			cout << "Значение элемента: ";
			cin >> value;
			AddToEnd(list, value);
			break;
		case 5:
			from_begin(list);
			break;
		case 6:
			from_end(list);
			break;
		}
		cout << endl;
	}
}
