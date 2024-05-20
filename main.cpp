#include "concrete/ComponentsFactory.h"
#include "transpiler/Helpers.h"
#include "transpiler/Token.h"
#include "transpiler/Tokenizer.h"
#include <iostream>
#include "transpiler/ast-nodes/Identifier.h"
#include "transpiler/ast-nodes/AstNodeBase.h"
#include "transpiler/Parser.h"
#include "transpiler/TranspilerException.h"
#include "transpiler/repel/Interpreter.h"
void example();

void console();

int main() {
//    example();
   std::vector<std::string> lines{
       "let g = Ground()",
    "let n1 = Node()",
    "let n2 = Node()",
    "let v1 = VoltageSource(5, g, n1)",
    "let r1 = Resistance(50, n1, n2)",
    "let r2 = Resistance(100, n2, g)",
    "let b1 = Branch(v1, r1, r2)",
    "let circuit = Circuit(b1)",
    "solve(circuit)"
   };
//   example();
   Interpreter interpreter = Interpreter();
   for(std::string line: lines){
       auto tokens = tokenize(line);
       interpreter.visit(parse(tokens));
   }
//    console();
//    auto tkns = tokenize("print(x,y +z)");
//    auto thing = buildAstTree(tkns);
//    Interpreter i;
//    auto interpreted = i.visit(thing);
//    if (interpreted.getValue().type() == typeid(double)) {
//        double value = boost::get<double>(interpreted.getValue());
//        std::cout << "Value: " << value << std::endl;
//    }else if(interpreted.getValue().type() == typeid(std::string)){
//        std::cout<<boost::get<std::string>(interpreted.getValue())<<std::endl;
//    }
//    std::string str = " fun(x y 9)";
//    std::vector<Token> tokens  = tokenize(str);
//    for(auto token :tokens){
//        std::cout<<token<<std::endl;
//    }
//    auto thing = buildAstTree(tokens);
//    int x = 9;
//    std::shared_ptr<AstNodeBase> aa = std::make_shared<AstNodeBase>(Identifier("varx"));
    return 0;
}

void console() {
    std::string prompt = "\033[1;36m#> \033[0;33m";
    std::string line;
    std::stringstream screen;
    Interpreter interpreter;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        if (line == ":exit") {
            std::cout << "\033[0m";
            break;
        }
        if (line == ":clear") {
            system("clear");
            continue;
        }
        try {
            std::vector<Token> tokens = tokenize(line);
//            for (auto token: tokens) {
//                std::cout << token << std::endl;
//            }
            interpreter.visit(parse(tokens));
        } catch (TranspilerException &transpilerException) {
            std::cout << transpilerException.what() << std::endl;
        } catch(CircuitException& circuitException){
            std::cout<<circuitException.what()<<std::endl;
        }
    }
}

void example() {
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
