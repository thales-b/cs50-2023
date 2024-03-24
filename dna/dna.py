import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # Read database file into a variable
    database_file = sys.argv[1]
    database = read_csv(database_file)

    # Read DNA sequence file into a variable
    sequence_file = sys.argv[2]
    sequence = read_sequence(sequence_file)

    # Find longest consecutive runs of each STR in DNA sequence
    str_counts = {}
    for str_name in list(database[0].keys())[1:]:
        str_counts[str_name] = longest_match(sequence, str_name)

    # Check database for matching profiles
    for person in database:
        match = True
        for str_name in str_counts:
            if int(person[str_name]) != str_counts[str_name]:
                match = False
                break

        if match:
            print(person["name"])
            return

    print("No match")



def read_csv(filename):
    data = []
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            data.append(row)
    return data


def read_sequence(filename):
    with open(filename, "r") as file:
        sequence = file.read().strip()
    return sequence


def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    i = 0
    while i < sequence_length:
        count = 0

        # Check if the current sequence matches the subsequence
        while sequence[i : i + subsequence_length] == subsequence:
            count += 1
            i += subsequence_length

        longest_run = max(longest_run, count)
        i += 1

    return longest_run



if __name__ == "__main__":
    main()
