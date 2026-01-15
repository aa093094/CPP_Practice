#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitcher_list;

    pitcher_list.insert(std::pair<std::string, double>("1st", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("2nd", 2.93));

    pitcher_list.insert(std::pair<std::string, double>("3rd", 2.95));

    pitcher_list.insert(std::make_pair("4th", 3.04));
    pitcher_list.insert(std::make_pair("5th", 3.05));
    pitcher_list.insert(std::make_pair("6th", 3.09));

    pitcher_list["7th"] = 3.56;
    pitcher_list["8th"] = 3.76;
    pitcher_list["9th"] = 3.90;

    print_map(pitcher_list);

    std::cout << "1st's stat :: " << pitcher_list["1st"] << std::endl;
}
