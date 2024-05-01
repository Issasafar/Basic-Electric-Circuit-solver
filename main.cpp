#include <iostream>
#include "Branch.h"
#include "Resistance.h"
#include "Node.h"
#include "VoltageSource.h"
#include "CurrentSource.h"
#include "Component.h"

using namespace std;

int main() {
    std::shared_ptr<Node> node1{std::make_shared<Node>(Node(9))};
    std::shared_ptr<Node> node2{std::make_shared<Node>(Node(1))};
    std::shared_ptr<Node> ground{std::make_shared<Node>(Node())};
    Component *r1;
    Resistance resistance = Resistance(10, node1, node2);
    r1 = &resistance;
    Component r2 = Resistance(20, node1, node2);
    Component r3 = Resistance(30, ground, node2);
    Component r4 = Resistance(40, node2, node1);

    Component *branch;
    Branch b = Branch();
    branch = &b;
    vector<Component> vector1{*r1, r2, r3, r4, *branch};
    if (dynamic_cast<Resistance *>(r1) != nullptr) {
        cout << "r1 is a resistor" << endl;
    }
    std::shared_ptr<Node> vn{std::make_shared<Node>(Node(99))};
    std::shared_ptr<Node> ve{std::make_shared<Node>(Node(8))};
    std::shared_ptr<Node> cn{std::make_shared<Node>(Node{9})};
    std::shared_ptr<Node> ce{std::make_shared<Node>(Node{34})};

    VoltageSource v1 = VoltageSource(10, 19, vn, ve);
    VoltageSource v2 = VoltageSource(9, 8);
    CurrentSource c1 = CurrentSource(20, 90, cn, ce);
    cout << v1.resistance() << endl;
    cout << c1.current() << endl;
    Component comp1 = Component(9, node2, node2);
    Component comp2 = Component(2, node1, node2);
    Component val = v1 + v2;
    cout << "the val value is " << val.resistance() << endl;
    cout << v1.startNode()->connectionsCount() << endl;
    cout << "val connection start count is : " << val.startNode()->connectionsCount() << " with value of: "
         << val.startNode()->value() << endl;
    cout << "node1 connections count: " << r2.startNode()->connectionsCount() << endl;
    return 0;
}