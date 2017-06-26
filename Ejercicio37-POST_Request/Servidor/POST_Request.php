<?php

//recojo variables
if(isset($_POST["arduino"]) && isset($_POST["mensaje"])){
	$arduino = $_POST["arduino"];
	$mensaje = $_POST["mensaje"];
}
else {
	die("error en el envio de parametros");
}

echo ("<h4>Hola Arduino numero $arduino!!</h4>");
echo ("<p>He recibido el mensaje: \"$mensaje\" mediante POST</p>");
echo ("OK")
?>