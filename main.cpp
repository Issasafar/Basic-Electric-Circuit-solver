#include <iostream>
#include "Branch.h"
#include "Resistance.h"
#include "Node.h"
#include "VoltageSource.h"
#include "CurrentSource.h"
#include "Component.h"
#include "Voltage.h"

int main() {
    std::shared_ptr<Node> node1{std::make_shared<Node>(Node(9))};
    std::shared_ptr<Node> node2{std::make_shared<Node>(Node(1))};
    std::shared_ptr<Node> ground{std::make_shared<Node>(Node())};
    Component *r1;
    Resistance resistance = Resistance(10, node1, node2);
    r1 = &resistance;
    Resistance r2 = Resistance(20, node1, node2);
    Resistance r3 = Resistance(30, ground, node2);
    Resistance r4 = Resistance(40, node2, node1);

    Component *branch;

    if (dynamic_cast<Resistance *>(r1) != nullptr) {
        std::cout << "r1 is a resistor" << std::endl;
    }


    std::shared_ptr<Node> vn{std::make_shared<Node>(Node(99))};
    std::shared_ptr<Node> ve{std::make_shared<Node>(Node(8))};
    std::shared_ptr<Node> cn{std::make_shared<Node>(Node{9})};
    std::shared_ptr<Node> ce{std::make_shared<Node>(Node{34})};

    VoltageSource v1 = VoltageSource(10, 20, vn, ve);
    VoltageSource v2 = VoltageSource(9, 8);
    CurrentSource c1 = CurrentSource(20, 90, cn, ce);
    Component comp1 = Component(9, node2, node2);
    Component comp2 = Component(2, node1, node2);
    Component val = r2 + r3;
    std::cout << "the values for r2 are: " << r2.resistance() << std::endl;
    std::cout << "the val resistance value is " << val.resistance() << std::endl;
    std::cout << "val connection start count is : " << val.startNode()->connectionsCount() << " with value of Node: "
              << val.startNode()->value() << std::endl;
    std::cout << "node1 connections count: " << r2.startNode()->connectionsCount() << std::endl;
    Component cmp1 = Component(10, node2, node1);
    Component cmp2 = Component(7, node2, node2);
    Component cmp3 = cmp1 * cmp2;
    std::cout << r2.to_string() << std::endl;
    std::cout << v1.to_string() << std::endl;
    std::cout << c1.to_string() << std::endl;
//    cmp1 += cmp2;
    std::cout << cmp1.to_string()<<std::endl;
//    std::cout<<cmp1.get_class_name();
//    r2 + r3;
    // auto  result =  r2 + r3;
//    v1 + c1;
    Component s = static_cast<Component>(c1);
    s = cmp2 * s;
    std::cout << s.to_string() << std::endl;
    Voltage vv1 = Voltage(9,true);
    std::cout<<vv1.voltage()<<std::endl;

    ground->get_voltage();
//    nodev.get_voltage();
    std::shared_ptr<Node> dev = std::make_shared<Node>(Node(9, 10));

    ground->get_voltage().known();
    Branch b1 = Branch();
//    b1.addComponent(r1);
    b1.addComponent(v1);
    b1.addComponent(c1);
    return 0;

}
