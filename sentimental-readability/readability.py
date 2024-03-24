from cs50 import get_string

def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    index = calculate_index(letters, words, sentences)
    grade = get_grade(index)
    print(f"Grade {grade}")


def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for char in text:
        if char.isspace():
            count += 1
    return count + 1


def count_sentences(text):
    count = 0
    for char in text:
        if char in [".", "!", "?"]:
            count += 1
    return count


def calculate_index(letters, words, sentences):
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)


def get_grade(index):
    if index >= 16:
        return "16+"
    elif index < 1:
        return "Before Grade 1"
    else:
        return str(index)


if __name__ == "__main__":
    main()


