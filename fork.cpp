#include "fork.hpp"

/* -----------------------------------------
*   definition of class Fork methods
*
*  -----------------------------------------*/


void Fork::setHolder(Philosopher* p){
    holdBy_ = p;
}

void Fork::setRequestor(Philosopher* p){
    requestedBy_ = p;
}

Philosopher* Fork::getHolder() const {
    return holdBy_;
}

Philosopher* Fork::getRequestor() const {
    return requestedBy_;
}

int Fork::getId() const {
    return id_;
}

// following is just for checking what happens in the background
Fork::Fork(int id)
    : id_(id)
{
    std::cout << "Fork " << id_ << " created!" << std::endl;
}

Fork::~Fork(){
   std::cout << "Fork " << id_ << " destroyed!" << std::endl;
}

