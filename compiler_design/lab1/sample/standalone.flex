%%

%public
%class q1
%standalone
%unicode

%%
"if" | "else" | "for"  {System.out.print(yytext() + " KEYWORD");}
[0-9]+ {System.out.print(yytext() + " INTEGER");}
[hH][a-zA-Z] + {System.out.print(yytext() + " STARTS WITH H");}
[a-zA-Z][a-zA-Z0-9] + {System.out.print(yytext() + " IDENTIFIER");}
" " + {System.out.print(yytext() + " WHITESPACE");}