#include <iostream>
#include "Branch.h"
#include "Resistance.h"
#include "Node.h"
#include "VoltageSource.h"
#include "CurrentSource.h"
#include "Component.h"
#include "Voltage.h"
#include "Circuit.h"
#include <Eigen/Dense>
#include <boost/any.hpp>

using Eigen::MatrixXd;


int main() {
    /*  MatrixXd m(2,2);
      m(0,0) = 3;
      m(1,0) = 2.5;
      m(0,1) = -1;
      m(1,1) = m(1,0) + m(0,1);
      std::cout << m << std::endl;
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
      b1.addComponent(v1);
      b1.addComponent(c1);
      b1.addComponent(r2);
      b1.addComponent(*r1);
      b1.add_component(r4);

      auto thing = b1.components();
      auto thingtype = b1.types_map();
      for (auto el: thing) {

          std::cout<<thingtype.at(el)<<": ";
          std::cout<<el->to_string()<<std::endl;
      }
      Circuit circuit = Circuit();
      circuit.add_branch(b1);
      circuit.add_branch(b1);
      for (auto el: circuit.branches()) {
          std::cout<<"**Branch*"<<std::endl;
          for (auto ell: el.components()) {
             std::cout<<ell->to_string()<<std::endl;
          }
      }*/
    std::shared_ptr<Node> ground{std::make_shared<Node>(Node::ground())};
    std::shared_ptr<Node> n1{std::make_shared<Node>(Node(0))};
    std::shared_ptr<Node> n2{std::make_shared<Node>(Node(1))};
    VoltageSource v1 = VoltageSource(5, 0, ground, n1);
    CurrentSource c2 = CurrentSource(1, 0, n2, ground);
    Resistance r1 = Resistance(50, n1, n2);
    Resistance r2 = Resistance(100, n2, ground);
    Branch b1 = Branch(0);
    Branch b2 = Branch(1);
    Branch b3 = Branch(2);
    b3.components({r1,r2,v1,r1});
    b1.add_component(v1);
    b2.add_component(r1);
//    b2.add_component(c2);
    b2.add_component(r2);
    Circuit circuit = Circuit();
    circuit.add_branch(b1);
    circuit.add_branch(b2);
//    circuit.solve();

    boost::any a = r2;
    std::cout << Component::get_class_name(r2) << std::endl;
    std::cout << std::endl;
    if (!a.empty()) {
        const std::type_info &ti = a.type();
        std::cout << Component::get_class_name(a) << std::endl;
        std::cout << ti.name() << '\n';
    }
    return 0;

}
