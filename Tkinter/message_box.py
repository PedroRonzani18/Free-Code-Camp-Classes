from tkinter import *
from tkinter import messagebox

root = Tk()
root.title('mensagem')


# showinfo, showwarning, showerror, askquestion, askokcancel, askyesno
def popup():
    response = messagebox.askyesno(title="Meu popup", message="Hello World")
    Label(root, text=("YES" if response else "NO")).pack()


Button(root, text="Popup", command=popup).pack()

root.mainloop()
