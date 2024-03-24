import cs50

while True:
    height = cs50.get_int("Height: ")
    if height <= 8 and height >= 1:
        break

for i in range(height):
    print(" " * (height - i - 1), end = "")
    print("#" * (i + 1))

