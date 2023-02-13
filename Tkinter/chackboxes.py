from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.title("CheckBoxes")
root.geometry("400x400")

def show():
    label1 = Label(root, text=var.get())
    label1.pack()


var = StringVar()

c = Checkbutton(root, text="APERTA", variable=var, onvalue="On", offvalue="Off")
c.deselect()
c.pack()

button1 = Button(root, text="Show Selection", command=show)
button1.pack()

root.mainloop()
