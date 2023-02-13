import sqlite3
from tkinter import *

root = Tk()
root.title("CheckBoxes")
root.geometry("400x400")

# create a database or connect to one
connect = sqlite3.connect('address_book.db')

# Create cursor
c = connect.cursor()

# Create table
'''
c.execute("""CREATE TABLE addresses (
        f_name text,
        l_name text,
        address text,
        city text,
        state text,
        zipcode integer 
        ) """)

'''
# Create text boxes
f_name = Entry(root, width=30)
f_name.grid(row=0, column=1, padx=20, pady=(10, 0))

l_name = Entry(root, width=30)
l_name.grid(row=1, column=1, padx=20)

address = Entry(root, width=30)
address.grid(row=2, column=1, padx=20)

city = Entry(root, width=30)
city.grid(row=3, column=1, padx=20)

state = Entry(root, width=30)
state.grid(row=4, column=1, padx=20)

zipcode = Entry(root, width=30)
zipcode.grid(row=5, column=1, padx=20)

delete_box = Entry(root, width=30)
delete_box.grid(row=9, column=1)

# Create text box labels
f_name_label = Label(root, text="First Name")
f_name_label.grid(row=0, column=0, pady=(10, 0))

l_name_label = Label(root, text="Last Name")
l_name_label.grid(row=1, column=0)

address_label = Label(root, text="Address")
address_label.grid(row=2, column=0)

city_label = Label(root, text="City")
city_label.grid(row=3, column=0)

state_label = Label(root, text="State")
state_label.grid(row=4, column=0)

zipcode_label = Label(root, text="Zipcode")
zipcode_label.grid(row=5, column=0)

delete_box_label = Label(root, text="ID Number")
delete_box_label.grid(row=9, column=0, pady=5)


# Create a function to Delete a Record
def delete():
    # create a database or connect to one
    connect = sqlite3.connect('address_book.db')
    # Create cursor
    c = connect.cursor()

    # Delete a record
    c.execute(f"DELETE from addresses WHERE oid = {delete_box.get()}")

    delete_box.delete(0, END)

    # Commit changes
    connect.commit()
    # Close connection
    connect.close()


# Create submit function to database
def submit():
    # create a database or connect to one
    connect = sqlite3.connect('address_book.db')
    # Create cursor
    c = connect.cursor()

    # insert into table
    c.execute("INSERT INTO addresses VALUES (:f_name, :l_name, :address, :city, :state, :zipcode)",
              {
                  'f_name': f_name.get(),
                  'l_name': l_name.get(),
                  'address': address.get(),
                  'city': city.get(),
                  'state': state.get(),
                  'zipcode': zipcode.get()
              }
              )

    # Commit changes
    connect.commit()
    # Close connection
    connect.close()

    # Clear text boxes
    f_name.delete(0, END)
    l_name.delete(0, END)
    address.delete(0, END)
    city.delete(0, END)
    state.delete(0, END)
    zipcode.delete(0, END)


# Create submit button
submit_btn = Button(root, text="Add record to Database", command=submit)
submit_btn.grid(row=6, column=0, columnspan=2, pady=10, padx=10, ipadx=100)

# Create querry label
query_label = Label(root)


# Create query function
def query():
    # create a database or connect to one
    connect = sqlite3.connect('address_book.db')
    # Create cursor
    c = connect.cursor()

    # Query the database
    c.execute(("SELECT *, oid FROM addresses"))
    reccords = c.fetchall()

    # Loop thru results
    print_records = ""

    for record in reccords:
        print_records += str(record[0]) + str(record[1]) + " " + str(record[6]) + "\n"

    query_label.config(text=print_records)
    query_label.grid(row=12, column=0, columnspan=2)
    # se quiser que dados apareçam debaixo do show records, colocar row=8

    # Commit changes
    connect.commit()
    # Close connection
    connect.close()


def update():
    global editor
    # Create a database or connect to one
    conn = sqlite3.connect('address_book.db')
    # Create cursor
    c = conn.cursor()

    record_id = delete_box.get()

    c.execute("""UPDATE addresses SET
    	f_name = :first,
    	l_name = :last,
    	address = :address,
    	city = :city,
    	state = :state,
    	zipcode = :zipcode 
    	WHERE oid = :oid""",
              {
                  'first': f_name_editor.get(),
                  'last': l_name_editor.get(),
                  'address': address_editor.get(),
                  'city': city_editor.get(),
                  'state': state_editor.get(),
                  'zipcode': zipcode_editor.get(),
                  'oid': record_id
              })

    # Commit changes
    conn.commit()
    # Close connection
    conn.close()

    editor.destroy()


# Create edit program to update a record
def edit():
    global editor
    editor = Tk()
    editor.title("Editing")
    editor.geometry("400x400")

    # Create a database or connect to one
    conn = sqlite3.connect('address_book.db')
    # Create cursor
    c = conn.cursor()

    record_id = delete_box.get()

    # Query the database
    c.execute("SELECT * FROM addresses WHERE oid = " + record_id)
    records = c.fetchall()

    # Create Global Variables for text box names
    global f_name_editor
    global l_name_editor
    global address_editor
    global city_editor
    global state_editor
    global zipcode_editor

    # Create text boxes
    f_name_editor = Entry(editor, width=30)
    f_name_editor.grid(row=0, column=1, padx=20, pady=(10, 0))

    l_name_editor = Entry(editor, width=30)
    l_name_editor.grid(row=1, column=1, padx=20)

    address_editor = Entry(editor, width=30)
    address_editor.grid(row=2, column=1, padx=20)

    city_editor = Entry(editor, width=30)
    city_editor.grid(row=3, column=1, padx=20)

    state_editor = Entry(editor, width=30)
    state_editor.grid(row=4, column=1, padx=20)

    zipcode_editor = Entry(editor, width=30)
    zipcode_editor.grid(row=5, column=1, padx=20)

    # Create text box labels
    f_name_label = Label(editor, text="First Name")
    f_name_label.grid(row=0, column=0, pady=(10, 0))

    l_name_label = Label(editor, text="Last Name")
    l_name_label.grid(row=1, column=0)

    address_label = Label(editor, text="Address")
    address_label.grid(row=2, column=0)

    city_label = Label(editor, text="City")
    city_label.grid(row=3, column=0)

    state_label = Label(editor, text="State")
    state_label.grid(row=4, column=0)

    zipcode_label = Label(editor, text="Zipcode")
    zipcode_label.grid(row=5, column=0)

    # Loop through results
    for record in records:
        f_name_editor.insert(0, record[0])
        l_name_editor.insert(0, record[1])
        address_editor.insert(0, record[2])
        city_editor.insert(0, record[3])
        state_editor.insert(0, record[4])
        zipcode_editor.insert(0, record[5])

    # Create a Save Button to save edited
    save_button = Button(editor, text="Edit Record", command=update)
    save_button.grid(row=6, column=0, columnspan=2, pady=10, padx=10, ipadx=145)


# Create a Query Button
query_button = Button(root, text="Show Records", command=query)
query_button.grid(row=7, column=0, columnspan=2, pady=10, padx=10, ipadx=137)

# Create a Delete Button
delete_button = Button(root, text="Delete Record", command=delete)
delete_button.grid(row=10, column=0, columnspan=2, pady=10, padx=10, ipadx=136)

# Create an Update Button
edit_button = Button(root, text="Edit Record", command=edit)
edit_button.grid(row=11, column=0, columnspan=2, pady=10, padx=10, ipadx=145)

# Commit changes
connect.commit()

# Close connection
connect.close()

root.mainloop()
