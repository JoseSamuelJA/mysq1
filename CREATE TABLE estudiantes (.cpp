CREATE TABLE estudiantes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(255) NOT NULL,
    carnet VARCHAR(10) NOT NULL
);
#include <iostream>
#include <mysql/mysql.h> // Incluir el encabezado del conector MySQL C++
g++ -o mi_programa -I./include mi_programa.cpp

using namespace std;

int main() {
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    // Inicializar el objeto de conexión
    conn = mysql_init(NULL);

    // Conectar a la base de datos (cambiar los valores según tu configuración)
    if (!mysql_real_connect(conn, "localhost", "usuario", "contraseña", "basededatos", 0, NULL, 0)) {
        cout << "Error al conectar a la base de datos: " << mysql_error(conn) << endl;
        return 1;
    }

    // Pedir al usuario que ingrese el nombre y el carnet del estudiante
    string nombre, carnet;
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);
    cout << "Ingrese el carnet del estudiante: ";
    getline(cin, carnet);

    // Construir la consulta SQL para insertar los datos del estudiante
    string query = "INSERT INTO estudiantes (nombre, carnet) VALUES ('" + nombre + "', '" + carnet + "')";

    // Ejecutar la consulta SQL
    if (mysql_query(conn, query.c_str())) {
        cout << "Error al ejecutar la consulta: " << mysql_error(conn) << endl;
        return 1;
    }

    // Cerrar la conexión
    mysql_close(conn);

    cout << "Datos del estudiante ingresados correctamente." << endl;

    return 0;
}