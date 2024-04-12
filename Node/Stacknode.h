//
// Created by Vadim on 12.04.2024.
//

#ifndef DATASTRUCTURE_STACKNODE_H
#define DATASTRUCTURE_STACKNODE_H
#include <memory>

namespace stacknode {
    template<typename T>
    struct StackNode {
        T data;
        std::unique_ptr<StackNode> next;
        StackNode(T data) : data{data}, next{nullptr} {};
    };
}
#endif //DATASTRUCTURE_STACKNODE_H
