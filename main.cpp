#include <iostream>
#include "Branch.h"
#include "Resistance.h"
#include "Node.h"
#include "VoltageSource.h"
#include "Circuit.h"
#include <Eigen/Dense>

using Eigen::MatrixXd;


int main() {
    std::shared_ptr<Node> ground{std::make_shared<Node>(Node::ground())};
    std::shared_ptr<Node> n1{std::make_shared<Node>(Node(0))};
    std::shared_ptr<Node> n2{std::make_shared<Node>(Node(1))};
    VoltageSource v1 = VoltageSource(5, ground, n1);
    Resistance r1 = Resistance(50, n1, n2);
    Resistance r2 = Resistance(100, n2, ground);
    Resistance r3 = Resistance(50, n1, ground);
    Branch b1 = Branch(0, {v1, r1, r2});
    Branch b2 = Branch(1, {r3});
    Circuit circuit = Circuit({b1, b2});
    std::cout << circuit.solve() << std::endl;
//    std::cout << "r1 volt should be 5: " << r1.startNode()->get_voltage() << std::endl;
//    std::cout << r1.voltage() << std::endl;
//    std::cout << "r1 current " << r1.current() << std::endl;
//    std::cout<< "r3 current "<<r3.current()<<std::endl;
    return 0;

}
