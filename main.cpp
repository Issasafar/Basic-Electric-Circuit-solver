#include <iostream>
#include <cmath>
#include "Resistance.h"
#include "Node.h"

using namespace std;

int main() {
    Node node1 = Node(9);
    Node node2 = Node(1);
    Node ground = Node();
    Resistance r1 = Resistance(19, node1, node2);
    Resistance r2 = Resistance(8, node1, node2);
    cout << r1.rightNode().value() << endl;
    cout << r2.value() << endl;
    cout << node2.connectionsCount() << endl;
    cout << ground.connectionsCount() << endl;
    return 0;
}