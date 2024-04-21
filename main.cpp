#include <iostream>
#include <cmath>
#include "Resistance.h"
#include "Node.h"

using namespace std;

int main() {
    Node node1 = Node();
    Node node2 = Node(1);
    Resistance r1 = Resistance(19, node1, node2);
    Resistance r2 = Resistance(8, node2, node1);
    cout << r1.rightNode().value() << endl;
    cout << r2.value();
    return 0;
}