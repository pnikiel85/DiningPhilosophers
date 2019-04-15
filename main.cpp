#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <chrono>

#include "philosopher.hpp"
#include "print.hpp"

void do_work(Philosopher& p){

    using namespace std::literals::chrono_literals;

    // eat five times
    while(p.getCounter() != 3){
        p.startEating();
        std::this_thread::sleep_for(1s);
        p.stopEating();
        std::this_thread::sleep_for(0.5s);
    }

}


void createDinner(){

    using namespace std::literals::chrono_literals;

    int number = 5;
    std::vector<Fork> f_vec; 
    f_vec.reserve(number);

    for(int i = 0; i < number; i++){
        f_vec.emplace_back(i);
    }

    std::vector<Philosopher> p_vec;
    p_vec.reserve(number);


    p_vec.emplace_back(0, std::ref(f_vec.at(4)), std::ref(f_vec.at(0)));
    p_vec.emplace_back(1, std::ref(f_vec.at(0)), std::ref(f_vec.at(1)));
    p_vec.emplace_back(2, std::ref(f_vec.at(1)), std::ref(f_vec.at(2)));
    p_vec.emplace_back(3, std::ref(f_vec.at(2)), std::ref(f_vec.at(3)));
    p_vec.emplace_back(4, std::ref(f_vec.at(3)), std::ref(f_vec.at(4)));



    std::vector<std::thread> threads;
    threads.reserve(number);

    for(int i = 0; i < number; i++){
        threads.emplace_back(do_work, std::ref(p_vec.at(i)));
    }

    for(auto && element : threads)
        element.detach();

    for(int i = 0; i < 100 ; i ++){
        std::this_thread::sleep_for(0.1s);
        printForks(f_vec);
        printPhilosophers(p_vec);
    }

}

int main(){

    createDinner();

    return 0;
}