cmake_minimum_required(VERSION 3.25)
project(DemoProject)

set(CMAKE_CXX_STANDARD 17)

# important setting for accessing the eigen library
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
find_package(Boost REQUIRED)
include_directories(${BOOst_INCLUDE_DIR})
message("${CMAKE_MODULE_PATH}")
message("${EIGEN3_INCLUDE_DIR}")


add_executable(untitled main.cpp concrete/Node.cpp concrete/Node.h concrete/Resistance.cpp concrete/Resistance.h concrete/Component.cpp concrete/Component.h concrete/Branch.cpp concrete/Branch.h concrete/VoltageSource.cpp concrete/VoltageSource.h concrete/CurrentSource.cpp concrete/CurrentSource.h concrete/CircuitException.cpp concrete/CircuitException.h concrete/Operators.h concrete/Voltage.cpp concrete/Voltage.h concrete/Circuit.cpp concrete/Circuit.h concrete/Current.cpp concrete/Current.h concrete/ElectricatPropertyObserver.h concrete/ElectricalProperty.cpp concrete/ElectricalProperty.h concrete/ComponentsFactory.cpp concrete/ComponentsFactory.h transpiler/Helpers.cpp transpiler/Helpers.h transpiler/Tokenizer.cpp transpiler/Tokenizer.h transpiler/Token.cpp transpiler/Token.h transpiler/ast-nodes/AstNodeBase.cpp transpiler/ast-nodes/AstNodeBase.h transpiler/ast-nodes/StringLiteral.cpp transpiler/ast-nodes/StringLiteral.h transpiler/ast-nodes/NumericLiteral.cpp transpiler/ast-nodes/NumericLiteral.h transpiler/ast-nodes/Identifier.cpp transpiler/ast-nodes/Identifier.h transpiler/ast-nodes/CallExpression.cpp transpiler/ast-nodes/CallExpression.h transpiler/Parser.cpp transpiler/Parser.h transpiler/ast-nodes/BinaryExpression.cpp transpiler/ast-nodes/BinaryExpression.h transpiler/ast-nodes/VarDeclaration.cpp transpiler/ast-nodes/VarDeclaration.h transpiler/TranspilerException.cpp transpiler/TranspilerException.h)


