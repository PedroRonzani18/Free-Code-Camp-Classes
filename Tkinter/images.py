from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.title("Aula de imagens")

button_exit = Button(root, text="Exit", command=root.quit)
button_exit.pack()

image = ImageTk.PhotoImage(Image.open("data/python_104451.png"))
label1 = Label(image=image)
label1.pack()

root.mainloop()
