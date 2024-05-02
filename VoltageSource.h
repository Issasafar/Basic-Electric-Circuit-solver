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

    VoltageSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end);
    Component add(Component *other) override;
};


#endif //DEMOPROJECT_VOLTAGESOURCE_H
