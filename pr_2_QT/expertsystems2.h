#ifndef EXPERTSYSTEMS2_H
#define EXPERTSYSTEMS2_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include "utility.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ExpertSystems2; }
QT_END_NAMESPACE

class ExpertSystems2 : public QMainWindow
{
    Q_OBJECT

public:
    ExpertSystems2(QWidget *parent = nullptr);
    ~ExpertSystems2();

private slots:

    void on_pushButton_add_rule_clicked();

    void on_pushButton_delete_rule_clicked();

    void on_pushButton_save_rules_clicked();

    //void DFS(std::vector<Rule>& conflictSet, std::vector<std::string>& startLetters, int count);

    void on_pushButton_execute_DFS_clicked();

private:
    std::set<Rule> rules{ };	// объявляем дерево, которое уже будет отсортировано по номеру правила
    std::map<int, bool> is_applied{ };	// словарь - ключ-значение - инт-бул - правило-было_применимо?
    std::vector<std::string> working_memory; 	// раб память
    std::vector<int> conflict_set;				//  конфл множество
    int activated_rule{ Rule::not_activated_rule };	// активное правило

    QTableWidgetItem* item = new QTableWidgetItem();
    QString text = "";
    Ui::ExpertSystems2 *ui;

    std::string print_vector(std::vector<int> const& in_vec);
    std::string print_vector(std::vector<std::string> const& in_vec);
    void print_status(int const& step, std::vector<std::string> const& working_memory, std::vector<int> const& conflict_set, int const& activated_rule);

};
#endif // EXPERTSYSTEMS2_H
