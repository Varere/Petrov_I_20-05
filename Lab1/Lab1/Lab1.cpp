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

void printks(KS ks) {
    cout << "Id: " << ks.id << " ";
    cout << "Название: " << ks.name << " ";
    cout << "Количество цехов: " << ks.sections << " ";
    cout << "Цехов работает: " << ks.wsections << " ";
    cout << "Эффективность: " << ks.efficiency << " ";
}

void save_to_file(vector<Pipe>& pipes, vector<KS>& kses) {
    ofstream out("output");
    out << pipes.size() << endl;
    for (int i = 0; i < pipes.size(); ++i) {
        out << pipes[i].id << endl;
        out << pipes[i].length << endl;
        out << pipes[i].caliber << endl;
        if (pipes[i].overhaul == true) {
            out << 1 << endl;
        }
        else {
            out << 0 << endl;
        }
    }
    out << kses.size() << endl;
    for (int i = 0; i < kses.size(); ++i) {
        out << kses[i].id << endl;
        out << kses[i].name << endl;
        out << kses[i].sections << endl;
        out << kses[i].wsections << endl;
        out << kses[i].efficiency << endl;
    }
    out.close();
}

int intcorcheck(int min, int max) {
    int n;
    bool flag = 0;
    cin >> n;
    if (cin.peek() != '\n' || cin.fail() || n < min || n > max) {
        cin.clear();
        cin.ignore(10000000, '\n');
        flag = 1;
        cout << "Некорректный ввод. Попробуйте снова" << endl;
    }
    if (flag) {
        return intcorcheck(min, max);
    }
    else {
        return n;
    }

}

double doublecorcheck(double min, double max) {
    double n;
    bool flag = 0;
    cin >> n;
    if (cin.peek() != '\n' || cin.fail() || n < min || n > max) {
        cin.clear();
        cin.ignore(10000000, '\n');
        flag = 1;
        cout << "Некорректный ввод. Попробуйте снова" << endl;
    }
    if (flag) {
        return doublecorcheck(min, max);
    }
    else {
        return n;
    }

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

string stringcheck() {
    while (1) {
        string s;
        cin >> ws;
        getline(cin, s);
        return s;
    }
}

void changeKs(KS& ks)
{
    cout << "Введите количество цехов в работе" << endl;
    while (1) {
        ks.wsections = intcorcheck(0, INT_MAX);
        if (ks.wsections > ks.sections) {
            cout << "Количество работающих цехов не может быть больще общего количества цехов" << endl;
        }
        else {
            break;
        }
    }

}
/*void changeKS(vector<KS>& kses) {
    int tempid;
    int tempaction;
    cout << "Выберите КС который хотите отредактировать" << endl;
    for (int i = 0; i < kses.size(); ++i) {
        cout << i + 1 << " " << kses[i].id << endl;
    }
    tempid = intcorcheck(0, kses.size());
    cout << "Нынешние данные ";
    printks(kses[tempid - 1]);
    cout << endl;
    cout << "Что вы хотите отредактировать: " << endl;
    cout << "1. Название " << endl;
    cout << "2. Количество цехов " << endl;
    cout << "3. Количество цехов в работе " << endl;
    cout << "4. Эффективность " << endl;
    cout << "5. Все " << endl;
    tempaction = intcorcheck(1, 5);

    if (tempaction == 1) {
        cout << "Введите новое название" << endl;
        string s;
        s = stringcheck();
        kses[tempid - 1].name = s;
    }
    else if (tempaction == 2) {
        cout << "Введите количество цехов" << endl;
        kses[tempid - 1].sections = intcorcheck(0, INT_MAX);
    }
    else if (tempaction == 3) {
        cout << "Введите количество цехов в работе" << endl;
        while (1) {
            kses[tempid - 1].wsections = intcorcheck(0, INT_MAX);
            if (kses[tempid - 1].wsections > kses[tempid - 1].sections) {
                cout << "Количество работающих цехов не может быть больще общего количества цехов" << endl;
            }
            else {
                break;
            }
        }
    }
    else if (tempaction == 4) {
        cout << "Введите эффективность" << endl;
        kses[tempid - 1].efficiency = doublecorcheck(0, 100);
    }
    else if (tempaction == 5) {
        cout << "Введите новое название" << endl;
        string s;
        s = stringcheck();
        kses[tempid - 1].name = s;
        cout << "Введите количество цехов" << endl;
        kses[tempid - 1].sections = intcorcheck(0, INT_MAX);
        cout << "Введите количество цехов в работе" << endl;
        while (1) {
            kses[tempid - 1].wsections = intcorcheck(0, INT_MAX);
            if (kses[tempid - 1].wsections > kses[tempid - 1].sections) {
                cout << "Количество работающих цехов не может быть больще общего количества цехов" << endl;
            }
            else {
                break;
            }
        }
        cout << "Введите эффективность" << endl;
        kses[tempid - 1].efficiency = doublecorcheck(0, 100);
    }
    else {
        cout << "Некорректный ввод" << endl;
    }
}*/

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
/*void changePipe(vector<Pipe>& pipes) {
    int tempid;
    int tempaction;
    cout << "Выберите трубу которую хотите отредактировать" << endl;
    for (int i = 0; i < pipes.size(); ++i) {
        cout << i + 1 << " " << pipes[i].id << endl;
    }
    tempid = intcorcheck(1, pipes.size());
    cout << "Нынешние данные ";
    printpipe(pipes[tempid - 1]);
    cout << endl;
    cout << "Что вы хотите отредактировать: " << endl;
    cout << "1. Длина " << endl;
    cout << "2. Диаметр " << endl;
    cout << "3. Состояние " << endl;
    cout << "4. Все " << endl;
    tempaction = intcorcheck(1, 4);
    if (tempaction == 1) {
        cout << "Введите новую длину" << endl;
        pipes[tempid - 1].length = doublecorcheck(0, DBL_MAX);;
    }
    else if (tempaction == 2) {
        cout << "Введите новый диаметр" << endl;
        pipes[tempid - 1].caliber = intcorcheck(0, INT_MAX);
    }
    else if (tempaction == 3) {
        cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
        pipes[tempid - 1].overhaul = intcorcheck(0, 1);
    }
    else if (tempaction == 4) {
        cout << "Введите новую длину" << endl;
        pipes[tempid - 1].length = doublecorcheck(0, DBL_MAX);
        cout << "Введите новый диаметр" << endl;
        pipes[tempid - 1].caliber = intcorcheck(0, INT_MAX);
        cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
        pipes[tempid - 1].overhaul = intcorcheck(0, 1);
    }
    else {
        cout << "Некорректный ввод" << endl;
    }
}*/

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
    while (1) {
        newks.wsections = intcorcheck(0, INT_MAX);
        if (newks.wsections > newks.sections) {
            cout << "Количество работающих цехов не может быть больще общего количества цехов" << endl;
        }
        else {
            break;
        }
    }
    cout << "Введите эффективность КС" << endl;
    newks.efficiency = doublecorcheck(0, 100);
    kses.push_back(newks);
    return ksid;
}

void printall(vector<Pipe>& pipes, vector<KS>& kses) {
    cout << "Трубы: " << endl;
    for (int i = 0; i < pipes.size(); ++i) {
        printpipe(pipes[i]);
        cout << endl;
    }
    cout << "КС: " << endl;
    for (int i = 0; i < kses.size(); ++i) {
        printks(kses[i]);
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
            for (int i = 0; i < pipes.size(); ++i) {
                cout << i + 1 << " " << pipes[i].id << endl;
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
            for (int i = 0; i < kses.size(); ++i) {
                cout << i + 1 << " " << kses[i].id << endl;
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

