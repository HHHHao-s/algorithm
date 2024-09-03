#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread> // 包含sleep_for
#include <chrono> // 包含chrono_literals

std::promise<void> p;

void react(){
    std::cout << "react" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 休眠1秒
}



void f(){



    std::thread t([](){
        p.get_future().wait();
        react();
    });


    throw std::runtime_error("An error occurred in react"); // 抛出异常

    p.set_value();


    if(t.joinable()){
        t.join();
    }
}

int main() {

    try {
        f();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }
    return 0;

}