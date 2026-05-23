%%

%public
%class two
%unicode
%standalone

%%

// Phone number
[0-9]{3}-[0-9]{3}-[0-9]{4} { System.out.println(yytext() + " PHONE_NUMBER"); }

// Email ID (simplified)
[a-zA-Z0-9._%\\+-]+@[a-zA-Z0-9.-]+[.][a-zA-Z]{3} { System.out.println(yytext() + " EMAIL_ID"); }

// Website link (simplified)
(http:\/\/|https:\/\/|www[.])[a-zA-Z0-9.-]+[.][a-zA-Z]+(\/\S*)? { System.out.println(yytext() + " WEBSITE_LINK"); }

// Ignore whitespace
[ \t\r\n\f]+ { /* ignore */ }

// Unrecognized tokens
. { System.out.println("Unrecognized: " + yytext()); }

