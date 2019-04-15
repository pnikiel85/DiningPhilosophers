#include "print.hpp"


void printForks(std::vector<Fork>& vec){

    std::stringstream ss;

    // 1st line
    for(unsigned int i = 0; i < vec.size(); i++){
        ss << "|------|----";
    }
    ss << std::endl;

    // 2nd line
    for(auto & element : vec){
        ss << "|      ";
        if(nullptr == element.getHolder()){
            ss << "| F" << element.getId() << " ";
        } else {
            ss << "|    ";
        }

    }
    ss << std::endl;

    // last line
    for(unsigned int i = 0; i < vec.size(); i++){
        ss << "|      |    ";
    }
    ss << std::endl;

//    std::lock_guard<std::mutex> lock(coutMtx);
    std::cout << ss.rdbuf();

}

void printPhilosophers(std::vector<Philosopher>& vec){

    std::stringstream ss;

    // 1st line
    for(auto & element : vec){
        if(element.holdsLeftFork()){
            ss << "|F" << element.getLeftFork().getId() << "  ";
        } else {
            ss << "|    ";
        }


        if(element.holdsRightFork()){
            ss << "F" << element.getRightFork().getId();
        } else {
            ss << "  ";
        }
        ss << "|    ";
    }

    ss << std::endl;

    // 2nd line
    for(auto & element : vec){
        ss << "|  P" << element.getId() << "  ";
        ss << "|    ";
    }
    ss << std::endl;

    // 3rd line
    for(auto & element : vec){
        if(element.isEating()){
            ss << "|eating";
        } else {
            ss << "|      ";
        }
        ss << "|    ";
    }
    ss << std::endl;

    // 4th line
    for(auto & element : vec){
        ss << "|cnt: " << element.getCounter();
        ss << "|    ";
    }
    ss << std::endl;

    // 5th line
    for(unsigned int i = 0; i < vec.size(); i++){
        ss << "|------|----";
    }
    ss << std::endl;
    ss << std::endl;

    std::cout << ss.rdbuf();

}
