#include <iostream>
#include "Branch.h"
#include "Resistance.h"
#include "Node.h"
#include "VoltageSource.h"
#include "CurrentSource.h"

using namespace std;

int main() {
    Node node1 = Node(9);
    Node node2 = Node(1);
    Node ground = Node();
    Component *r1;
    Resistance resistance = Resistance(10, node1, node2);
    r1 = &resistance;
    Component r2 = Resistance(20, r1->startNode(), node2);
    Component r3 = Resistance(30, ground, node2);
    Component r4 = Resistance(40, node2, node1);
    Component *branch;
    Branch b = Branch();
    branch = &b;
    vector<Component> vector1{*r1, r2, r3, r4, *branch};
    if (dynamic_cast<Resistance *>(r1) != nullptr) {
        cout << "r1 is a resistor" << endl;
    }
    VoltageSource v1 = VoltageSource(10, 19);
    CurrentSource c1 = CurrentSource(20, 90);
    cout << v1.resistance() << endl;
    cout << c1.current() << endl;
    return 0;
}