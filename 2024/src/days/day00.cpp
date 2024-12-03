#include <iostream>
#include <cassert>
#include <regex>
#include <map>
#include <sstream>
#include <string>

static std::string exampleInput = R""""(
10
20
)"""";

static std::string puzzleInput = R""""(
100
200
)"""";

void parse(std::string input, std::vector<int32_t>& result) {
    std::istringstream inputStream(input);
    std::string line;

    while (std::getline(inputStream, line, '\n')) {
        if (line.empty()) continue;

        std::regex numberRegex(R"((\d+))", std::regex::ECMAScript);
        std::smatch match;
        if (!std::regex_match(line, match, numberRegex)) {
            printf("Something wrong with: %s\n", line.c_str());
            continue;
        }

        result.push_back(std::stoi(match[1].str()));
    }
}

int32_t doTheThing(std::string input) {
    std::vector<int32_t> things;

    parse(input, things);

    int32_t sum = 0;
    for (size_t i = 0; i < things.size(); i++) {
        sum += things[i];
    }

    return sum;
}

void day00() {
    int32_t partOneOutput = doTheThing(exampleInput);
    printf("Part One: %d\n", partOneOutput);
    assert(partOneOutput == 30);

    int32_t partTwoOutput = doTheThing(puzzleInput);
    printf("Part Two: %d\n", partTwoOutput);
    assert(partTwoOutput == 300);
}
