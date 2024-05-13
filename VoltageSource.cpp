//
// Created by issa on 30/04/24.
//

#include "VoltageSource.h"

VoltageSource::VoltageSource() : Component() {}

VoltageSource::VoltageSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end)
        : Component(resistance, start, end) { v->set_value(val); }

VoltageSource::VoltageSource(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : VoltageSource(val, 0,
                                                                                                                 std::move(
                                                                                                                         start),
                                                                                                                 std::move(
                                                                                                                         end)) {}

VoltageSource::VoltageSource(double val, double resistance) {
    v->set_value(val);
    r = resistance;
}

