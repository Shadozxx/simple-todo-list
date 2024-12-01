#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

// Вступайте в мой ТГК: t.me/WingProject
// Простой таск лист от Shado
// Возможности: Добавить задачу, Удалить все задачи, Просмотреть все задачи
// Имя файла содержится в переменной ниже (filen) в него записываются все задачи в формате {номер. текст}
// Чтобы изменить название файла измените переменную ниже (filen) 
// Также можно добавить директорию куда он сохранится, например C:\Tasklist.prion



void addtask(int taskid, string& description);
void showtasks();
void removeall();
string filen = "Tasklist.prion"; // ИМЯ ФАЙЛА. Можно просто изменить, либо дать полный путь к файлу (например C:\Tasklist.prion)

int main() {

    string desc; // Отвечает за описание задачи, эта переменная будет использована в case 1
    int tid; // Отвечает за номер задачи, эта переменная будет использована в case 1
    int choice; // Отвечает за выбор пользователя, эта переменная будет использована в этой функции
    system("cls"); // Чистим консоль при вызове main() <-- данная функция у нас выступает в роли меню
    system("chcp 1251 > nul"); // Меняем кодировку для корректного отображения киррилицы
    cout << "SIMPLE TODO LIST BY SHADO || V 1.0B" << endl;
    cout << "1 - Добавить новую задачу" << endl;
    cout << "2 - Вывести все задачи" << endl;
    cout << "3 - Удалить все задачи" << endl;
    cout << "Пожалуйста, сделайте выбор, введя нужную цифру в консоль > ";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls"); // Чистим, чистим
        cout << "Введите номер задачи: ";
        cin >> tid; // Получаем номер задачи и заносим в tid
        cout << endl; // Пропуск линии
        cout << "Введите описание задачи: ";
        cin.ignore(); // Нужнен чтобы ввод проигнорировал пустую линию
        getline(cin, desc); // Ввод описания задачи, функция позволяет получить строку с пробелами
        addtask(tid, desc); // Вызов функции addtask(), передавая номер и описание
        break;
    case 2:
        system("cls"); // Чистим
        showtasks(); // Отображаем все задачи
        break;
    case 3:
        system("cls"); // Мойдодыр
        removeall(); // Удаляем все задачи
    default:
        system("cls"); // Уборочка
        cout << "Введён неверный аргумент, нажмите любую клавишу для возврата" << endl; 
        system("pause");
        main();
        break;

    }
}

void addtask(int taskid, string& description) { // Добавить задачу
    fstream file(filen, ios::app | ios::out); // Открываем файл для чтения и в режиме добавления
    if (file.is_open()) { // Проверка: открыт ли файл?
        file << taskid << ". " << description << endl;
        cout << "Успешно записана задача " << taskid << endl;
        file.close(); // Закрываем файл, избегаем утечек
        system("pause");
        main();
    }
}

void showtasks() { // Показать все задачи
    string rev;
    fstream file(filen, ios::in);
    if (file.good()) // Проверка: работоспособен ли файл? (тут выступает для проверки существования файла, если его нету то список задач пуст)
    {
        if (file.is_open()) { // Проверка: открыт ли файл?
            while (getline(file, rev)) { // Вывод линий файла
                cout << rev << endl;
                cout << "====================================" << endl;
            }
            file.close(); // Закрываем файл, избегаем утечек
            system("pause");
            main();
        }
    }
    else { // То, о чём я писал выше, если файла не существует, то выводит строку данную ниже
        cout << "Файл поврежден или задач не обнаружено (просто создайте её, в меню под пунктом 1" << endl;
        system("pause");
        main();
    }
}
void removeall() { // Удалить все задачи
    if (remove(filen.c_str()) == 0) { // Проверка: успешно ли удален файл?
        cout << "Все задачи удалены!" << endl;
    }
    else {
        cout << "Ошибка при удалении, скорее всего список задач и так пуст" << endl;
    }
    system("pause");
    main();
}
