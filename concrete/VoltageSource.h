//
// Created by issa on 30/04/24.
//

#ifndef CIRCUITSOLVER_VOLTAGESOURCE_H
#define CIRCUITSOLVER_VOLTAGESOURCE_H


#include "Component.h"

/**
 * @file VoltageSource.h
 * @brief represent electrical voltage source
 */
class VoltageSource : public Component {
private:
    using Component::current;
public:
    VoltageSource();

    VoltageSource(double val, double resistance);

    VoltageSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end);

    VoltageSource(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end);
};


#endif //CIRCUITSOLVER_VOLTAGESOURCE_H
