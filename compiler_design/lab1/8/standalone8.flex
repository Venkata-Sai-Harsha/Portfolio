%%

%public
%class three
%unicode
%standalone

%%

// Roman numerals
M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3}) { System.out.println(yytext() + " ROMAN_NUMERAL"); }

// Ignore whitespace
[ \t\r\n\f]+ { /* ignore */ }

// Unrecognized tokens
. { System.out.println("Unrecognized: " + yytext()); }

