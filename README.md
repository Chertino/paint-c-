Proyecto Paint
Descripción
Proyecto Paint es una aplicación de pintura básica desarrollada en C++ utilizando el framework Qt. Permite a los usuarios dibujar y editar imágenes de forma sencilla, con características como cambio de color y grosor de lápiz, así como la capacidad de abrir y guardar archivos de imagen en diferentes formatos.

Características Principales
Dibujo y edición de imágenes.
Cambio dinámico de color y grosor de lápiz.
Funcionalidad para abrir y guardar archivos de imagen en diferentes formatos.
Borrador para borrar áreas específicas de la imagen.
Interfaz de usuario intuitiva y fácil de usar.


Requisitos del Sistema
Sistema operativo compatible con Qt.
Compilador compatible con C++11 o superior.
Biblioteca Qt 5.0 o superior instalada.


Instrucciones de Uso
Abrir la Aplicación: Ejecutar el archivo ejecutable o compilar y ejecutar el código fuente utilizando un compilador compatible con Qt.
Crear o Abrir una Imagen: Utilice las opciones del menú Archivo para crear una nueva imagen o abrir una existente.
Dibujar y Editar: Utilice el lápiz para dibujar sobre la imagen. Puede cambiar el color y grosor del lápiz según sus preferencias.
Guardar la Imagen: Guarde su obra de arte utilizando la opción Guardar como del menú Archivo.



Desde la opcion de ajustes puede seleccionar opciones como Color, Grosor, Borrador y Limpiar lienzo.

![image](https://github.com/Chertino/paint-c-/assets/137564638/e948d8da-2efd-4e2f-9d17-24a083158f09)

Si presiona la opcion Color podra customizar el color del pincel deacuerdo a lo que desee.

![image](https://github.com/Chertino/paint-c-/assets/137564638/558eca39-d5c3-4401-ac94-4e395b4a33ae)

Si selecciona la opcion Grosor tambien podra variar el ancho de la linea del pincel interactuando con las flechas de el lado derecho o insertando un valor por teclado.

![image](https://github.com/Chertino/paint-c-/assets/137564638/e59eccfa-f2ae-45d7-a745-adcdaf37b962)

Tambien esta la opcion de usar el Borrador si desea eliminar alguna parte de su dibujo o la opcion Limpiar lienzo si desea tener de nuevo el lienzo en blanco.

![image](https://github.com/Chertino/paint-c-/assets/137564638/7a8bdb91-f68a-47ae-ac49-144974fa6154)

![image](https://github.com/Chertino/paint-c-/assets/137564638/a6c3e87c-d292-44b9-b042-d6562e440b36)


Si selecciona Guardar como.

![image](https://github.com/Chertino/paint-c-/assets/137564638/8589a3ed-8a70-4f99-9883-38ff01e971b4)

Puede elegir entre varios formatos de archivo compatibles.

![image](https://github.com/Chertino/paint-c-/assets/137564638/7c8648c0-fb5b-4e78-b6c7-3a977c1b5a2e)

En la ventana emergente, puedes elegir la ubicacion de tu archivo y simplemete haz click en guardar.

![image](https://github.com/Chertino/paint-c-/assets/137564638/fbf0ea58-c30c-4720-8ab8-2a6c4386742d)

Dando click en Abrir Puede abrir archivos que sean compatibles con el lienzo.

![image](https://github.com/Chertino/paint-c-/assets/137564638/ebd3629f-fb7c-4cb4-ad98-71a0a0d1a401)


Si presiona la opcion salir o intenta cerrar el lienzo, Una ventana emergente le dara la posibilidad de guardad los cambios antes de cerrar la ventana.

![image](https://github.com/Chertino/paint-c-/assets/137564638/dc69225c-ce72-45e1-928c-38ae03a7f9c6)

![image](https://github.com/Chertino/paint-c-/assets/137564638/fafe1ec9-408c-4b81-9faf-792b4c8eb64d)



Sera redireccionado a su carpeta de archivos y podra guardarlo donde quiera y ponerle el nombre que desee.







Contribuciones
Las contribuciones son bienvenidas. Si deseas contribuir a este proyecto, no dudes en enviar un pull request.


Licencia
Este proyecto está licenciado bajo Licencia MIT.


Créditos
Este proyecto se inspiró en el tutorial de programación de Derek Banas en YouTube.

//Acerca de los archivos.

Los primeros 3 archivos, son los recursos que crea el la plataforma de qt para incializar una correcta ejecucion.

//Headers

Proyectopaint.h se encargará de crear todos los eventos y funciones que ocurran dentro del area de trabajo, por asi decirlo es la parte donde se crean y se definen todas las funciones.
Mainwindow.h crea las funciones de la venta principal, lo que corresponde a modificaciones, guardar archivo, menus, etc.

//Archivos .cpp

main.cpp tiene como objetivo mostrar la venta en pantalla, lo que decir que es la parte funcional, que se encargara de inicalizar correctamente la ventana.

mainwindow.cpp Se ve a encargar de crar la parte funcional a nuestras las funciones y acciones que previamente habiamos registrado anteriormente en mainwindow.h y ademas, las incluye en los menus de ventana.

Proyectopaint.cpp tiene como objetivo programar toda el area de trabajo con sus respectivos parametros, si el usuario realiza una modificacion ya sea de color o grosor de lapiz, este recibirá esta informacion  y la implementará en el area de trabajo cuando la utilicemos.

//Archivo.ui

Qt Creator nos ofrece la posibilidad de realizar cambios a nustras ventanas a partir de una herramienta de diseño, personalmente no la hemos implementado aun, así que el archivo no contiene informacion importante.
