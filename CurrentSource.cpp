//
// Created by issa on 30/04/24.
//

#include "CurrentSource.h"

#include <utility>

CurrentSource::CurrentSource() : Component() {}

CurrentSource::CurrentSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end)
        : Component(resistance, std::move(start), std::move(end)) { c->current(val); }

CurrentSource::CurrentSource(double val, double resistance) {
    c->current(val);
    r = resistance;
}
