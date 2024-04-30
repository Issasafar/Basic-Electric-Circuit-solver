//
// Created by issa on 27/04/24.
//

#include "Component.h"
Component::~Component() = default;
Component::Component() : r{0}, v{0}, c{0}{}
Component::Component(double resistance,Node &start, Node &end) : startNd{&start}, endNd{&end}, r{resistance}, v{0}, c{0}{}
void Component::endNode(Node left) {
    endNd->removeConnection();
    endNd = &left;
    left.addConnection();
}

void Component::startNode(Node start) {
    startNd->removeConnection();
    startNd = &start;
    start.removeConnection();
}

Node &Component::startNode() { return *startNd; }

Node &Component::endNode() { return *endNd; }
double Component::resistance() const {return r;}
double Component::voltage() const{return v;}
double Component::current() const{return c;}
void Component::voltage(double val){v = val;}
void Component::resistance(double val) {r = val;}
void Component::current(double val) {c = val;}

template<class T>
typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
Component::operator+(T &other) {

}
