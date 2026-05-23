/*@
  assigns \nothing ;
  ensures \result <==> 'a' <= c <= 'z' ;
*/
int is_lower_alpha(char c){
  return 'a' <= c && c <= 'z' ;
}
/*@
  assigns \nothing ;
  ensures \result <==> 'A' <= c <= 'Z' ;
*/
int is_upper_alpha(char c){
  return 'A' <= c && c <= 'Z' ;
}

/*@
  assigns \nothing ;
  ensures \result <==> '0' <= c <= '9' ;
*/
int is_digit(char c){
  return '0' <= c && c <= '9' ;
}

/*@
  assigns \nothing ;
  ensures 
  \result <==> (
    ('a' <= c <= 'z') ||
    ('A' <= c <= 'Z') ||
    ('0' <= c <= '9')
  ) ;
*/
int is_alpha_num(char c){
  return
    is_lower_alpha(c) || 
    is_upper_alpha(c) ||
    is_digit(c) ;
}
enum alpha {UPPER,LOWER,DIGIT,OTHER}
/*@
  assigns \nothing ;
  behavior lower:
    assumes 'a' <= c <= 'z' ;
    ensures \result == LOWER ;
  behavior upper:
    assumes 'A' <= c <= 'Z' ;
    ensures \result == UPPER ;
  behavior digit:
    assumes '0' <= c <= '9' ;
    ensures \result == DIGIT ;
  behavior other:
    assumes ! ('a' <= c <= 'z') ;
    assumes ! ('A' <= c <= 'Z') ;
    assumes ! ('0' <= c <= '9') ;
    ensures \result == OTHER ;
  complete behaviors ;
  disjoint behaviors ;
*/
enum Kind kind_of_letter(char c){
   if(is_lower_alpha(c)){
	return LOWER;
    } 
    else if(is_upper_alpha(c)){
        return UPPER;
    }
    else if(is_digit(c)){
        return DIGIT;
    }
    return OTHER;
}
