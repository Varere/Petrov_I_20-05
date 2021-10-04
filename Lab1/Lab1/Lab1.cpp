#include <iostream>
#include <vector>

using namespace std;

struct Pipe
{
    int id;
    int length;
    int caliber;
    bool overhaul;
};

struct KS
{
    int id;
    string name;
    int sections; // number of sections
    int wsections; //working sections
    double efficiency;
};

int main()
{
    vector<Pipe> pipes;
    int action;
    setlocale(LC_ALL, "Russian");
    while (1) {
        cout << "Введите 1 чтобы добавить трубу" << endl;
        cout << "Введите 2 чтобы добавить кс" << endl;
        cout << "Введите 3 чтобы просмотреть список объектов" << endl;
        cout << "Введите 4 чтобы редактировать трубу" << endl;
        cout << "Введите 5 чтобы редактировать кс" << endl;
        cout << "Введите 6 чтобы сохранить данные" << endl;
        cout << "Введите 7 чтобы загрузить данные" << endl;
        cout << "Введите 0 чтобы завершить работу" << endl;

        cin >> action;

        if (action == 0) {
            break;
        } else if (action == 1) {
            int tempid;
            int templength;
            int tempcaliber;
            bool tempoverhaul; 
            cout << "Введите id трубы" << endl;
            cin >> tempid;
            cout << "Введите длину трубы" << endl;
            cin >> templength;
            cout << "Введите диаметр трубы" << endl;
            cin >> tempcaliber;
            cout << "Труба сейчас в ремонте? (1:да; 2:нет)" << endl;
            cin >> tempoverhaul;
            Pipe newpipe = { tempid, templength, tempcaliber, tempoverhaul };
            pipes.push_back(newpipe);
        }
    }
}

