#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat(QString foodname1)
{
    qDebug()<<"Treat teacher with"<<foodname1.toUtf8().data();
}
