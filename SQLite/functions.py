import sqlite3


# Query the DB and Return All Records
def show_all():
    # Connect to DB
    conn = sqlite3.connect('database/customer.db')
    # Create a cursor
    c = conn.cursor()
    # Query the database
    c.execute("SELECT rowid, * FROM customers")
    for item in c.fetchall():
        print(item)

    conn.commit()
    conn.close()


# Add a new record to the table
def add_one(first, last, email):
    conn = sqlite3.connect('database/customer.db')
    c = conn.cursor()
    c.executemany("INSERT INTO customers VALUES (?,?,?)", (first, last, email))
    conn.commit()
    conn.close()


def add_many(list):
    conn = sqlite3.connect('database/customer.db')
    c = conn.cursor()
    c.executemany("INSERT INTO customers VALUES (?,?,?)", (list))
    conn.commit()
    conn.close()


def delete_one(id):
    conn = sqlite3.connect('database/customer.db')
    c = conn.cursor()
    c.execute("DELETE FROM customers WHERE rowid = (?)", str(id))
    conn.commit()
    conn.close()
