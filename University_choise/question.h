#ifndef QUESTION_H
#define QUESTION_H
#include <QString>


class question
{
public:
    QString text,ans1_t,ans2_t;
    bool answ;
    question *ans1,*ans2;
    question(QString text,QString ans1_t="",QString ans2_t="",question *ans1=NULL,question *ans2=NULL);
};

#endif // QUESTION_H
