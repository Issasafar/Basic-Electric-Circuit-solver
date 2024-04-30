//
// Created by issa on 30/04/24.
//

#include "VoltageSource.h"
VoltageSource::VoltageSource(): Component() {}
VoltageSource::VoltageSource(double val, double resistance, Node &start, Node &end) : Component(resistance, start, end){c = val;}
VoltageSource::VoltageSource(double val, double resistance){c = val; r = resistance;}
