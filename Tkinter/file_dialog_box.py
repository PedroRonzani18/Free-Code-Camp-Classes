from tkinter import *
from tkinter import filedialog

from PIL import ImageTk, Image


def partial_to_full_path(path=""):
    from pathlib import Path

    parent = Path(__file__).parent
    for _ in range(path.count('../')):
        parent = parent.parent
    parent = str(parent)

    barras = path.count('../') * '../'
    parent += path[path.find(barras) + len(barras) - 1:]
    return parent


root = Tk()
root.title("Caixa de dialogo")


def open_file():
    global image1
    root.filename = filedialog.askopenfilename(initialdir=partial_to_full_path() + "/data",
                                               title="Selecione um arquivo",
                                               filetypes=(("png files", "*.png"), ("all files", "*.*")))
    Label(root, text=root.filename).pack()
    image1 = ImageTk.PhotoImage(Image.open(root.filename))
    Label(root, image=image1).pack()


Button(root, text="Open File", command=open_file).pack()

root.mainloop()
