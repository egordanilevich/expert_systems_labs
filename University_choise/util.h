#ifndef UTIL_H
#define UTIL_H
#include <QString>

struct question
{

    QString text,ans1_t,ans2_t;
    question *ans1,*ans2;
};

question q1;
#endif // UTIL_H
