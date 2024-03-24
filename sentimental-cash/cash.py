from cs50 import get_float

def calculate_coins(cents):
    coins = 0

    quarters = cents // 25
    cents %= 25
    coins += quarters

    dimes = cents // 10
    cents %= 10
    coins += dimes

    nickels = cents // 5
    cents %= 5
    coins += nickels

    coins += cents

    return coins

while True:
    dollars = get_float("Change owed: ")
    if dollars >= 0:
        break

cents = round(dollars * 100)
coins = calculate_coins(cents)
print(coins)


def calculate_coins(cents):
    coins = 0

    quarters = cents // 25
    cents %= 25
    coins += quarters

    dimes = cents // 10
    cents %= 10
    coins += dimes

    nickels = cents // 5
    cents %= 5
    coins += nickels

    coins += cents

    return coins

