//
// Created by issa on 30/04/24.
//

#include "CurrentSource.h"

#include <utility>

CurrentSource::CurrentSource() : Component() {}

CurrentSource::CurrentSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end)
        : Component(resistance, std::move(start), std::move(end)) { c->set_value(val); }

CurrentSource::CurrentSource(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : CurrentSource(val, 0,
                                                                                                                 std::move(
                                                                                                                         start),
                                                                                                                 std::move(
                                                                                                                         end)) {}

CurrentSource::CurrentSource(double val, double resistance) {
    c->set_value(val);
    r = resistance;
}
