import unicodedata

def canonicalize_string(input_string):
    """
    Canonicalizes the input string by normalizing and converting to lowercase.
    """
    # Normalize the string to NFKC form
    normalized_string = unicodedata.normalize('NFKC', input_string)
    # Convert to lowercase
    canonicalized_string = normalized_string.lower()
    return canonicalized_string

def detect_homograph(str1, str2):
    """
    Detects if two strings are homographs by comparing their canonicalized forms.
    """
    canonical_str1 = canonicalize_string(str1)
    canonical_str2 = canonicalize_string(str2)
    
    # Compare the canonicalized strings
    return canonical_str1 == canonical_str2

# Test the function with some examples
string1 = "example.com"
string2 = "example.com"  # The 'e' is a Cyrillic 'е'
string3 = "example.com"

print(f"Are '{string1}' and '{string2}' homographs? {detect_homograph(string1, string2)}")
print(f"Are '{string1}' and '{string3}' homographs? {detect_homograph(string1, string3)}")
