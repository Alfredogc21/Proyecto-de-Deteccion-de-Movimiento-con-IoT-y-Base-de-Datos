# Proyecto de deteccion de movimiento y humo con IoT y base de datos

Este proyecto utiliza un ESP32 para monitorear sensores PIR y de humo, enviando los registros a una base de datos MariaDB a través de un servidor PHP.

## Descripción

El objetivo de este proyecto es monitorear la detección de movimiento (PIR) y la presencia de humo mediante sensores conectados a un ESP32. Los registros generados por los sensores se envían a una base de datos MariaDB utilizando un servidor PHP como intermediario.

## Componentes

- ESP32: Controla y procesa los datos de los sensores.
- Sensor PIR: Detección de movimiento.
- Sensor de humo: Detección de humo.
- MariaDB: Base de datos para almacenar registros.
- PHP: Maneja la recepción de datos y la interacción con la base de datos.

## Configuración

1. Configura tu entorno de desarrollo para el ESP32.
2. Carga el código del ESP32 en tu placa.
3. Asegúrate de tener una base de datos MariaDB configurada.
4. Configura el servidor PHP con la URL correcta de la base de datos.
5. Conecta los sensores PIR y de humo al ESP32 según sea necesario.

## Estructura del Proyecto

- `conexionBdSensorMovimiento.ino`: Contiene el código fuente del proyecto ESP32.
- `esp32.php`: Contiene el codigo para insertar datos a la base de datos.
- `conexion.php`: Contiene la conexion a la base de datos.
- `sensorarduino.sql`: Contiene la estructura de la base de datos relacional.

## Dependencias

- `WiFi.h`: Biblioteca para la conexión Wi-Fi con el ESP32.
- `HTTPClient.h`: Biblioteca para realizar solicitudes HTTP con el ESP32.

## Uso

1. Enciende el ESP32 y verifica la conexión a la red Wi-Fi.
2. Monitorea los registros generados por los sensores en la consola del ESP32.
3. Verifica que los datos se estén enviando correctamente al servidor PHP y almacenándose en la base de datos MariaDB.

## Créditos

Este proyecto fue desarrollado por [Alfredo Gomez Culma].


