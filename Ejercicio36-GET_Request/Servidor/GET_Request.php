<?php

//recojo variables
if(isset($_GET["arduino"]) && isset($_GET["mensaje"])){
	$arduino = $_GET["arduino"];
	$mensaje = $_GET["mensaje"];
}

echo ("<h4>Hola Arduino numero $arduino!!</h4>");
echo ("<p>He recibido el mensaje: \"$mensaje\" mediante GET</p>");
echo ("OK")
?>
