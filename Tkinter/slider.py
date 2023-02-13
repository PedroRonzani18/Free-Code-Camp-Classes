from tkinter import *

root = Tk()
root.title("Sliders")
root.geometry("400x400")

vertical = Scale(root, from_=0, to=200, orient=VERTICAL)
vertical.pack()

horizontal = Scale(root, from_=0, to=400, orient=HORIZONTAL)
horizontal.pack()

lbl1 = Label(root, text=horizontal.get())
lbl1.pack()


def slide():
    global lbl1
    lbl1.config(text=horizontal.get())
    root.geometry(f"{horizontal.get()}x{vertical.get()}")


Button(root, text="clica ae", command=slide).pack()

root.mainloop()
