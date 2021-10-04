#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

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
    int efficiency;
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
    vector<KS> kses; //plural from KS I guess
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
            cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;//error add correction check
            cin >> tempoverhaul;
            Pipe newpipe = { tempid, templength, tempcaliber, tempoverhaul };
            pipes.push_back(newpipe);
        } else if (action == 2) {
            int tempid;
            string tempname;
            int tempsections; 
            int tempwsections; 
            int tempefficiency;
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
            cout << endl;
        } else if(action == 4) {
            int tempid;
            int tempaction;
            
            cout << "Выберите трубу которую хотите отредактировать" << endl;
            for (int i = 0; i < pipes.size(); ++i) {
                cout << i + 1 << " " << pipes[i].id << endl;
            }
            cin >> tempid;
            cout << "Нынешние данные ";
            printpipe(pipes[tempid + 1]);
            cout << endl;
            cout << "Что вы хотите отредактировать: " << endl;
            cout << "1. id " << endl;
            cout << "2. Длина " << endl;
            cout << "3. Диаметр " << endl;
            cout << "4. Состояние " << endl;
            cout << "5. Все " << endl;
            cin >> tempaction;
            if (tempaction == 1) {
                cout << "Введите новый id" << endl;
                cin >> pipes[tempid - 1].id;
            } else if (tempaction == 2){
                cout << "Введите новую длину" << endl;
                cin >> pipes[tempid - 1].length;
            } else if (tempaction == 3){
                cout << "Введите новый диаметр" << endl;
                cin >> pipes[tempid - 1].caliber;
            } else if (tempaction == 4) {
                cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
                cin >> pipes[tempid - 1].overhaul;
            } else if (tempaction == 5){
                cout << "Введите новый id" << endl;
                cin >> pipes[tempid - 1].id;
                cout << "Введите новую длину" << endl;
                cin >> pipes[tempid - 1].length;
                cout << "Введите новый диаметр" << endl;
                cin >> pipes[tempid - 1].caliber;
                cout << "Труба сейчас в ремонте? (1:да; 0:нет)" << endl;
                cin >> pipes[tempid - 1].overhaul;
            } else {
                cout << "Некорректный ввод" << endl;
            }

        } else if (action == 5) {
            int tempid;
            int tempaction;

            cout << "Выберите КС который хотите отредактировать" << endl;
            for (int i = 0; i < kses.size(); ++i) {
                cout << i + 1 << " " << kses[i].id << endl;
            }
            cin >> tempid;
            cout << "Нынешние данные ";
            printks(kses[tempid - 1]);
            cout << endl;
            cout << "Что вы хотите отредактировать: " << endl;
            cout << "1. id " << endl;
            cout << "2. Название " << endl;
            cout << "3. Количество цехов " << endl;
            cout << "4. Количество цехов в работе " << endl;
            cout << "5. Эффективность " << endl;
            cout << "6. Все " << endl;
            cin >> tempaction;
            if (tempaction == 1) {
                cout << "Введите новый id" << endl;
                cin >> kses[tempid - 1].id;
            } else if (tempaction == 2) {
                cout << "Введите новое название" << endl;
                cin >> kses[tempid - 1].name;
            } else if (tempaction == 3) {
                cout << "Введите количество цехов" << endl;
                cin >> kses[tempid - 1].sections;
            } else if (tempaction == 4) {
                cout << "Введите количество цехов в работе" << endl;
                cin >> kses[tempid - 1].wsections;
            } else if (tempaction == 5) {
                cout << "Введите эффективность" << endl;
                cin >> kses[tempid - 1].efficiency;
            } else if (tempaction == 6) {
                cout << "Введите новый id" << endl;
                cin >> kses[tempid - 1].id;
                cout << "Введите новое название" << endl;
                cin >> kses[tempid - 1].name;
                cout << "Введите количество цехов" << endl;
                cin >> kses[tempid - 1].sections;
                cout << "Введите количество цехов в работе" << endl;
                cin >> kses[tempid - 1].wsections;
                cout << "Введите эффективность" << endl;
                cin >> kses[tempid - 1].efficiency;
            } else {
                cout << "Некорректный ввод" << endl;
            }
        } else if (action == 6) {
            ofstream out("output");
            out << "Трубы: " << endl;
            for (int i = 0; i < pipes.size(); ++i) {
                out << "Id: " << pipes[i].id << " ";
                out << "Длина: " << pipes[i].length << " ";
                out << "Диаметр: " << pipes[i].caliber << " ";
                if (pipes[i].overhaul == true) {
                    out << "Состояние: В ремонте";
                }
                else {
                    out << "Состояние: Исправна";
                }
            }
            out << endl;
            out << "КС: " << endl;
            for (int i = 0; i < kses.size(); ++i) {
                out << "Id: " << kses[i].id << " ";
                out << "Название: " << kses[i].name << " ";
                out << "Количество цехов: " << kses[i].sections << " ";
                out << "Цехов работает: " << kses[i].wsections << " ";
                out << "Эффективность: " << kses[i].efficiency << " ";
            }
            out << endl;
            out.close();
        } else if (action == 7) {
            ifstream input("output");
            string main;
            int typechange = 0;
            while (getline(cin, main)) {
                if (main.size() < 10) {
                    typechange++;
                }
                if (typechange > 1) {
                    for (int i = 0; i < main.size(); ++i) {
                        string temp;
                        int tempid;
                        string tempname;
                        int tempsections;
                        int tempwsections;
                        int tempefficiency;
                        int typecount = 0;
                        if (main[i] == 32) {
                            typecount++;
                            for(int j = i + 1;; ++j){
                                if (main[j] == 32) {
                                    i = j + 1;
                                    break;
                                }
                                temp += main.at(j);
                            }
                            if (typecount == 1) {
                                tempid = stoi(temp);
                            } else if (typecount == 2) {
                                tempname = temp;
                            } else if (typecount == 3) {
                                tempsections = stoi(temp);
                            } else if (typecount == 4) {
                                tempwsections = stoi(temp);
                            } else if (typecount == 5){
                                tempefficiency = stoi(temp);
                            }
                            temp.clear();
                        }
                        KS newks = { tempid, tempname, tempsections, tempwsections, tempefficiency };
                        kses.push_back(newks);
                    }
                } else {
                    for (int i = 0; i < main.size(); ++i) {
                        string temp;
                        int tempid;
                        int templength;
                        int tempcaliber;
                        bool tempoverhaul;
                        int typecount = 0;
                        if (main[i] == 32) {
                            typecount++;
                            for (int j = i + 1;; ++j) {
                                if (main[j] == 32) {
                                    i = j + 1;
                                    break;
                                }
                                temp += main.at(j);
                            }
                            if (typecount == 1) {
                                tempid = stoi(temp);
                            }
                            else if (typecount == 2) {
                                templength = stoi(temp);
                            }
                            else if (typecount == 3) {
                                tempcaliber = stoi(temp);
                            }
                            else if (typecount == 4) {
                                if (temp[-8] == 32) {
                                    tempoverhaul = 1;
                                } else {
                                    tempoverhaul = 0;
                                }
                            }
                            temp.clear();
                        }
                        Pipe newpipe = { tempid, templength, tempcaliber, tempoverhaul };
                        pipes.push_back(newpipe);
                    }
                }
            }
        }
    }
}

