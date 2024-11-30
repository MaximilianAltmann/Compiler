#include "lexer.hpp"
#include <cctype>
#include <stdexcept>
#include <iostream>

std::vector<Token> lexer::tokenize()
{
    std::vector<Token> tokens;
        while(pos < src.size()) {
        char current = src[pos];
        if(isspace(current)) {
            pos++;
            continue;
        }

        if(isalpha(current)) {
            std::string word = readWhileIsAlpha();

            if(word == "int") {
                tokens.push_back({TokenType::INT, word});
            } else if(word == "float") {
                tokens.push_back({TokenType::FLOAT, word});
            } else if(word == "double") {
                tokens.push_back({TokenType::DOUBLE, word});
            }else if(word =="char") {
                tokens.push_back({TokenType::CHAR, word});
            } else {
                tokens.push_back({TokenType::IDENTIFIER, word});
            }
        } else if(isdigit(current)) {
            std::string num = readWhileIsDigit();
            tokens.push_back({TokenType::NUMBER, num});
        } else if(current == '=') {
            tokens.push_back({TokenType::EQUAL, "="});
            pos++;
        } else if(current == '+') {
            tokens.push_back({TokenType::PLUS, "+"});
            pos++;
        } else if(current == ';') {
            tokens.push_back({TokenType::SEMICOLON, ";"});
            pos++;
        } else {
            throw std::runtime_error("Unexpected character: " + std::string(1, current));
        }
    }
    tokens.push_back({TokenType::END, ""});
    return tokens;
}

std::string lexer::readWhileIsAlpha()
{
    std::string result;
    while (pos < src.size() && isalpha(src[pos])) {
        result += src[pos++];
    }
    return result;
}

std::string lexer::readWhileIsDigit()
{
    std::string result;
    while(pos < src.size() && isdigit(src[pos]) != 0) {
        result += src[pos++];
    }
    return result;
}




// Most likely trash to remove

std::string lexer::do_readWhile(bool (*condition)(char))
{
    std::string result;
    do {
        result += src[pos++];
    } while(pos < src.size() && condition(src[pos]));

    return result;
}

