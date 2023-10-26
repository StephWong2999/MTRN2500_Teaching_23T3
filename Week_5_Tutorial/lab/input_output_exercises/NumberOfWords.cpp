#include <iostream>
#include <sstream>
#include <string>

// Solution using getline
int count_words(std::string const& sentence, std::string const& word) {
    std::stringstream ss(sentence);
    int count {0};

    while(ss.good()) {
        std::string str;
        std::getline(ss, str, ' ');
        if (str == word) {
            count ++;
        }
    }
    return count;
}

// Solution using extraction operator
int count_words(std::string const& sentence, std::string const& word) {
    std::stringstream ss(sentence);
    int count {0};
    std::string str;

    while(ss >> str) {
        if (word == str) {
            count ++;
        }
    }
    return count;
}

int main() {
    std::string sentence, word;
    std::getline(std::cin, sentence);
    std::cin >> word;
    std::cout << count_words(sentence, word) << std::endl;
}