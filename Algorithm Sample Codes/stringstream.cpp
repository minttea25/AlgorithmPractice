#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// int tokenizer
std::vector<int> IntTokenizer(const std::string& s, const char delim)
{
    std::vector<int> ret;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delim))
    {
        ret.push_back(std::stoi(token));
    }
    return ret;
}

// fixed order
std::vector<int> Tokenizer(const std::string& s, const char delim, const int tokenCount)
{
    std::vector<int> ret;
    std::stringstream ss(s);
    
    int tc = tokenCount;
    while (tc > 1)
    {
        int token;
        char d;
        ss >> token >> d;
        ret.push_back(token);
        tc--;
    }
    int token;
    ss >> token;
    ret.push_back(token);

    return ret;
}

int main()
{
    std::string s("1,2,3,4,5");


    auto v1 = IntTokenizer(s, ',');
    for(const auto& i : v1) std::cout << i << ' ';
    std::cout << std::endl;
    
    auto v2 = Tokenizer(s, ',', 5);
    for (const auto& str : v2) std::cout << str << ' ';
    std::cout << std::endl;



    return 0;
}