//
// Created by issa on 21/04/24.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


class Node {
private:
    int v;
    int c = 0;
public:
    Node();

    explicit Node(int val);

    void addConnection();
    void removeConnection();
    void value(int val);
    int connectionsCount() const;
    [[nodiscard]] int value() const;
};


#endif //UNTITLED_NODE_H
