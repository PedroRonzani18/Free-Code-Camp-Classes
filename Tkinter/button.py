from tkinter import *

root = Tk()


def myClick():
    label1 = Label(root, text="APERTEI FI NU")
    label1.pack()


button1 = Button(root, text="Clica ae meu fi", command=myClick, fg="red", bg="green")
button1.pack()

root.mainloop()
