#include "days/days.h"
#include <functional>
#include <iostream>

std::vector<std::function<void()>> days = {
    day00,
    day01,
    day02,
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <day>" << std::endl;
        return 1;
    }

    int day = std::stoi(argv[1]);
    if (day < 0 || day > days.size()) {
        std::cerr << "Invalid day: " << day << std::endl;
        return 1;
    }

    days[day]();

    return 0;
}
