//
// Created by issa on 13/05/24.
//

#ifndef DEMOPROJECT_ELECTRICATPROPERTYOBSERVER_H
#define DEMOPROJECT_ELECTRICATPROPERTYOBSERVER_H
/**
 * @file ElectricalPropertyObserver.h
 * @brief base observer interface for voltage or current changes
 */
class ElectricalPropertyObserver {
public:
    virtual void on_voltage_changed(double value) = 0;

    virtual void on_current_changed(double value) = 0;
};

#endif //DEMOPROJECT_ELECTRICATPROPERTYOBSERVER_H
