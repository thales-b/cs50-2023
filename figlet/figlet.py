import sys
from pyfiglet import Figlet
import random

figlet = Figlet()

if len(sys.argv) != 1 and len(sys.argv) != 3:
    print("Invalid usage")
elif len(sys.argv) == 1:
    fonts = figlet.getFonts()
    f = fonts[random.randint(0, len(figlet.getFonts()) - 1)]
    figlet.setFont(font=f)
    print("Input: ", end="")
    s = input()
    print(f"Output: {figlet.renderText(s)}")
elif len(sys.argv) == 3 and sys.argv[1] in ["-f", "--font"]:
    figlet.setFont(font=sys.argv[2])
    print("Input: ", end="")
    s = input()
    print(f"Output: {figlet.renderText(s)}")
