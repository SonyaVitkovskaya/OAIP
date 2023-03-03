#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tree
{
	Tree* left = NULL;
	Tree* right = NULL;
	string info;
	int key;
};

Tree*& samaya_pravaya(Tree*& root, Tree*** prev)
{
	Tree** temp = &root;
	while ((*temp)->right) 
	{
		*prev = temp;
		temp = &(*temp)->right;
	}
	return *temp;
}
void add_node(Tree*& root, int key, string info)
{
	Tree** temp = &root;
	while (*temp)
	{	
		if (key < (*temp)->key)  temp = &(*temp)->left;
		else temp = &(*temp)->right;
	}
	Tree* newNode = new Tree;
	newNode->key = key;
	newNode->info = info; 
	*temp = newNode;
}
void delete_uzel(Tree*& node)
{
	if (node==NULL) return;
	Tree* tempPtr = NULL;
	if ((node->left && !node->right) || (!node->left && node->right))
	{
		if (node->left != NULL) tempPtr = node->left;
		else tempPtr= node->right;
	}
	else if (node->left && node->right)
	{
		Tree** prevPtr = NULL;
		tempPtr = samaya_pravaya(node->left, &prevPtr);
		if (!prevPtr) tempPtr->right = node->right;
		else
		{
			if (tempPtr->left)	  (*prevPtr)->right = tempPtr->left;
			else (*prevPtr)->right = NULL;
			tempPtr->right = node->right;
			tempPtr->left = node->left;
		}
	}
	delete node;
	node = tempPtr;
}
void show(Tree* node, int level=0)
{
	if (node==NULL) return;
	show(node->right, level + 1);
	for (int i = 0; i < level; i++) cout << "   ";
	cout << node->key << endl;
	show(node->left, level + 1);
}

int zadanie(Tree* node,int count)
{
	if (node == NULL) return 0;
	if (node->right && !node->left) 
	{
		count++;
		count=zadanie(node->right, count);
	}
	if (node->left && !node->right)
	{
		count++;
		count=zadanie(node->left, count);
	}
	if (node->right && node->left)
	{
		count=zadanie(node->right, count);
		count=zadanie(node->left, count);
	}
	return count;
}

void print(Tree* node, bool post)
{
	if (node==NULL) return;
	if (!post) cout << node->info << " ";
	print(node->left, post);
	print(node->right, post);
	if (post) cout << node->info << " ";
}

void create_massiv(Tree* node, vector<Tree*>& nodes)
{
	if (node == NULL) return;
	nodes.push_back(node);
	create_massiv(node->left, nodes);
	create_massiv(node->right, nodes);
}

void sort(vector<Tree*>& nodes)
{
	for (int i = 0; i < nodes.size() - 1; i++)
	{
		for (int j = i + 1; j < nodes.size(); j++)
		{
			if (nodes[i]->key > nodes[j]->key)
			{
				Tree* temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
			}
		}
	}
}

Tree* Balance(Tree*& root, vector<Tree*>& nodes, int k=-1, int n=0)
{
	if (k == -1) k = nodes.size(), root = nodes[k / 2];
	if (n == k) return NULL;
	int m = (n + k) / 2;
	nodes[m]->left = Balance(root, nodes, m, n);
	nodes[m]->right = Balance(root, nodes, k, m + 1);
	return nodes[m];
}

Tree*& node(Tree*& root, int key)
{
	Tree** temp = &root;
	while (*temp)
	{
		if ((*temp)->key > key) temp = &(*temp)->left;
		else
		{
			if ((*temp)->key < key) temp = &(*temp)->right;
			else return *temp;
		}
	}
	return *temp;
}
 

int main()
{
	system("chcp 1251");
	system("cls");
	Tree* root = NULL;
	int key=-1, action, size;
	string name;
	Tree* exist;
	cout << "Размер: " << endl;
	cin >> size;  cout << endl;
	for (int i = 0; i < size; i++)
	{
		while (key == -1 || node(root, key))
		{
			cout << "Введите ключ: " << endl;
			cin >> key;
		}
		cout << "Введите имя: " << endl;
		cin >> name;
		add_node(root, key, name);
	}
	while (1)
	{
		vector<Tree*> nodes;
		cout << "1-Задание" << endl << "2-Добавить" << endl << "3-Удалить" << endl << "4-Показать" << endl << "5-Поиск" << endl << "6-Сбалансировать" << endl << "7-Распечатать" << endl << "8-Завершить" << endl;
		cin >> action;
		if (action == 8)	break;
		switch (action)
		{
		case 1:
		{
			int count = 0;
			count = zadanie(root, count);
			cout << "Число узлов: " << count << endl;
			break;
		}
		case 2:
			cout << "Введите ключ: " << endl;
			cin >> key;
			while (node(root, key))
			{
				cout << "Введите ключ: " << endl;
				cin >> key;
			}
			cout << "Введите имя: ";
			cin>>name;
			add_node(root, key, name);
			break;
		case 3:
			cout << "Введите ключ: " << endl;
			cin >> key;
			delete_uzel(node(root, key));
			break;
		case 4:
			show(root);
			break;
		case 5:
			cout << "Введите ключ: " << endl;
			cin >> key;
			exist = node(root, key);
			if (exist) cout << "Имя: " << exist->info << endl;
			else cout << "Элемент не найден"<<endl;
			break;
		case 6:
			create_massiv(root, nodes);
			sort(nodes);
			Balance(root, nodes);
			break;
		case 7:
			cout << "1-Прямой обход" << endl << "2-Обратный обход" << endl << "3-В порядке возрастания ключа" << endl;
			cin >> action;
			switch (action)
			{
			case 1:
				print(root, false);
				break;
			case 2:
				print(root, true);
				break;
			case 3:
				create_massiv(root, nodes);
				sort(nodes);
				for (int i = 0; i < nodes.size(); i++) cout << nodes[i]->info << " ";
				break;
			}
			cout << endl;
			break;
		}
	}
}