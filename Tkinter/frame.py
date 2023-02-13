from tkinter import *
from PIL import ImageTk, Image

root = Tk()
root.title("Frames")

frame = LabelFrame(root, text="Meu Frame", padx=5, pady=5)
frame.pack(padx=30, pady=10)

button1 = Button(frame, text="RAPAIZ")
button1.pack()

root.mainloop()