import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    passwd="Pedro200418",
    database="testdb"
)

my_cursor = mydb.cursor()


def create_db():
    my_cursor.execute("CREATE DATABASE testdb")


def show_databases():
    my_cursor.execute("SHOW DATABASES")

    datas = []

    for db in my_cursor:
        print(db, 'testdb' in db[0])


def create_table():
    my_cursor.execute(
        "CREATE TABLE users (name VARCHAR(255), email VARCHAR(255), age INTEGER(10), user_id INTEGER AUTO_INCREMENT PRIMARY KEY)")


# mostra quantas tabelas foram criadas
def show_tables():
    my_cursor.execute("SHOW TABLES")
    for table in my_cursor:
        print(table)


def insert_one_value():
    sqlstuff = "INSERT INTO users (name, email, age) VALUES (%s, %s, %s)"
    record1 = ("John", "yomama@gmail.com", 40)

    my_cursor.execute(sqlstuff, record1)
    mydb.commit()


def insert_namy_values():
    sqlstuff = "INSERT INTO users (name, email, age) VALUES (%s, %s, %s)"
    record1 = [("John", "yomama@gmail.com", 40),
               ("John", "asddss@gmail.com", 25)
               ]
    my_cursor.executemany(sqlstuff, record1)
    mydb.commit()


def alter_table():
    my_cursor.execute("ALTER TABLE users DROP COLUMN coluTest")
    mydb.commit()


def show_table_data():
    # my_cursor.execute("SELECT * FROM users")
    # my_cursor.execute("SELECT name FROM users")
    my_cursor.execute("SELECT * FROM users WHERE name = 'John' ORDER BY age ASC")
    resultado = my_cursor.fetchall()

    for x in resultado:
        print(x)


def atualizar_uma_informacao_na_tabela():
    com_sql = "UPDATE users SET age = 200"
    my_cursor.execute(com_sql)
    mydb.commit()


def deletar_informacoes():
    com_sql = "DELETE FROM users WHERE user_id = 6"
    my_cursor.execute(com_sql)
    mydb.commit()


def deletar_table():
    com_sql = "DROP TABLE users"
    my_cursor.execute(com_sql)
    mydb.commit()


show_databases()
