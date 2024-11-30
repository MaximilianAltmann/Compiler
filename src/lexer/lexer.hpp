#include "token.hpp"
#include <string>
#include <vector>

class lexer {
    public:
    explicit lexer(const std::string& src) : src(src), pos(0) {}
    std::vector<Token> tokenize();

    private:
    std::string src;
    size_t pos;
    std::string readWhile(bool (*condition)(char));
};