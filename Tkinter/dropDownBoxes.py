from tkinter import *

root = Tk()
root.title("CheckBoxes")
root.geometry("400x400")

var = StringVar()
var.set("Selecione uma alternativa")

list = ["a", "b"]

drop = OptionMenu(root, var, *list)
drop.pack()


def show():
    Label(root, text=var.get()).pack()


Button(root, text="Show", command=show).pack()

root.mainloop()
