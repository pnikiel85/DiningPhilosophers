#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <shared_mutex>

#include "philosopher.hpp"

class Philosopher;

class Fork{

    int id_;
    Philosopher* holdBy_ = nullptr;
    Philosopher* requestedBy_ = nullptr;

    
public:


    Fork(int id);
    ~Fork();
    Fork& operator=(const Fork&);
    Fork(Fork &&) = default;
    Fork(const Fork &) = delete;

    void setHolder(Philosopher* p);     //lock_guard inside
    void setRequestor(Philosopher* p);  //lock_guard inside
    Philosopher* getHolder() const;     //shared_lock inside
    Philosopher* getRequestor() const;  //shared_lock inside
    int getId() const;                  //shared_lock inside

};