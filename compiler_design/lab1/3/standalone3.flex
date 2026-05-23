%%standalone

%public
%class q3
%standalone
%unicode

%%
// Multiline comments
"/*" + (.* + [\n\t])* + "*/" {System.out.printf("%-30s MULTILINE COMMENTS\n", yytext());}

// Single-line or inline comments
"//".* | "/*" + .* + "*/" {System.out.printf("%-30s COMMENTS\n", yytext());}

// Macros
"#include" | "#define" | "#ifdef" | "#ifndef" | "#endif" {System.out.printf("%-30s MACROS\n", yytext());}

// Header files
"<" + [a-zA-Z.] + ">" {System.out.printf("%-30s HEADER FILE\n", yytext());}

// Arithmetic operators
"+" | "-" | "*" | "/" | "%" | "=" | "++" | "--" {System.out.printf("%-30s ARITHMETIC OPERATORS\n", yytext());}

// Comparison operators without equality
"!=" | "<" | ">" {System.out.printf("%-30s COMPARISON OPERATORS\n", yytext());}

// Comparison operators with equality
"==" | "<=" | ">=" {System.out.printf("%-30s COMPARISON OPERATORS WITH EQUALITY\n", yytext());}

// Bitwise operators (placed above Boolean operators)
"&" | "|" | "^" | "!" | "<<" | ">>" {System.out.printf("%-30s BITWISE OPERATORS\n", yytext());}

// Boolean operators
"&&" | "||" | "!" {System.out.printf("%-30s BOOLEAN OPERATORS\n", yytext());}

// Pointer operators
"*" | "->" | "&" | "." {System.out.printf("%-30s POINTER OPERATORS\n", yytext());}

// Integer
"-"* + [0-9]+ {System.out.printf("%-30s INTEGER\n", yytext());}

// Floating point numbers
"-"* + [0-9]+"."[0-9]+ {System.out.printf("%-30s FLOATING POINT\n", yytext());}

// Whitespace
" "+ {}

// Parentheses (opening)
"(" | "[" | "{" {System.out.printf("%-30s PARENTHESES - OPENING\n", yytext());}

// Parentheses (closing)
")" | "]" | "}" {System.out.printf("%-30s PARENTHESES - CLOSING\n", yytext());}

// Colon
":" {System.out.printf("%-30s COLON\n", yytext());}

// Semicolon
";" {System.out.printf("%-30s SEMICOLON\n", yytext());}

// Identifiers
[a-zA-Z][a-zA-Z0-9]* {System.out.printf("%-30s IDENTIFIER\n", yytext());}

// Keywords (moved below identifiers)
"if" | "else" | "for" | "while" | "switch" | "case" | "break" | "continue" | "return" | "void" {System.out.printf("%-30s KEYWORD\n", yytext());}
