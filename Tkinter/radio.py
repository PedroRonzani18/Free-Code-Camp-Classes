from tkinter import *

root = Tk()
root.title("Radio")

modes = [
    ("Cheese", "Cheese"),
    ("Catupiri", "Catupiri"),
    ("Moda", "Moda"),
    ("Marguerita", "Marguerita"),
]

pizz = StringVar()
pizz.set(modes[0][0])

for text, mode in modes:
    Radiobutton(root, text=text, variable=pizz, value=mode).pack()

Label(root, text=pizz.get()).pack()


def clicked(value):
    Label(root, text=value).pack()


Button(root, text="Clica ae vei", command=lambda: clicked(pizz.get())).pack()

root.mainloop()
