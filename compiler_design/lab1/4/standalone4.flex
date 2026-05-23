%%standalone

%public
%class q4
%standalone
%unicode

%%
"//".* | "/*" + .* + "*/" {System.out.printf("%-30s COMMENTS\n", yytext());}

"#include" | "#define" | "#ifdef" | "#ifndef" | "#endif" {System.out.printf("%-30s MACROS\n", yytext());}

"if" | "else" | "for" | "while" | "switch" | "case" | "break" | "continue" | "return" | "void" {System.out.printf("%-30s KEYWORD\n", yytext());}

"<" + [a-zA-Z.] + ">" {System.out.printf("%-30s HEADER FILE\n", yytext());}

[a-zA-Z][a-zA-Z0-9]+ {System.out.printf("%-30s IDENTIFIER\n", yytext());}

"+" | "-" | "*" | "/" | "%" | "=" | "++" | "--" {System.out.printf("%-30s ARTHEMETIC OPERATORS\n", yytext());}

"==" | "<=" | ">=" {System.out.printf("%-30s COMPARASION OPERATORS WITH EQUALITY\n", yytext());}

"!=" | "<" | ">" {System.out.printf("%-30s COMPARASION OPERATORS\n", yytext());}

"&&" | "||" | "!" {System.out.printf("%-30s BOOLEAN OPERATORS\n", yytext());}

"*" | "->" | "&" | "." {System.out.printf("%-30s POINTER OPERATORS\n", yytext());}

"&" | "|" | "^" | "!" | "<<" | ">>" {System.out.printf("%-30s BITWISE OPERATORS\n", yytext());}

[0-9]+ {System.out.printf("%-30s INTEGER\n", yytext());}

[0-9]+"."[0-9]+ {System.out.printf("%-30s FLOATING POINT\n", yytext());}

" "+ {}

"(" | "[" | "{" {System.out.printf("%-30s PARANTHESES - OPENING\n", yytext());}

")" | "]" | "}" {System.out.printf("%-30s PARANTHESES - CLOSING\n", yytext());}

":" {System.out.printf("%-30s COLON\n", yytext());}

";" {System.out.printf("%-30s SEMICOLON\n", yytext());}

. {System.out.printf("%-30s ERROR\n", yytext());}
