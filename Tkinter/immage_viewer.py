from tkinter import *

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


def get_all_png(directory):
    import os

    files = os.listdir(directory)
    return [file for file in files if file.endswith('.png')]


root = Tk()
root.title("Aula de imagens")

images = []

for path in get_all_png(partial_to_full_path() + "/data"):
    images.append(ImageTk.PhotoImage(Image.open("data/" + path)))

label1 = Label(image=images[0])

label1.grid(row=0, column=0, columnspan=3)

status = Label(root, text=f"Image 1 of {len(images)}", bd=1, relief=SUNKEN, anchor=E)


def forward(index):
    global label1
    global button_front
    global button_back

    label1.grid_forget()
    label1 = Label(image=images[index - 1])

    button_front = Button(root, text=">>", command=lambda: forward(index + 1))
    button_back = Button(root, text="<<", command=lambda: back(index - 1))

    if index == len(images):
        button_front = Button(root, text=">>", state=DISABLED)

    label1.grid(row=0, column=0, columnspan=3)
    button_back.grid(row=1, column=0)
    button_front.grid(row=1, column=2)

    status = Label(root, text=f"Image {index} of {len(images)}", bd=1, relief=SUNKEN, anchor=E)
    status.grid(row=2, column=0, columnspan=3, sticky=W + E)


def back(index):
    global label1
    global button_front
    global button_back

    label1.grid_forget()
    label1 = Label(image=images[index - 1])

    button_front = Button(root, text=">>", command=lambda: forward(index + 1))
    button_back = Button(root, text="<<", command=lambda: back(index - 1))

    if index == 1:
        button_back = Button(root, text="<<", state=DISABLED)

    label1.grid(row=0, column=0, columnspan=3)
    button_back.grid(row=1, column=0)
    button_front.grid(row=1, column=2)

    status = Label(root, text=f"Image {index} of {len(images)}", bd=1, relief=SUNKEN, anchor=E)
    status.grid(row=2, column=0, columnspan=3, sticky=W + E)


button_back = Button(root, text="<<", command=back, state=DISABLED)
button_exit = Button(root, text="EXIT", command=root.quit)
button_front = Button(root, text=">>", command=lambda: forward(2), pady=10)

button_back.grid(row=1, column=0)
button_exit.grid(row=1, column=1)
button_front.grid(row=1, column=2)

status.grid(row=2, column=0, columnspan=3, sticky=W + E)

# label1 = Label(image=image)
# label1.pack()

root.mainloop()
