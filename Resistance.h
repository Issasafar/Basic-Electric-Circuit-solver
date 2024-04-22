//
// Created by issa on 21/04/24.
//

#ifndef UNTITLED_RESISTANCE_H
#define UNTITLED_RESISTANCE_H
#include "Node.h"

class Resistance {
private:
    double r;
    Node* rightNd;
    Node* leftNd;
public:
    Resistance();
    Resistance(double val);
    Resistance(double val, Node& right, Node& left);

    double value() const;
    Node rightNode();
    Node leftNode();

    void rightNode(Node r);
    void leftNode(Node l);
};


#endif //UNTITLED_RESISTANCE_H
