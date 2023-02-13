from customtkinter import *

set_appearance_mode("dark")
set_default_color_theme("dark-blue")

root = CTk()
root.geometry("500x500")

frame = CTkFrame(root)
frame.pack(pady=20, padx=60, fill="both", expand=True)

label = CTkLabel(master=frame, text="Login System")
label.pack(pady=12, padx=10)

entry1 = CTkEntry(master=frame, placeholder_text="Username")
entry1.pack(pady=12, padx=10)

entry2 = CTkEntry(master=frame, placeholder_text="Password", show="*")
entry2.pack(pady=12, padx=10)

button = CTkButton(master=frame, text="Login")
button.pack(pady=12, padx=10)

checbox = CTkCheckBox(master=frame, text="Remember me")
checbox.pack(pady=12, padx=10)

root.mainloop()