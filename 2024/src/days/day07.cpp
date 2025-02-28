#include <iostream>
#include <cassert>
#include <regex>
#include <map>
#include <sstream>
#include <string>

static std::string exampleInput = R""""(
190: 10 19
3267: 81 40 27
83: 17 5
156: 15 6
7290: 6 8 6 15
161011: 16 10 13
192: 17 8 14
21037: 9 7 18 13
292: 11 6 16 20
)"""";

static std::string puzzleInput = R""""(
100
200
)"""";

static void parse(std::string input, std::vector<int32_t>& result) {
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

static int32_t doTheThing(std::string input) {
    std::vector<int32_t> things;

    parse(input, things);

    int32_t sum = 0;
    for (size_t i = 0; i < things.size(); i++) {
        sum += things[i];
    }

    return sum;
}

void day07() {
    int32_t partOneExampleOutput = doTheThing(exampleInput);
    printf("Part One Example: %d\n", partOneExampleOutput);
    assert(partOneExampleOutput == 3749);

    // int32_t partOneOutput = doTheThing(puzzleInput);
    // printf("Part One: %d\n", partOneOutput);
    // assert(partOneOutput == 300);

    // int32_t partTwoExampleOutput = doTheThing(exampleInput);
    // printf("Part Two Example: %d\n", partTwoExampleOutput);
    // assert(partTwoExampleOutput == 30);

    // int32_t partTwoOutput = doTheThing(puzzleInput);
    // printf("Part Two: %d\n", partTwoOutput);
    // assert(partTwoOutput == 300);
}
