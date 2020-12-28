#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link1,
		* link2;
	inform inf;
};

int Creata(Spusok*& first, Spusok*& last, int index, int N, int i);
int COUT(Spusok*& T, inform inf, int N, int index);
void Process(Spusok*& T, inform v1, inform v2, Spusok*& last);

int main(void)
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* first = NULL;
	Spusok* last = NULL;

	int index = rand() % 6, N = 4, i = 0;
	Creata(first, last, index, N, i);

	Spusok* T = first;
	cout << "Вивід інформації про кожен сформований елемент: " << endl << endl;
	COUT(T, 0, N, index);
	cout << endl << endl;

	int v1, v2;
	/*
	Після кожного елементу списку із значенням інформаційного поля V1
	вставити новий елемент із значенням інформаційного поля V2.
	*/
	cout << "Введіть V1: ";	cin >> v1;
	cout << endl;
	cout << "Введіть V2: ";	cin >> v2;
	cout << endl << endl;

	T = first;
	Process(T, v1, v2, last);
	T = first;
	COUT(T, 0, N, index);

	return 0;
}

int Creata(Spusok*& first, Spusok*& last, int index, int N, int i)
{
	Spusok* tmp = new Spusok;

	tmp->inf = index;
	tmp->link1 = NULL;
	tmp->link2 = NULL;
	if (first == NULL)
		first = tmp;
	else
	{
		last->link1 = tmp;
		tmp->link2 = last;
	}
	last = tmp;

	if (i < N - 1)
		return Creata(first, last, rand() % 6, N, i + 1);
	else
		return 0;
}

int COUT(Spusok*& T, inform inf, int N, int index)
{
	if (T != NULL)
	{
		inf = T->inf;
		cout << inf << "   ";
	}

	if (T != NULL)
		return COUT(T->link1, inf, N, index + 1);
	else
		return 0;
}

void Process(Spusok*& T, inform v1, inform v2, Spusok*& last)
{
	if (T != NULL)
	{
		if (T->inf == v1)
		{
			Spusok* tmp = new Spusok;                       // 1(створення нового емента)
			tmp->inf = v2;                                  // 2(присвоєння новоствореному елементу(інформаційному полю) значення)
			tmp->link1 = T->link1;                          // 3(перше поле зв'язку(нового елемента) вкзазуватиме на другий елемент)
			if (T->link1 != NULL)
				T->link1->link2 = tmp;                      // або 4(якщо "T->link1 != NULL" то другий елемент вказуватиме на новостворений) 
			else
				last = tmp;                                 // або 4(інакше вказівник last(функція --- 'вказує на кінцевий елемент') вказуватиме на новостворений елемент)
			T->link1 = tmp;                                 // 5(перше поле зв'язку(першого елемента) вкзазуватиме на новостворений елемент)
			tmp->link2 = T;                                 // 6(друге поле зв'язку(нового елемента)  вкзазуватиме на перший елемент  )
			return Process(T->link1->link1, v1, v2, last);  // або 7(якщо "T->inf == v1" то вказівник 'T' вказуватиме на дві позиції вперед(другий елемент), оскільки був добавлений елемент)
		}
		else
			return Process(T->link1, v1, v2, last);         // або 7(інакше вказівник 'T' вказуватиме на одну позицію вперед(другий елемент), оскільки не було добавленонового елемента)
	}
}
