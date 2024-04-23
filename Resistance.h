//
// Created by issa on 21/04/24.
//

#ifndef UNTITLED_RESISTANCE_H
#define UNTITLED_RESISTANCE_H
#include "Node.h"

class Resistance {
private:
    double r;
    Node* startNd;
    Node* endNd;
public:
    Resistance();
    Resistance(double val);
    Resistance(double val, Node& start, Node& end);

    double value() const;
    Node &startNode();
    Node &endNode();

    void startNode(Node r);
    void endNode(Node l);
};


#endif //UNTITLED_RESISTANCE_H
