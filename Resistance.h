//
// Created by issa on 21/04/24.
//

#ifndef CIRCUITSOLVER_RESISTANCE_H
#define CIRCUITSOLVER_RESISTANCE_H

#include "Node.h"
#include "Component.h"
/**
 * @file Resistance.h
 * @brief electrical resistance
 */
class Resistance : public Component {
private:
    // overriding methods from the parent class
    Component add(Component *thisObj, Component *other) override;

    Component subtract(Component *thisObj, Component *other) override;

    Component multiply(Component *thisObj, Component *other) override;

    Component divide(Component *thisObj, Component *other) override;

    Component &add_equal(Component *thisObj, Component *other) override;

    Component &subtract_equal(Component *thisObj, Component *other) override;

public:
    Resistance();

    Resistance(double val);

    Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end);

    double resistance() const;

};


#endif //CIRCUITSOLVER_RESISTANCE_H
