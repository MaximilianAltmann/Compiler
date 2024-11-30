#include <string>
// Token-Types
enum class TokenType { INT, IDENTIFIER, NUMBER, EQUAL, PLUS, SEMICOLON, END };

// Token-structure
struct Token {
    TokenType type;
    std::string value;
};