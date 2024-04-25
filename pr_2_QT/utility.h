#ifndef UTILITY_H
#define UTILITY_H

#include <string>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>

// структура продукционных правил. состоит из 3 компонентов
struct Rule
{
    static constexpr char const* const goal_token{ "goal" };
    static constexpr char const* const conj_token{ "^" };
    static constexpr int not_activated_rule{ 0 };
    static constexpr int counter_beg{ 1 };

    int number;
    std::string in_fact1; 		// если ее нет, то по сути будет A&A=A
    std::string in_fact2;		// если есть конъюнкция
    std::string out_fact;

    // используем стандартное дерево. поэтому нужен конструктор
    Rule(int number = counter_beg, std::string const& in_fact1 = "", std::string const& in_fact2 = "", std::string const& out_fact = "") : number(number), in_fact1(in_fact1), in_fact2(in_fact2), out_fact(out_fact)
    { }

    // перегрузка оперторов. это нужно для сортировки дерева по номеру правила
    bool operator<(Rule const& rhs) const
    {
        return this->number < rhs.number;
    }

    bool operator==(Rule const& rhs) const
    {
        return this->number == rhs.number;
    }
};



#endif // UTILITY_H
