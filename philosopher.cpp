#include "philosopher.hpp"

/* ----------------------------------------------------------------
*
*   definitions of Philosopher
*
* ----------------------------------------------------------------*/

// new requestor
// fork can be managed by owner only
void Philosopher::requestReceived(Philosopher* p, Fork& fork){

    if(this == fork.getHolder() && !this->isEating()){ //hand over if only one fork and request
        fork.setHolder(p);
        fork.setRequestor(this);
    } else if(this == fork.getHolder() && this->isEating()){    //don't hand over when you're eating
        fork.setRequestor(p);
    }
}

// take fork or send a request to holder
void Philosopher::requestFork(Fork& fork){
    if(nullptr == fork.getHolder()){    // take a fork ...
        fork.setHolder(this);
    } else {
        fork.getHolder()->requestReceived(this, fork);  // ... or send a request
    }
}

// put on table or hand over if requested
void Philosopher::putFork(Fork& fork){
    if( this == fork.getHolder() && nullptr == fork.getRequestor() ){     // put on table if not requested
        fork.setHolder(nullptr);
    } else if( this == fork.getHolder() && nullptr != fork.getRequestor() ){  // hand over if requested
        fork.setHolder(fork.getRequestor());
        fork.setRequestor(nullptr);
    }
}

Philosopher::Philosopher(int id, Fork& l_fork, Fork& r_fork)
    : id_(id), l_fork_(l_fork), r_fork_(r_fork)
{
    std::cout << "Philosopher " << id_ << " created!" << std::endl;
}

Philosopher::~Philosopher(){
    std::cout << "Philosopher " << id_ << " destroyed!" << std::endl;
}

int Philosopher::getId() const {
    return id_;
}

// request two forks to start eating
bool Philosopher::startEating(){
    if(!this->isEating()){  // can't request if already has two forks
        this->requestFork(r_fork_);
        this->requestFork(l_fork_);
    }
    // check if Philosopher is holding two forks and return
    return this->isEating();
}

// put Forks to stop eating
void Philosopher::stopEating(){
    if(this->isEating()) {
        this->counter_++;
    }
    this->putFork(r_fork_);         // put on table or hand over if requested
    this->putFork(l_fork_);         // put on table or hand over if requested
}


// Philosopher is eating if is holding two forks
bool Philosopher::isEating() const {
    if( this == r_fork_.getHolder() && this == l_fork_.getHolder()){
        return true;
    }
    else {
        return false;
    }
}

// all methods below for printing only
bool Philosopher::holdsLeftFork() const {
    return this == this->l_fork_.getHolder();
}

Fork& Philosopher::getLeftFork() const {
    return l_fork_;
}

bool Philosopher::holdsRightFork() const {
    return this == this->r_fork_.getHolder();
}

Fork& Philosopher::getRightFork() const {
    return r_fork_;
}

int Philosopher::getCounter(){
    return this->counter_;
}

