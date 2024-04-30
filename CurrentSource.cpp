//
// Created by issa on 30/04/24.
//

#include "CurrentSource.h"
CurrentSource::CurrentSource(): Component() {}
CurrentSource::CurrentSource(double val, double resistance, Node &start, Node &end) : Component(resistance, start, end ){c = val;}
CurrentSource::CurrentSource(double val, double resistance) {c = val; r = resistance;}
