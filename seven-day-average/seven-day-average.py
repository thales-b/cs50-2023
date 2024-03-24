import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each state
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print("\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


def calculate(reader):
    # Create a dictionary to store 14 most recent days of new cases by state
    new_cases = {}

    for row in reader:
        state = row["state"]
        cases = int(row["cases"])

        if state not in new_cases:
            new_cases[state] = []

        if len(new_cases[state]) < 14:
            new_cases[state].append(cases)

    return new_cases


def comparative_averages(new_cases, states):
    for state in states:
        case_list = new_cases[state]

        if len(case_list) >= 7:
            current_week = case_list[-7:]
            previous_week = case_list[-14:-7]

            current_average = sum(current_week) / 7
            previous_average = sum(previous_week) / 7

            difference = (current_average - previous_average) / previous_average * 100

            print(f"{state} had a 7-day average of {int(current_average)} and ", end="")
            if difference > 0:
                print(f"an increase of {int(difference)}%.")
            elif difference < 0:
                print(f"a decrease of {int(abs(difference))}%.")
            else:
                print("no change.")
        else:
            print(f"Not enough data available for {state}\n")



main()
