//
// Created by issa on 21/04/24.
//

#ifndef UNTITLED_RESISTANCE_H
#define UNTITLED_RESISTANCE_H
#include "Node.h"
#include "Component.h"

class Resistance : public Component {
private:
    Component add(Component *thisObj, Component *other) override;
    Component subtract(Component *thisObj, Component *other) override;
    Component multiply(Component *thisObj, Component *other) override;
    Component divide(Component *thisObj, Component *other) override;
    Component& add_equal(Component *thisObj, Component *other) override;
    Component& subtract_equal(Component*thisObj,Component *other) override;
public:
    Resistance();
    Resistance(double val);
    Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end);

    double resistance() const;

};


#endif //UNTITLED_RESISTANCE_H
