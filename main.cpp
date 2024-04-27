#include <iostream>
#include <cmath>
#include "Resistance.h"
#include "Node.h"
#include "Branch.h"

using namespace std;

int main() {
    Node node1 = Node(9);
    Node node2 = Node(1);
    Node ground = Node();
    Resistance r1 = Resistance(19, node1, node2);
    Resistance r2 = Resistance(8, r1.startNode(), node2);
    cout << r1.startNode().value() << endl;
    cout << r2.value() << endl;
    cout << node2.connectionsCount() << endl;
    cout << ground.connectionsCount() << endl;
    cout << r1.startNode().connectionsCount()<<endl;
    Resistance r3 = Resistance(8, ground, node2);
    Resistance r4 = Resistance(77, node2, node1);
    vector<Resistance> vector1{r3, r4};
    Branch b1 = Branch(ground, node1, vector1);
    cout << "printing the values of resistors in the branch" << endl;
    for (Resistance r: b1.branchResistors()) {
        cout << r.value() << endl;
    }
    cout << "printing the starting and ending node of the branch" << endl;
    cout << b1.startingNode().connectionsCount() << endl;
    cout << b1.endingNode().connectionsCount() << endl;
    return 0;
}