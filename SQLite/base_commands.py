import sqlite3

# Connect to a database
conn = sqlite3.connect("database/customer.db")

# Create a cursor
c = conn.cursor()


# Create a table named customers
def create_database():
    c.execute("""CREATE TABLE customers(
            first_name text,
            last_name text,
            email text
            )
        """)
    # Datatypes: NULL, INTEGER, REAL, TEXT, BLOB


def insert_data():
    many_customers = [
        ("Wes", "Brown", "wes@brown.com"),
        ('Steph', 'Kuewa', 'steph@kuewa.com'),
        ('Dan', 'Pas', 'dan@pas.com')
    ]

    # c.execute("INSERT INTO customers VALUES ('John', 'Elder', 'john@codemy.com')")
    c.executemany("INSERT INTO customers VALUES (?,?,?)", many_customers)


def display_database():
    c.execute(
        "SELECT rowid, * FROM customers")  # procure pelo rowid e todos os dados associados aquele rowid (id da linha)
    # c.fetchone()
    # c.fetchmany(50)
    for data in c.fetchall():
        # print(f"{data[0]} {data[1]}\t | {data[2]}")
        print(data)


def display_filtered_data():
    c.execute("SELECT * FROM customers WHERE last_name = 'Elder'")
    #         "SELECT * FROM customers WHERE age >= 21"
    #         "SELECT * FROM customers WHERE last_name LIKE 'Br%'"
    for data in c.fetchall():
        print(data)


def update_records():
    # c.execute("UPDATE customers SET first_name = 'Bob' WHERE last_name = 'Elder'")
    c.execute("UPDATE customers SET first_name = 'John' WHERE rowid = 1")


def delete_record():
    c.execute("DELETE from customers WHERE rowid = 3")


def get_records_custom_ordering():
    c.execute("SELECT rowid, * FROM customers ORDER BY rowid")  # ASC = ascendente
    for item in c.fetchall():
        print(item)


def select_with_and_or():
    c.execute("SELECT rowid, * FROM customers WHERE last_name LIKE 'Br%' AND rowid = 2")
    for item in c.fetchall():
        print(item)


def limiting_results():
    c.execute("SELECT rowid, * FROM customers LIMIT 2") # retorna no maximo 2 resultados


def delete_entire_table():
    c.execute("DROP TABLE customers")


if __name__ == '__main__':
    select_with_and_or()
    # Commit command
    conn.commit()

    # Close connection
    conn.close()
