#ifndef LISTSENSOR_H
#define LISTSENSOR_H


#include <QWidget>
#include "abstractsensor.h"

class ListSensor
{
private:
    QWidget* widget;
public:
    ListSensor();
    void visit(const AbstractSensor& sensor);

};

#endif // LISTSENSOR_H
