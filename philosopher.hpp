#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>

#include "fork.hpp"

class Fork;

class Philosopher{

    int id_;
    int counter_ = 0;
    Fork& l_fork_;
    Fork& r_fork_;


    void requestReceived(Philosopher* p, Fork& fork);
    void requestFork(Fork& fork);
    void putFork(Fork& fork);

public:

    Philosopher(int id, Fork& l_fork, Fork& r_fork);
    ~Philosopher();

    int getId() const;
    bool startEating();
    void stopEating();
    bool isEating() const;
    bool holdsLeftFork() const;
    Fork& getLeftFork() const;
    bool holdsRightFork() const;
    Fork& getRightFork() const;
    int getCounter();

};
