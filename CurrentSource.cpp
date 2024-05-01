//
// Created by issa on 30/04/24.
//

#include "CurrentSource.h"
CurrentSource::CurrentSource(): Component() {}
CurrentSource::CurrentSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(resistance, start, end ){c = val;}
CurrentSource::CurrentSource(double val, double resistance) {c = val; r = resistance;}
