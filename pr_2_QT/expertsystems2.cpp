#include "expertsystems2.h"
#include "ui_expertsystems2.h"

ExpertSystems2::ExpertSystems2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ExpertSystems2)
{
    ui->setupUi(this);
    ui->tableWidget_input_rules->setRowCount(1); // количество строк
    ui->tableWidget_input_rules->setColumnCount(2); // кол-во столбцов
    ui->tableWidget_input_rules->setHorizontalHeaderLabels({" исходное ","  замена  "});
    int totalWidth = 0;
    for (int i = 0; i <  ui->tableWidget_input_rules->columnCount(); ++i) {
        totalWidth += ui->tableWidget_input_rules->columnWidth(i);
    }

    // Устанавливаем размер QTableWidget равным суммарной ширине столбцов
    //    ui->tableWidget_input_rulesList->setMinimumWidth(totalWidth+20);
    //    ui->tableWidget_input_rulesList->setMaximumWidth(totalWidth+50);


    ui->tableWidget_out->setRowCount(1);
    ui->tableWidget_out->setColumnCount(4);
    ui->tableWidget_out->setHorizontalHeaderLabels({"Шаг"," Рабочая память "," Конф. мн-во "," Активн. правило "});

    //ui->tableWidget_input_rulesList->setColumnWidth(0,200);
}

ExpertSystems2::~ExpertSystems2()
{
    delete ui;
}


void ExpertSystems2::on_pushButton_add_rule_clicked()//добавить  правило
{
    ui->tableWidget_input_rules->setRowCount(ui->tableWidget_input_rules->rowCount()+1); // количество строк
}


void ExpertSystems2::on_pushButton_delete_rule_clicked()//удалить правило
{
    if(ui->tableWidget_input_rules->rowCount() > 1)
        ui->tableWidget_input_rules->setRowCount(ui->tableWidget_input_rules->rowCount()-1); // количество строк
}


void ExpertSystems2::on_pushButton_save_rules_clicked()//сформировать стек правил
{
    rules.clear();
    is_applied.clear();

    int rules_counter = Rule::counter_beg;

    int rowCount = ui->tableWidget_input_rules->rowCount();
    for (int row = 0; row < rowCount; row++) {
        QTableWidgetItem* item_in = ui->tableWidget_input_rules->item(row, 0);
        QTableWidgetItem* item_out = ui->tableWidget_input_rules->item(row, 1);

        std::string input = item_in->text().toStdString();
        std::string in_fact1{ };
        std::string in_fact2{ };

        size_t const conjunction_pos{ input.find(Rule::conj_token) }; 	// позиция конъюнкции


        if (conjunction_pos != input.npos)	// смогли наййти коньюнкцию?
        {
            in_fact1 = input.substr(0, conjunction_pos);
            in_fact2 = input.substr(conjunction_pos + strlen(Rule::conj_token), input.size()-1);
        }
        else
        {
            in_fact1 = input;
            in_fact2 = in_fact1;
        }
        std::string const out_fact = item_out->text().toStdString();

        rules.emplace(rules_counter, in_fact1, in_fact2, out_fact);
        is_applied.insert({ rules_counter, false });

        rules_counter++;
    }
}




void ExpertSystems2::on_pushButton_execute_DFS_clicked()
{
    std::string start_str = ui->lineEdit_in_STR->text().toStdString();
    working_memory.clear();

    std::istringstream ss(start_str); // Создаем строковый поток

    std::string token;
    while (std::getline(ss, token, ','))
    {
        working_memory.push_back(token);
    }
    size_t step{ 0 };

    print_status(step, working_memory, conflict_set, activated_rule);

    step++;

    for (std::string last_got_fact{ }; last_got_fact != Rule::goal_token; step++)
    {
        if (activated_rule != Rule::not_activated_rule)	// активировано ли хоть 1 правило?
        {
            conflict_set.pop_back();	// взятое правило из конфл множества становится акт правилом, следовательно, его удаляем из конфл мн

            last_got_fact = rules.find(activated_rule)->out_fact;

            working_memory.push_back(last_got_fact);
        }

        if (last_got_fact != Rule::goal_token)	// последний
        {
            for (auto it{ rules.cbegin() }; it != rules.cend(); ++it)	//  идем по всему дереву до конца
            {
                // находим по дереву в промежутке элемемент слева, если находим (не возвращено конечное значение working_memory.cend()),
                // проверяем, отмечено ли оно уже активированным
                if (std::find(working_memory.cbegin(), working_memory.cend(), it->in_fact1) != working_memory.cend() &&
                        std::find(working_memory.cbegin(), working_memory.cend(), it->in_fact2) != working_memory.cend() &&
                        is_applied.find(it->number)->second == false)
                {
                    conflict_set.push_back(it->number);
                    is_applied[it->number] = true;
                }
            }
            // берем последнее правило
            activated_rule = conflict_set.back();
        }
        else activated_rule = Rule::not_activated_rule;

        print_status(step, working_memory, conflict_set, activated_rule);
    }
}

std::string ExpertSystems2::print_vector(const std::vector<int> &in_vec)
{
    std::string out{ };
    for (auto it{ in_vec.cbegin() }; it != in_vec.cend(); it++ )
    {
        out += std::to_string(*it);
        if (it + 1 != in_vec.cend()) out += ", ";
    }

    return out;
}

std::string ExpertSystems2::print_vector(const std::vector<std::string> &in_vec)
{
    std::string out{ };
    for (auto it{ in_vec.cbegin() }; it != in_vec.cend(); ++it )
    {
        out += *it;
        if (it + 1 != in_vec.cend()) out += ", ";
    }

    return out;
}



void ExpertSystems2::print_status(const int &step, const std::vector<std::string> &working_memory, const std::vector<int> &conflict_set, const int &activated_rule)
{
    int row = ui->tableWidget_out->rowCount(); // Определяем текущую строку таблицы
    ui->tableWidget_out->setRowCount(row + 1); // Увеличиваем количество строк на 1

    QTableWidgetItem* itemStep = new QTableWidgetItem(QString::number(step));
    QTableWidgetItem* itemWorkingMemory = new QTableWidgetItem(QString::fromStdString(print_vector(working_memory)));
    QTableWidgetItem* itemConflictSet = new QTableWidgetItem(QString::fromStdString(print_vector(conflict_set)));
    QTableWidgetItem* itemActivatedRule = new QTableWidgetItem(QString::number(activated_rule));

    ui->tableWidget_out->setItem(row, 0, itemStep);
    ui->tableWidget_out->setItem(row, 1, itemWorkingMemory);
    ui->tableWidget_out->setItem(row, 2, itemConflictSet);
    ui->tableWidget_out->setItem(row, 3, itemActivatedRule);
}

