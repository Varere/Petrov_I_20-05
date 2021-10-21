#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits>

using namespace std;

struct Pipe {
    int id;
    double length;
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

void printks(const KS& ks) {
    cout << "Id: " << ks.id << " ";
    cout << "Название: " << ks.name << " ";
    cout << "Количество цехов: " << ks.sections << " ";
    cout << "Цехов работает: " << ks.wsections << " ";
    cout << "Эффективность: " << ks.efficiency << " ";
}

void save_to_file(const vector<Pipe>& pipes, const vector<KS>& kses) 
{
    ofstream out("output");
    if (out.is_open()) {
        out << pipes.size() << endl;
        for (auto &p: pipes) 
        {
            out << p.id << endl;
            out << p.length << endl;
            out << p.caliber << endl;
            out << p.overhaul << endl;
            
        }
        out << kses.size() << endl;
        for (auto &k: kses) {
            out << k.id << endl;
            out << k.name << endl;
            out << k.sections << endl;
            out << k.wsections << endl;
            out << k.efficiency << endl;
        }
        out.close();
    }
}

int intcorcheck(int min, int max) {
    int n;
    while (1) {
        cin >> n;
        cout << "Введите значение от " << min << " до " << max << endl;
        if (cin.peek() != '\n' || cin.fail() || n < min || n > max) {
            cin.clear();
            cin.ignore(10000000, '\n');
            cout << "Некорректный ввод. Попробуйте снова" << endl;
        }
        else {
            return n;
        }
    }
}

double doublecorcheck(double min=0.0,double max=DBL_MAX) {
    double n;
    while (1) {
        cin >> n;
        cout << "Введите значение от " << min << " до " << max << endl;
        if (cin.peek() != '\n' || cin.fail() || n < min || n > max) {
            cin.clear();
            cin.ignore(10000000, '\n');
            cout << "Некорректный ввод. Попробуйте снова" << endl;
        }
        else {
            return n;
        }
    }
}

void printpipe(const Pipe& pipe) {
    cout << "Id: " << pipe.id << " ";
    cout << "Длина: " << pipe.length << " ";
    cout << "Диаметр: " << pipe.caliber << " ";
    if (pipe.overhaul == true) {
        cout << "Состояние: В ремонте";
    } else {
        cout << "Состояние: Исправна";
    }
}

string stringcheck() {
        string s;
        cin >> ws;
        getline(cin, s);
        return s;
}

void changeKs(KS& ks)
{
    cout << "Введите количество цехов в работе" << endl;
    ks.wsections = intcorcheck(0, ks.sections);
}

void file_upload(vector<Pipe>& pipes, vector<KS>& kses) {
    ifstream input("output");
    int counter;
    input >> counter;
    for (int i = 0; i < counter; ++i) {
        Pipe newpipe = {};
        input >> newpipe.id;
        input >> newpipe.length;
        input >> newpipe.caliber;
        input >> newpipe.overhaul;
        pipes.push_back(newpipe);

    }

    input >> counter;

    for (int i = 0; i < counter; ++i) {
        KS newks = {};
        input >> newks.id;
        string s;
        input >> ws;
        getline(cin, s);
        newks.name = s;
        input >> newks.sections;
        input >> newks.efficiency;
        kses.push_back(newks);
    }
}

void changePipe(Pipe& pipe)
{
    cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
    pipe.overhaul = intcorcheck(0, 1);
}

int createPipe(int pipeid, vector<Pipe>& pipes) {
    Pipe newpipe = {};
    newpipe.id = pipeid;
    pipeid++;
    cout << "Введите длину трубы" << endl;
    newpipe.length = doublecorcheck(0, DBL_MAX);
    cout << "Введите диаметр трубы" << endl;
    newpipe.caliber = intcorcheck(0, INT_MAX);
    cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
    newpipe.overhaul = intcorcheck(0, 1);
    pipes.push_back(newpipe);
    return pipeid;
}

int createKS(int ksid, vector<KS>& kses) {
    KS newks = {};
    newks.id = ksid;
    ksid++;
    cout << "Введите название КС" << endl;
    newks.name = stringcheck();
    cout << "Введите количество цехов в КС" << endl;
    newks.sections = intcorcheck(0, INT_MAX);
    cout << "Введите количнство работающих цехов в КС" << endl;
    newks.wsections = intcorcheck(0, newks.sections);
    cout << "Введите эффективность КС" << endl;
    newks.efficiency = doublecorcheck(0, 100);
    kses.push_back(newks);
    return ksid;
}

void printall(vector<Pipe>& pipes, vector<KS>& kses) {
    cout << "Трубы: " << endl;
    for (auto &p: pipes) {
        printpipe(p);
        cout << endl;
    }
    cout << "КС: " << endl;
    for (auto &k: kses) {
        printks(k);
        cout << endl;
    }
}


int main() {
    vector<Pipe> pipes;
    vector<KS> kses; 
    int action;
    int pipeid = 1;
    int ksid = 1;
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

        action = intcorcheck(0, 7);

        if (action == 0) {
            break;
        }
        else if (action == 1) {
            createPipe(pipeid++, pipes);
        }
        else if (action == 2) {
            createKS(ksid++, kses);
        }
        else if (action == 3) {
            printall(pipes, kses);
        }
        else if (action == 4) {
            int id;
            if (pipes.empty()) {
                cout << "Нет активных труб" << endl;
                continue;
            }
            cout << "Выберите трубу которую хотите отредактировать" << endl;
            for (auto p: pipes) {
                int i = 1;
                cout << i  << " " << p.id << endl;
                i++;
            }
            id = intcorcheck(1, pipes.size());
            changePipe(pipes[id]);

        }
        else if (action == 5) {
            int id;
            if (kses.empty()) {
                cout << "Нет активных КС" << endl;
                continue;
            }
            cout << "Выберите КС который хотите отредактировать" << endl;
            for (auto k: kses) {
                int i = 1;
                cout << i  << ". " << k.id << endl;
                i++;
            }
            id = intcorcheck(0, kses.size());
            changeKs(kses[id]);
        }
        else if (action == 6) {
            save_to_file(pipes, kses);
        }
        else if (action == 7) {
            file_upload(pipes, kses);
        } 
    }
}

