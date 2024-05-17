#include "concrete/ComponentsFactory.h"
#include "transpiler/Helpers.h"
#include "transpiler/Token.h"
#include "transpiler/Tokenizer.h"
#include <iostream>
#include "boost/any.hpp"
#include "transpiler/Parser.h"

void example();
int main() {
    std::string str = "99 \"hello\"";
    std::vector<Token> tokens  = tokenize(str);
    for (auto token: tokens) {
        auto thing = tokens.begin();
        std::cout<<token<<std::endl;
        auto x = 9;

    }
    return 0;
}

void example(){
    ComponentsFactory cf = ComponentsFactory();
    auto ground = cf.get_ground();
    auto n1 = cf.get_node();
    auto n2 = cf.get_node();
    auto v1 = cf.get_voltage_source(5, ground, n1);
    auto r1 = cf.get_resistance(50, n1, n2);
    auto r2 = cf.get_resistance(100, n2, ground);
    auto b1 = cf.get_branch({v1, r1, r2});
    auto circuit = cf.get_circuit({b1});
    circuit.solve();
    circuit.print_matrix();
}
