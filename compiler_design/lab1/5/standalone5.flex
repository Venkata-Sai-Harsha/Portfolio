import java.util.*;

%%standalone


%public
%class q5
%standalone
%unicode

%{
    public static HashSet<String> identifiers = new HashSet<>();
    public static int count = 0;
    public static void printIdentifiers() {
        System.out.println();
        System.out.println("Identifiers found:");
        for (String identifier : identifiers) {
            System.out.println(identifier);
        }
    }

    public static int countSemi = 0;
%}

%%
"/*" + (.* + [\n\t])* + "*/" {System.out.printf("%-30s MULTILINE COMMENTS\n", yytext());}

"//endOfFile" {printIdentifiers();}

"//".* | "/*" + .* + "*/" {System.out.printf("%-30s COMMENTS\n", yytext());}

"#include" | "#define" | "#ifdef" | "#ifndef" | "#endif" {System.out.printf("%-30s MACROS\n", yytext());}

"int" | "float" | "char" {System.out.printf("%-30s DATA TYPES\n", yytext());}

"if" | "else" | "for" | "while" | "switch" | "case" | "break" | "continue" | "return" | "void" | "printf" {System.out.printf("%-30s KEYWORD\n", yytext());}

"<" + [a-zA-Z.] + ">" {System.out.printf("%-30s HEADER FILE\n", yytext());}

[a-zA-Z][a-zA-Z0-9]+ {
    System.out.printf("%-30s IDENTIFIER\n", yytext());
    identifiers.add(yytext());    
}

"+" | "-" | "*" | "/" | "%" | "=" | "++" | "--" {System.out.printf("%-30s ARTHEMETIC OPERATORS\n", yytext());}

"==" | "<=" | ">=" {System.out.printf("%-30s COMPARASION OPERATORS WITH EQUALITY\n", yytext());}

"!=" | "<" | ">" {System.out.printf("%-30s COMPARASION OPERATORS\n", yytext());}

"&&" | "||" | "!" {System.out.printf("%-30s BOOLEAN OPERATORS\n", yytext());}

"*" | "->" | "&" | "." {System.out.printf("%-30s POINTER OPERATORS\n", yytext());}

"&" | "|" | "^" | "!" | "<<" | ">>" {System.out.printf("%-30s BITWISE OPERATORS\n", yytext());}

"-"* + [0-9]+ {System.out.printf("%-30s INTEGER\n", yytext());}

"-"* + [0-9]+"."[0-9]+ {System.out.printf("%-30s FLOATING POINT\n", yytext());}

" "+ {}

"(" | "[" | "{" {System.out.printf("%-30s PARANTHESES - OPENING\n", yytext());}

")" | "]" | "}" {System.out.printf("%-30s PARANTHESES - CLOSING\n", yytext());}

":" {System.out.printf("%-30s COLON\n", yytext());}

";" {
    System.out.printf("%-30s SEMICOLON\n", yytext());
    count += 1;
}

. {System.out.printf("%-30s ERROR\n", yytext());}
