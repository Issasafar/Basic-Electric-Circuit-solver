//
// Created by issa on 21/04/24.
//

#ifndef UNTITLED_RESISTANCE_H
#define UNTITLED_RESISTANCE_H
#include "Node.h"
#include "Component.h"
class Resistance : public Component {
public:
    Resistance();
    Resistance(double val);
    Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end);

    double resistance() const;
    Component add(Component *other) override;

};


#endif //UNTITLED_RESISTANCE_H
