from tkinter import *

root = Tk()

e = Entry(root, width=50, borderwidth=5)
e.pack()
e.insert(0, "Seu nome")

def myClick():
    label1 = Label(root, text=e.get())
    label1.pack()


button1 = Button(root, text="Digite seu nome", command=myClick, fg="red", bg="green")
button1.pack()

root.mainloop()
