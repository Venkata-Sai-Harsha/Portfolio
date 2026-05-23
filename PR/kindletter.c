enum Kind { VOWEL, CONSONANT};
/*@    requires 'a'<=c<='z';
       behavior vowel:
          assumes c \in {'a','e','i','o','u'};
          ensures \result==VOWEL;
       behavior consonant:
          assumes !(c \in {'a','e','i','o','u'});
          ensures \result==CONSONANT;
       complete behaviors vowel,consonant;
       disjoint behaviors vowel,consonant;
*/
enum Kind kind_of_letter(char c){
   if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
	return VOWEL;
    } 
    return CONSONANT;
}
