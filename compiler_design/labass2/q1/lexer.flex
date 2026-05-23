%{
  import java_cup.runtime.Symbol;
%}

%%
IF           { return new Symbol(sym.IF); }
ELSE         { return new Symbol(sym.ELSE); }
SWITCH       { return new Symbol(sym.SWITCH); }
[<]          { return new Symbol(sym.LT); }
[>]          { return new Symbol(sym.GT); }
[<=]         { return new Symbol(sym.LE); }
[>=]         { return new Symbol(sym.GE); }
[==]         { return new Symbol(sym.EQ); }
[!=]         { return new Symbol(sym.NE); }
"{"          { return new Symbol(sym.LBRACE); }
"}"          { return new Symbol(sym.RBRACE); }
"("          { return new Symbol(sym.LPAREN); }
")"          { return new Symbol(sym.RPAREN); }
";"          { return new Symbol(sym.SEMICOLON); }
[a-zA-Z_][a-zA-Z0-9_]* { return new Symbol(sym.ID, yytext()); }
[0-9]+       { return new Symbol(sym.NUMBER, Integer.parseInt(yytext())); }
[ \t\n\r]+   { /* Skip whitespace */ }
.            { System.err.println("Unexpected character: " + yytext()); }
