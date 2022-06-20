//
// Created by Nate Lampros on 11/3/21.
//

#ifndef CS235_BST_BSTINTERFACE_H
#define CS235_BST_BSTINTERFACE_H
template<typename T>
class BSTInterface
{
public:
    BSTInterface(void) {}
    virtual ~BSTInterface(void) {}

    /** Return true if node added to BST, else false */
    virtual bool addNode(const T&) = 0;

    /** Return true if node removed from BST, else false */
    virtual bool removeNode(const T&) = 0;

    /** Return true if BST cleared of all nodes, else false */
    virtual bool clearTree() = 0;

    /** Return a level order traversal of a BST as a string */
    virtual std::string toString() const = 0;
};
#endif //CS235_BST_BSTINTERFACE_H
