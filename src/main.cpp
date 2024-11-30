#include <iostream>
#include <string.h>
#include "lexer.hpp"

int main() 
{
    std::string src_code = R"(
        int fte = 5;
        int y = e + 255;
        float y = 5;
    )";
    lexer lexer(src_code);
    std::vector<Token> tokens = lexer.tokenize();
    // print tokens 
    for(Token& t : tokens) {
        std::cout << "Type: "<< static_cast<int>(t.type) << " Value: " << t.value << "\n";
    }

    std::cout << "Hello world Compiler edition" << "\n";
    return 0;
}