#include <iostream>
#include <vector>

using namespace std;

struct Pipe {
    int id;
    int length;
    int caliber;
    bool overhaul;
};

struct KS {
    int id;
    string name;
    int sections; // number of sections
    int wsections; //working sections
    double efficiency;
};

void printks(KS ks) {
    cout << "Id: " << ks.id << " ";
    cout << "Название: " << ks.name << " ";
    cout << "Количество цехов: " << ks.sections << " ";
    cout << "Цехов работает: " << ks.wsections << " ";
    cout << "Эффективность: " << ks.efficiency << " ";
}

void printpipe(Pipe pipe) {
    cout << "Id: " << pipe.id << " ";
    cout << "Длина: " << pipe.length << " ";
    cout << "Диаметр: " << pipe.caliber << " ";
    if (pipe.overhaul == true) {
        cout << "Состояние: В ремонте";
    } else {
        cout << "Состояние: Исправна";
    }
}


int main() {
    vector<Pipe> pipes;
    vector<KS> kses; //
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
        } else if (action == 2) {
            int tempid;
            string tempname;
            int tempsections; 
            int tempwsections; 
            double tempefficiency;
            cout << "Введите id КС" << endl;
            cin >> tempid;
            cout << "Введите название КС" << endl;
            cin >> tempname;
            cout << "Введите количество цехов в КС" << endl;
            cin >> tempsections;
            cout << "Введите количнство работающих цехов в КС" << endl;
            cin >> tempwsections;
            cout << "Введите эффективность КС" << endl;
            cin >> tempefficiency;
            KS newks = { tempid, tempname, tempsections, tempwsections, tempefficiency };
            kses.push_back(newks);
        } else if (action == 3) {
            cout << "Трубы: " << endl;
            for (int i = 0; i < pipes.size(); ++i) {
                printpipe(pipes[i]);
            }
            cout << endl;
            cout << "КС: " << endl;
            for (int i = 0; i < kses.size(); ++i) {
                printks(kses[i]);
            }

        }
    }
}

