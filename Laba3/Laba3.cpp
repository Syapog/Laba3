#include <iostream>
#include <ctime>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");

    srand(time(NULL));

    const int SIZE = 20;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout << endl;

    int povtor[SIZE]; // чтобы хранить числа которые проверил
    int ind[SIZE]; // место чила (номер)
    bool netch = true;

    for (int i = 0; i < SIZE; i++) // всем povtor даем -1, если -1 то пусто
    {
        povtor[i] = -1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) // обнуляем индексы
        {
            ind[j] = -1;
        }

        bool est = false; // есть ли это число
        for (int j = 0; j < SIZE; j++)
        {
            if (arr[i] == povtor[j])
                est = true; // есть то не обрабатываем
        }

        if (!est)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (arr[i] == arr[j])// повторяется ли это число еще раз
                {
                    for (int l = 0; l < SIZE; l++) //заполняем первую свободную ячейки
                    {
                        if (ind[l] == -1)
                        {
                            ind[l] = j;
                            l = SIZE; // досрочно завершаю
                        }
                    }
                }
            }

            int n = 0; // кол-во индексов для i
            for (int j = 0; j < SIZE; j++)
            {
                if (ind[j] != -1)// если не пусто то ++
                    n++;
            }

            if (n > 2) // если нашли нужное то выводим
            {
                cout << "Число " << arr[i] << " под номерами ";
                for (int j = 0; j < SIZE; j++)
                {
                    if (ind[j] != -1) // опять если не пустая то выводим индекс
                        cout << ind[j] << ", ";
                }
                cout << endl;
                netch = false;
            }

            for (int j = 0; j < SIZE; j++) //записываю число в повтор
            {
                if (povtor[j] == -1)
                {
                    povtor[j] = arr[i]; // равняем к обрабат. числу
                    j = SIZE;
                }
            }

        }

    }
    if (netch)
    {
        cout << "Таких чисел нет";
    }
}