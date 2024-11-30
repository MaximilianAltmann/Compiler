cmake_minimum_required(VERSION 3.10)
project(SimpleCompiler)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Compiler-Warnungen
add_compile_options(-Wall -Wextra -pedantic)

# Include-Verzeichnisse
include_directories(
    src/lexer/
    src/lexer/
    src/parser/
    src/codegen/
)

# Quellen und Ziel
add_executable(compiler
    src/lexer/lexer.cpp
    src/lexer/lexer.hpp
    src/lexer/token.hpp
    src/parser/parser.cpp
    src/parser/parser.hpp
    src/parser/ast.hpp
    src/codegen/codegen.cpp
    src/codegen/codegen.hpp
    src/main.cpp
    #src/utils/utils.cpp
    #src/utils/error.cpp
)

# Tests
#enable_testing()
#add_executable(tests
#    tests/lexer_tests.cpp
#    tests/parser_tests.cpp
#)

#target_link_libraries(tests PRIVATE compiler)
#add_test(NAME LexerTests COMMAND tests)
