#include <nlohmann/json.hpp>
#include <iostream>
int main() {
    nlohmann::json jobj = {
        {"name", "john"},
        {"ID", "0356731"},
        {"email", "CHChang810716@gmail.com"}
    };
    std::cout << jobj << std::endl;
}