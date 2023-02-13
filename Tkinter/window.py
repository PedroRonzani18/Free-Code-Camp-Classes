from tkinter import *

from PIL import ImageTk, Image

root = Tk()
root.title('Criando nova janela')


def open():
    global image1
    top = Toplevel()
    top.title("NOVO")
    image1 = ImageTk.PhotoImage(Image.open("data/python_icon_188903.png"))
    Label(top, image=image1).pack()
    button2 = Button(top, text="close", command=top.destroy).pack()


button1 = Button(root, text="Abrir segunda", command=open).pack()

root.mainloop()
