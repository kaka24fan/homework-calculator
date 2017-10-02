#pragma once
#include<string>

class Token
{
public:
    enum TokenName { NUM, LEFTPAREN, RIGHTPAREN, DOT, PLUS, MINUS, MUL, FAC, COS, END };
    TokenName getName() {return name;}
    int getVal() {return val;}
    Token(TokenName n, int v, int z) {name = n; val = v;}
    Token(TokenName n) {name = n; val = -1;}
    std::string toString();

private:
    TokenName name;
    int val;
    std::string getEnumString(TokenName n);
};

class Lexer
{
public:
    void putback(Token t);
    Token get();
    Lexer(std::string s);
private:
    char readInChar();
    void fail(std::string msg);
    Token* last;
    std::string source;
    int next_index;
    char peek;
};
