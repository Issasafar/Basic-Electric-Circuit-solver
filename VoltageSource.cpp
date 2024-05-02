//
// Created by issa on 30/04/24.
//

#include "VoltageSource.h"
VoltageSource::VoltageSource(): Component() {}
VoltageSource::VoltageSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(resistance, start, end){c = val;}
VoltageSource::VoltageSource(double val, double resistance){c = val; r = resistance;}

Component VoltageSource::add(Component *other) {
    return {77, other->startNode(),other->startNode()};
}
