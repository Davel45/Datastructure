//
// Created by Vadim on 11.04.2024.
//

#ifndef DATASTRUCTURE_SINGLENODE_H
#define DATASTRUCTURE_SINGLENODE_H
#include <memory>

namespace singlenode {
    template<typename T>
    struct SingleNode {
        T data;
        std::unique_ptr<SingleNode> next;
        SingleNode(T data) : data{data}, next{nullptr} {};
    };
}
#endif //DATASTRUCTURE_SINGLENODE_H
