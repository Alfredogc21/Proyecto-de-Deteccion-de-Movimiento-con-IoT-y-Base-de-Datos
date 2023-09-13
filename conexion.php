<?php

try {
    $conexion = new PDO('mysql:host=localhost;dbname=nombredelabd', 'root', '');
    echo "Conexion exitosa <br>";

} catch (PDOException $e) {
    echo 'Error: ' . $e->getMessage();
}


?>