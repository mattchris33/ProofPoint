import re # Syntax used to search patterns in sentence (words)

def validSen(sen):
    # Put conditional statement to check if the sentence starts with a capital
    if not sen[0].isupper():
        return False
    
    # Put conditional statement to count quotation marks, if it is not even, it is false
    if sen.count('"') % 2 != 0:
        return False
    
    # Put conditional statement to check if it ends with termination
    if not sen[-1] in {'.', '?', '!'}:
        return False
    
    # Put conditional statement to check if there is any period characters beside last character
    if '.' in sen[:-1]:
        return False
    
    # Put conditional statement to ensure umbers below 13 are spelled out
    words = re.findall(r'\b\w+\b', sen) # This function checks all words in sentence
    for word in words:
        if word.isdigit() and int(word) < 13: # This function takes out the digits in sentence
            return False
    
    return True

# Test Cases
valid = [
    "The quick brown fox said “hello Mr lazy dog”.", # Valid
    "The quick brown fox said hello Mr lazy dog.", #Valid
    "One lazy dog is too few, 13 is too many.", #Valid
    "One lazy dog is too few, thirteen is too many.", #Valid
    "How many \"lazy dogs\" are there?" #Valid
]

invalid = [
    'The quick brown fox said "hello Mr. lazy dog".', #Invalid
    'the quick brown fox said “hello Mr lazy dog".', #Invalid
    '"The quick brown fox said “hello Mr lazy dog."', #Invalid
    'One lazy dog is too few, 12 is too many.', #Invalid
    'Are there 11, 12, or 13 lazy dogs?', #Invalid
    'There is no punctuation in this sentence' #Invalid
]

for sen in valid + invalid:
    result = validSen(sen)
    print(f'{sen}\n{"Valid" if result else "Invalid"}\n')
