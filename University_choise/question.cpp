#include "question.h"

question::question(QString text, QString ans1_t, QString ans2_t, question *ans1, question *ans2)
{
    if (ans1 == nullptr || ans2 == nullptr)
    {
        answ = true;
        this->text = text;
    }
    else
    {
        answ = false;
        this->text = text;
        this->ans1_t = ans1_t;
        this->ans2_t = ans2_t;
        this->ans1 = ans1;
        this->ans2 = ans2;
    }
}
