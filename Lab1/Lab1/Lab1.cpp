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

/*int corcheck() {
    string n;
    bool flag = 0;
    int num = 0;
    cin >> n;
    if (cin.peek() != '\n') {
        cin.clear();
        cin.ignore(10000000, '\n');
        flag = 1;
        cout << "Некорректный ввод. Попробуйте снова" << endl;
    }
    for (int i = 0; i < n.size(); ++i) {
        if (isdigit(n[i])) {
            int a = n[i];
            num = num * 10 + (a - 48);
        } else {
            flag = 1;
            cout << "Некорректный ввод. Попробуйте снова" << endl;
            break;
        }
    }
    if (flag) {
        return corcheck();
    } else{
        return num;
    }
    
}*/

int intcorcheck(int min, int max) {
    int n;
    //string space = " ";
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
    //string space = " ";
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


int main() {
    vector<Pipe> pipes;
    vector<KS> kses; //plural from KS I guess
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
            int tempid;
            int templength;
            int tempcaliber;
            bool tempoverhaul;
            tempid = pipeid;
            pipeid++;
            cout << "Введите длину трубы" << endl;
            templength = doublecorcheck(0, DBL_MAX);
            cout << "Введите диаметр трубы" << endl;
            tempcaliber = intcorcheck(0, INT_MAX);
            cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
            tempoverhaul = intcorcheck(0, 1);
            Pipe newpipe = { tempid, templength, tempcaliber, tempoverhaul };
            pipes.push_back(newpipe);
        }
        else if (action == 2) {
            int tempid;
            string tempname;
            int tempsections;
            int tempwsections;
            int tempefficiency;
            tempid = ksid;
            ksid++;
            cout << "Введите название КС" << endl;
            cin >> tempname;
            cout << "Введите количество цехов в КС" << endl;
            tempsections = intcorcheck(0, INT_MAX);
            cout << "Введите количнство работающих цехов в КС" << endl;
            while (1) {
                tempwsections = intcorcheck(0, INT_MAX);
                if (tempwsections > tempsections) {
                    cout << "Количество работающих цехов не может быть больще общего количества цехов" << endl;
                } else {
                    break;
                }
            }
            cout << "Введите эффективность КС" << endl;
            tempefficiency = doublecorcheck(0, 100);
            KS newks = { tempid, tempname, tempsections, tempwsections, tempefficiency };
            kses.push_back(newks);
        }
        else if (action == 3) {
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
        else if (action == 4) {
            int tempid;
            int tempaction;
            if (pipes.empty()) {
                cout << "Нет активных труб" << endl;
                continue;
            }
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
                pipes[tempid - 1].length = doublecorcheck(DBL_MIN, DBL_MAX);;
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
                pipes[tempid - 1].length = doublecorcheck(DBL_MIN, DBL_MAX);
                cout << "Введите новый диаметр" << endl;
                pipes[tempid - 1].caliber = intcorcheck(0, INT_MAX);
                cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
                pipes[tempid - 1].overhaul = intcorcheck(0, 1);
            }
            else {
                cout << "Некорректный ввод" << endl;
            }

        }
        else if (action == 5) {
            int tempid;
            int tempaction;
            if (kses.empty()) {
                cout << "Нет активных КС" << endl;
                continue;
            }
            cout << "Выберите КС который хотите отредактировать" << endl;
            for (int i = 0; i < kses.size(); ++i) {//!!!!!!!!!!!!!!!!!!!!!
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
                cin >> kses[tempid - 1].name;
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
                cin >> kses[tempid - 1].name;
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
        }
        else if (action == 6) {
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
        else if (action == 7) {
            ifstream input("output");
            int counter;
            string main;
            int tempid;
            int templength;
            int tempcaliber;
            bool tempoverhaul;
            string tempname;
            int tempsections;
            int tempwsections;
            int tempefficiency;
            input >> counter;
            for (int i = 0; i < counter; ++i) {
                input >> tempid;
                input >> templength;
                input >> tempcaliber;
                input >> tempoverhaul;
                Pipe newpipe = { tempid, templength, tempcaliber, tempoverhaul };
                pipes.push_back(newpipe);

            }

            input >> counter;

            for (int i = 0; i < counter; ++i) {
                input >> tempid;
                getline(cin, main);
                tempname = main;
                input >> tempsections;
                input >> tempwsections;
                input >> tempefficiency;
                KS newks = { tempid, tempname, tempsections, tempwsections, tempefficiency };
                kses.push_back(newks);
            }
        } else {
            cout << "Некорректный ввод" << endl;
        }
        
    }
}

