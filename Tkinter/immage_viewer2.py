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

current_index = 1

for path in get_all_png(partial_to_full_path() + "/data"):
    images.append(ImageTk.PhotoImage(Image.open("data/" + path)))

image_label = Label(image=images[current_index-1])

image_label.grid(row=0, column=0, columnspan=3)

status = Label(root, text=f"Image 1 of {len(images)}", bd=1, relief=SUNKEN, anchor=E)


def forward():
    global image_label
    global button_front
    global button_back
    global status
    global current_index

    if current_index < len(images):
        current_index += 1
        button_back.config(state=NORMAL)

    image_label.config(image=images[current_index - 1])

    if current_index == len(images):
        button_front.config(state=DISABLED)

    status.config(text=f"Image {current_index} of {len(images)}")


def back():
    global image_label
    global button_front
    global button_back
    global status
    global current_index

    if current_index > 1:
        current_index -= 1
        button_front.config(state=NORMAL)

    image_label.config(image=images[current_index - 1])

    if current_index == 1:
        button_back.config(state=DISABLED)

    status.config(text=f"Image {current_index} of {len(images)}")


button_back = Button(root, text="<<", command=back, state=DISABLED)
button_exit = Button(root, text="EXIT", command=root.quit)
button_front = Button(root, text=">>", command=forward, pady=10)

button_back.grid(row=1, column=0)
button_exit.grid(row=1, column=1)
button_front.grid(row=1, column=2)

status.grid(row=2, column=0, columnspan=3, sticky=W + E)

root.mainloop()
