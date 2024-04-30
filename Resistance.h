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
    Resistance(double val, Node& start, Node& end);

    double resistance() const;
    void printValue();
};


#endif //UNTITLED_RESISTANCE_H
