#include <string>
#include <regex>
#include "Component.h"

template<typename T>
std::string Component::get_class_name(T object) {
   /* if (object != nullptr)*/ { return std::regex_replace(std::string(typeid(object).name()), std::regex("[0-9]+"), ""); }
    return std::regex_replace(std::string(typeid(this).name()), std::regex("[0-9]+"), "");
}
