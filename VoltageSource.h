//
// Created by issa on 30/04/24.
//

#ifndef DEMOPROJECT_VOLTAGESOURCE_H
#define DEMOPROJECT_VOLTAGESOURCE_H


#include "Component.h"

class VoltageSource : public Component{
private:
    using Component::current;
public:
    VoltageSource();

    VoltageSource(double val, double resistance);

    VoltageSource(double val, double resistance, Node &start, Node &end);

};


#endif //DEMOPROJECT_VOLTAGESOURCE_H
