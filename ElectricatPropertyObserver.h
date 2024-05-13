//
// Created by issa on 13/05/24.
//

#ifndef DEMOPROJECT_ELECTRICATPROPERTYOBSERVER_H
#define DEMOPROJECT_ELECTRICATPROPERTYOBSERVER_H
class ElectricalPropertyObserver{
public:
    virtual void on_value_changed(double value) = 0;
};
#endif //DEMOPROJECT_ELECTRICATPROPERTYOBSERVER_H
