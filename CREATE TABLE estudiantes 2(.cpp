#include <iostream>
#include <mysql/mysql.h>

using namespace std;

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    // Inicializar la conexión a MySQL
    conn = mysql_init(NULL);
    if (conn == NULL) {
        cerr << "Error al inicializar la conexión: " << mysql_error(conn) << endl;
        return 1;
    }

    // Conectarse a la base de datos
    if (mysql_real_connect(conn, "localhost", "usuario", "contraseña", "nombre_base_de_datos", 0, NULL, 0) == NULL) {
        cerr << "Error al conectarse a la base de datos: " << mysql_error(conn) << endl;
        mysql_close(conn);
        return 1;
    }

    // Ingresar los datos del estudiante
    string nombre;
    int carnet;
    float nota;
    
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    cout << "Ingrese el carnet del estudiante: ";
    cin >> carnet;
    cout << "Ingrese la nota del estudiante: ";
    cin >> nota;

    // Insertar los datos del estudiante en la tabla
    string query = "INSERT INTO estudiantes (nombre, carnet, nota) VALUES ('" + nombre + "', " + to_string(carnet) + ", " + to_string(nota) + ")";
    if (mysql_query(conn, query.c_str()) != 0) {
        cerr << "Error al insertar datos en la tabla: " << mysql_error(conn) << endl;
        mysql_close(conn);
        return 1;
    }

    cout << "Datos insertados correctamente en la tabla." << endl;

    // Cerrar la conexión a MySQL
    mysql_close(conn);

    return 0;
}