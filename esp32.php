<?php
require_once 'conexion.php';

//file_put_contents('debug.txt', print_r($_POST, true)); // Escribe los datos recibidos en un archivo de registro

if($_POST){
    $valor = isset($_POST['valor']) ? $valor = $_POST['valor'] : $valor = null;
    $mac = isset($_POST['mac']) ? $mac = $_POST['mac'] : $mac = null;

    //Insertamos los datos en la base de datos
    $statement = $conexion->prepare("INSERT INTO info (id, valor, mac, fecha) VALUES (null, :valor, :mac, CURRENT_TIMESTAMP)");
    $statement->execute(array(':valor' => $valor, ':mac' => $mac));

    if ($statement->execute(array(':valor' => $valor, ':mac' => $mac))) {
        // Verifica si se insertaron filas
        $rowCount = $statement->rowCount();
        if ($rowCount > 0) {
            echo "Datos insertados correctamente ($rowCount filas insertadas)";
        } else {
            echo "No se insertaron datos";
        }
    } else {
        echo "Error al ejecutar la consulta";
    }
} else {
    echo "No se han enviado los datos";
}

?>