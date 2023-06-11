# EDA2_GameHub




DATA STRUCTURES AND ALGORITHMS II, 2022-2023



GAMEHUB





Martí Esquius Arnau (u213923 / NIA: 267444)

Alex de la Haya (u214576 / NIA: 268693 )

Roman Atanasiu(u213937 / NIA: 267839)



# PROJECT REPORT GAMEHUB
# TABLA DE CONTENIDO:

# 1.Introducción
# 2.Objetivos del proyecto
2.1 Lista

2.2 Cola

2.3 Stack

2.4 Linear Search

2.5 Diccionario

2.6 File/CSV

2.7 Interfaz visual

# 3.Solución
# 4.Tratamiento de Errores
# 5.Data model design
# 6.Dataset descripción y procesamiento
# 7.Referencias

		


# 1. INTRODUCCIÓN

A los tres integrantes del grupo nos apasionan los videojuegos y por tanto hemos querido hacer un foro en donde los gamers de todos los juegos, puedan compartir sus experiencias e interaccionar con los demás usuarios/amigos de la plataforma. También somos amantes de los retos y por eso hemos decidido llevar este proyecto un paso más allá al incorporar una interfaz visual que dista mucho de ser primitiva ya que incorpora una paleta de colores frescos y vivos. Hemos trabajado mucho para sacar este proyecto adelante pero una vez terminado, el producto final ha resultado ser mucho mejor de lo esperado.

Tenemos la sensación de que en el campo de los videojuegos se está perdiendo el sentimiento de comunidad y esto es lo que deseamos recuperar. GameHub es el foro que estás buscando, en donde todos los forofos de tu videojuego favorito comparten novedades y se divierten junto a sus hermanos virtuales. 

¡Únete ya!

Equipo de desarrollo de GameHub.












# 2. OBJETIVOS DEL PROYECTO
# 2.1 Lista
fichero main.h líneas 24-38

typedef struct _User{
    char name[MAX_LENGTH];
    char user[MAX_LENGTH];
    char password[MAX_LENGTH];
    int age;
    char email [MAX_LENGTH];
    char city [MAX_LENGTH];
    char hobbies  [MAX_HOBBIES][MAX_LENGTH];
    Publicacion* publicacion;
    struct _User* next;
    struct _Queue* friend_request;
    int numfriends;
    int maxfriends;
    struct _User** friends; //dynamic list of pointers of User
} User;

La lista principal del código es una lista enlazada de usuarios, una lista donde se guardan todos los usuarios registrados. Esta lista solo tiene un enlace hacia el siguiente usuario. A esta lista se le añaden User’s al principio de ella, función de tiempo esperado O(1) ya que no se tiene que recorrer la lista, eso sí, si queremos acceder a los usuarios más antiguos, será relativamente costoso, ya que no está doblemente enlazada y se tardará bastante en encontrar los usuarios más antiguos. Si bien la lista fue fácil de implementar, estuvimos más tiempo del deseado para la función que añade usuarios a la lista, ya que al principio intentábamos poner los usuarios al final de la lista, siendo más costoso y difícil de implementar.



# 2.2 Cola 
fichero fichero main.h líneas 40-49
typedef struct _element{
    User* user;
    struct _element* next;
    struct _element* prev;
}Element;

typedef struct _Queue{
    Element* first;
    Element* last;
} Queue;

Hemos implementado una cola (queue) doblemente enlazada en donde podemos tenemos un puntero que apunta al primer elemento y otro al final. Cada elemento contiene un usuario y dos punteros uno nos lleva al usuario anterior y otro al posterior.
Esta cola sirve para las peticiones de amistad que tiene cada usuario. Cada vez que manda 1 a alguien, se actualiza la cola de ese alguien con una nueva petición al final, y ese alguien acepta de 1 en 1 las primeras peticiones de amistad recibidas.
Este tipo de lista es un poco más costosa de implementar pero la ventaja es que la podemos recorrer en ambos sentidos (aún así la notación BIG O sigue siendo la misma, ‘n’), y además es dinámica, así que se pueden añadir ilimitados elementos. Añadir o quitar un elemento (siguiendo los principios de una cola, es decir, añadimos un elemento en la última posición y quitamos un elemento de la primera posición) tiene una notación BIG O de ‘1’. Podemos encontrar esta estructura en el main.h y hemos tardado un poco más que en la lista ya que este tipo de cola tiene un grado de complejidad un poco mayor al implementarse.







# 2.3 Stack

Para implementar el stack hemos usado la estructura de las publicaciones y hemos añadido una funcionalidad extra con ellas, borrar la última, es decir, hacer un GetTop para después hacer un Pop.

Podríamos haber utilizado otra estrategia para eliminar una publicación, pero usando las características propias de las funciones asociadas a los stack (sacando un puntero de top y usando pop) hemos sido capaces de eliminar concretamente la última.

La complejidad esperada del algoritmo es de Big O (n) ya que para sacar el top debemos ir siguiendo cada una de las publicaciones. Podriamos haber hecho un puntero propio del top para reutilizarlo en cada eliminación de post, de acuerdo con los principios básicos de la Programación Dinámica.

# 2.4 Linear search
fichero user functions.c, líneas 10-20
User* find_user(char* user, User* list){
    while (list != NULL){
        //recorremos la lista hasta el final
        if (strcmp(user,list->user)==0){
            //nombre = usuario  (lo hemos encontrado)
            return list;
        }
        list = list->next;     // si no pasamos al siguiente
    }
    return NULL;     //no ha habido suerte/ list vacía
}

Hemos implementado una búsqueda lineal en la función find user(); que es una función que dada un la lista enlazada de users, ya que como no hay forma de ordenar los usuarios ni es un array con posiciones definidas, era imposible hacer una búsqueda binaria. Esta función busca un string dado, y si este existe en la lista de users, y devuelve el usuario en cuestión. Tiene una complejidad temporal de O(n).

# 2.5 Diccionario (diccionario.c y diccionario.h)

*Estructura diccionario (main.h)

Inicializamos el diccionario reservando espacio manualmente. La cantidad de ítems que hay va dictaminada por el tamaño del diccionario (size) y count es el factor de carga. Luego cada ítem contiene su llave y la cantidad de veces que se ha usado esta palabra. 

*Función hash (hash_function)

Para pasar de una palabra a una valor numérico recurrimos a esta función hash. Consiste en transformar la cadena de texto en una función polinomial haciendo uso de su valor numérico en la codificación ascii.
ej. h(“abc”) = ascii(“a”)^2 + ascii(“b”)^1 + ascii(“c”)^0
Posteriormente aplicamos la función mod (residuo división) sobre el valor para no sobrepasar los límites del diccionario.

*Resolución de colisiones(add_item)

Cada vez que añadimos un ítem lo pasamos por nuestra función hash. Si hay colisiones utilizamos la estrategia de linear probing en donde sumamos +1 a la posición hasta que encontramos un hueco. Podríamos haber usado una estrategia más optimizada a la hora de resolver colisiones (la actual puede llegar a provocar clusters y ser ineficiente). La gestión de errores la hacemos en new_post (hace resize al diccionario si su factor de carga va a ser mayor del 75% una vez añadida la nueva palabra). 

*Top 10 (top_10)

Para hacer el top 10 la primera entrada entrada del diccionario [0] es ‘.None.’. Nuestro top inicialmente contiene todo ‘.None.’. A medida que vamos recorriendo la lista añadimos los ítems que han sido utilizados más veces. Como ordenar los 10 elementos más grandes, hemos decidido implementar un BubbleSort, ya que si bien es más ineficiente que otros algoritmos, al solo tener que ordenar 10 nos ha parecido el algoritmo más conveniente a implementar. El top 10 se actualiza a cada publicación y sale tanto en consola (706-713 main.c) como en la interfaz gráfica. El elemento ‘.None.’ se ignora a la hora de imprimir. La BIG O de este algoritmo es de ‘n’ (es negligido el segundo ‘for’ que es de 10 iteraciones). 

*Tiempo

Hemos tardado más de lo esperado en completar nuestro diccionario. Tuvimos que retocar un par de veces el algoritmo que hacía el top 10. Nuestro primer approach fue crear un array lleno de -1 (posición vacía). Posteriormente dábamos valores iniciales válidos al array (entre 0 y size que contengan una palabra) con la función setup_top. Y por último usábamos la función top_10. El problema es que los valores iniciales válidos interfieren con el top. Es por eso que tuvimos que cambiar de estrategia.

# 2.6 File /Csv

Para realizar la incorporación del fichero hemos creado una carpeta llamada resources y dentro hemos puesto nuestro nuevo archivo .txt. Las funciones que hemos utilizado para leerlo han sido: fscanf,fopen y fclose. 
El algoritmo se encuentra entre las líneas 64 y 68 de main.c y requiere la existencia de user_list dentro de la carpeta ‘resources’.
Le hemos dado el mismo tratamiento a los usuarios del archivo que a los que registramos manualmente, ya que así somos capaces de iniciar sesión con una cuenta sin necesidad de crearla.
Hemos usado un algoritmo para sacar a los usuarios del archivo .txt y la complejidad esperada es de Big O(n).
Las variables que hemos usado han sido los diferentes componentes de new_user y los hemos ido añadiendo a nuestra lista de usuarios usando add_user to_list.

*Tiempo

Hemos dedicado algo de tiempo a la creación del archivo con los 20 usuarios iniciales pero la implementación en el main no ha sido muy exigente en este sentido. La modificación del CMakeLists.txt fue algo complicada porque para nosotros es un archivo complejo y delicado. Pero terminamos sacando la solución. 
El tiempo total del Objetivo Deseable fue de aproximadamente 4 horas de trabajo.


*Posibles mejoras

Como posibles mejoras del algoritmo creemos que en el archivo deberíamos utilizar “,” o “.” para separar las palabras. 
En nuestro caso actual la separación se realiza con el carácter “ “, eso tiene limitaciones como que no podemos añadir un juego de 3 palabras para un usuario como sí podemos hacer en la pestaña de registro y nos tenemos que limitar a usar siglas.


# 2.7 Interfaz Visual (main.c, visual_functions.c y visual_functions.h)

Win Api (biblioteca pública de windows)
Para poder usar una interfaz visual como base de nuestro programa hemos tenido que dedicar todo el main.c a las líneas de código relacionadas con esa interfaz. Además, para funciones concretas como las relacionadas con los errores de todo tipo (contraseña, email, falta de valores para registro, nombre de usuario no encontrado…), publicaciones, listas.. nos dimos cuenta de que estaría bien dedicar otros archivos .c y .h a esta finalidad.

*Main.c (Interfaz Visual)

#include:

Para entender el funcionamiento del programa, debemos empezar con los #include. En nuestro caso, debemos incluir las bibliotecas de Windows destinadas a la interfaz.

También vamos a incluir stdio.h para poder complementar la interfaz con la consola, la finalidad es utilizar sobre todo la función printf() que incluye la biblioteca, esto nos va a permitir hacer un seguimiento del estado del programa con la consola.

Finalmente debemos incluir los demás archivos .h, que incluyen las declaraciones de funciones y estructuras que vamos a implementar en nuestro programa.


NOTA: Nos hemos dado cuenta de que hay que incluir los archivos .h con declaraciones de las funciones que definimos en archivos .c, de incluir directamente los archivos .c el programa no funciona correctamente.

En general, para los demás archivos del programa nos hemos limitado a incluir y, en algún caso particular como seria queue_functions.c hemos incluido también un archivo .h correspondiente a, en ese caso, user_functions.


*WinMain (función main de nuestro programa)

Para poder crear un programa en WinApi usando C debemos usar la función principal de toda App de Windows: WinMain.
En ella creamos la ventana y procesamos los mensajes que nos llegan del usuario. 
Aún así, la función más importante no es WinMain sino WndProc. Dentro de esta última vamos a gestionar un switch con 
WM_CREATE: Todos los elementos que queremos se crean aquí.
WM_PAINT: Todo lo relacionado con texto, fuentes y fondos se gestiona aquí.
WM_COMMAND: La interacción con los elementos (botones principalmente) es recogida en esta parte del programa, y tiene unas implicaciones concretas en otras partes.
WM_DESTROY: Antes de finalizar la ejecución siempre vamos a pasar por esta parte del código, es el sitio ideal para hacer free de las estructuras dinámicas de nuestro programa.

*visual_functions.c

Dentro de esta parte del programa hacemos los mensajes que mostramos muchas veces por pantalla. Algunas más remarcables son el menú de usuario y el listado de usuarios.
Debemos considerar también los mensajes de error, uno de los puntos en los que más se ha notado es el hecho de que no podíamos enviar mensajes de diagnóstico con facilidad.

*Variables

Las variables asociadas a este objetivo son todas las variables globales, que han de ser globales para poder ser compatibles con la interfaz de usuario. Aún así, no todas són usadas únicamente con finalidades visuales, las principales y destinadas exclusivamente a ello són todas las de tipo HWND, botones y Edit Controls(espacio donde el usuario introduce texto).
Debemos también remarcar la variable global ‘i’, esta es la encargada de permitir cambiar el WM_PAINT y adaptarlo a las necesidades del estado de la ventana.

*Tiempo y Contratiempos

Hemos tardado mucho más de lo que podíamos imaginar en un primer momento, el hecho de querer hacer una interfaz ha significado que hemos tenido que incurrir en la creación de un gran número de variables globales, hemos descubierto que la capacidad de carga de la interfaz no siempre es suficiente y que el código es muy pesado con más de 1300 líneas de código totales dedicadas ÍNTEGRAMENTE a la interfaz.

En tiempo, el hecho de no solo querer hacer una interfaz sinó querer hacer una moderna y visualmente agradable ha sido de, como mínimo, unas 30 horas de trabajo, incluyendo documentación, pruebas iniciales y modificaciones y adaptaciones. 
Aún así, estamos muy orgullosos del resultado final.

*Posibles mejoras

Como posible mejora nos gustaría implementar la interfaz en otro soporte. El proceso de creación de la interfaz ha sido muy complejo.
Tenemos la sospecha de que podríamos haber reducido un poco el número de variables globales, esto hubiera supuesto una mejora del proyecto pero desconocemos cómo hacerlo.
También hemos sido limitados por la velocidad y capacidad de procesamiento de mensajes de CLion y WinApi, al dar muchas órdenes y cambiar mucho el msg de la ventana puede llegar a congelarse.
La conclusión a la que hemos llegado es que C no es un lenguaje de programación orientado a interfaces, como mínimo en la versión que usamos. También pensamos que las funciones de Windows tienen una capacidad bastante pobre y que para hacer interfaces visuales vamos a usar otras herramientas a partir de ahora.

# 3 SOLUCIÓN

Nuestro proyecto final tiene los siguientes archivos:
 - main.c
	Destinado a la interfaz y la interacción con el usuario.
 - main.h
	Definición de todas las estructuras
 - dictionary.c
	Podemos encontrar todo lo relacionado con el diccionario y publicaciones
 - dictionary.h
	Declaración de funciones
 - services.c
	Funciones auxiliares que nos sirven de soporte en otras partes del código.
 - services.h
	Declaración de funciones
 - user_functions.c
	Podemos encontrar todo lo relacionado con el usuario
 - user_functions.h
	Declaración de funciones
 - queue_functions.c
	Funciones relacionadas con el flujo y manejo de peticiones de amistad
 - queue_functions.h
	Declaración de funciones
 - visual_functions.c
	Funciones de dibujo relacionadas con la interfaz
 - visual_functions.h
	Declaración de funciones

La estructura principal del programa es la de User, está almacena los datos personales de cada usuario. Pero no solo eso, es importante tener en cuenta que estas también almacenan punteros tanto para las publicaciones como para las amistades.

Primero las publicaciones, cada User tiene una lista dinámica de publicaciones, y cada vez que se hace 1 publicación se añade al final de esta lista.
Luego están las peticiones de amistad (las peticiones son las que recibe el usuario, no las que envía), que es un puntero a una cola con el puntero del User que nos ha enviado la petición.

Por último están las amistades. Són un array dinámico de puntero de users de los amigos. Cada vez que aceptamos una petición de amistad, esta se borra de la cola, y pasa a estar el puntero del User que somos amigos en su array dinámico y el suyo en el “nuestro”.

Con las publicaciones usamos las propiedades del stack para tratar con ellas, es decir, para mostrarlas. Al añadir una nueva publicación hacemos que la anterior del autor apunte a la nueva, y posteriormente definimos un puntero ‘top’.

# 4. TRATAMIENTO DE ERRORES 
La mayoría de los posibles errores lo hemos gestionado de esta manera. La función devuelve ‘0’ o ‘1’ dependiendo de si ha sido ejecutada con éxito. Luego fuera del main dependiendo del resultado tomamos cartas en el asunto. Si todo ha ido con normalidad seguimos ejecutando las líneas posteriores de código. En el caso de que haya ido mal podemos llamar otra vez a esta función o llamar a otra función alternativa.




En este caso gestionamos los errores de manera preventiva. Si el diccionario va a estar lleno (capacidad mayor o igual al setenta y cinco por ciento) al incluir la siguiente publicación lo ampliamos y así disminuimos el número de colisiones.



Los errores han sido tratados individualmente, y los mensajes están en visual_functions.c.
Aún así, para el control de algunos errores específicos hemos añadido algunas funciones que vale la pena mencionar:
validar_email: Función de services.c que comprueba que el email que estamos registrando termine con “@gmail.com”, hemos hecho esto para preparar nuestro programa para una posible futura colaboración con una pagina de mail.

are_friends: Función en queue_functions.c que comprueba que, al enviar una solicitud de amistad, no se la estemos enviando a un amigo.
friend_request_already: Función de queue_functions.c que comprueba que no estemos enviando 2 veces una solicitud de amistad al mismo usuario.
find_user: Función de user_functions.c, esta función busca un usuario recibiendo su nombre, si no existe retorna NULL. Usando un if y llamando a print_screen_error6 (visual_functions.c) podemos saber si estamos enviando un mensaje a un usuario existente.

log_in_data: Función de user_functions.c que nos permite saber si el usuario y la contraseña es correcto al iniciar sesión. También nos permite detectar errores.
En combinación con estas funciones usaremos las funciones de visual_functions.c para poder diagnosticar estos y otros errores tales como la falta de parámetros en el registro de usuario.


# 5. DATA MODEL DESIGN

El programa general tiene 4 variables importantes, 3 de ellas son para usuarios, y la otra es un diccionario.

La primera es la list_of_users, una lista enlazada de punteros de users, que es la estructura principal donde se almacenan todos los usuarios registrados en la página web. Al principio es un puntero que apunta a NULL, pero a medida que se añaden usuarios cambia, pero este siempre apuntará al primer Usuario de la lista. 
Vamos a aplicar las funcionalidades propias de una cola para hacer impresiones de usuarios.

Otra variable importante es newUser, este es el usuario al que rellenamos los datos al crear una cuenta manualmente desde el registro de nuevo usuario, y al final se añade a la lista de usuarios.

Otra current_user, que es un puntero de un User. Cuando iniciemos sesión cambiaremos la dirección al puntero del usuario iniciado, y las diferentes funciones tomarán este valor como parámetro, para saber que es él el que está siendo modificado/accedido.

La última es dict, un DICT que sirve para ver el top 10 de tendencias(palabras más usadas).

# 6. DESCRIPCIÓN Y PROCESAMIENTO DE DATASET

NOTA: La imagen del diagrama está subida al GitHub, para que sea más agradable a la vista. La versón en pdf tiene más calidad

Este es un diagrama de flujo del programa, cabe destacar que el programa tiene siempre una opción de “back”, que siempre nos lleva al proceso anterior. 

Si bien el main es un poco caótico por las funciones visuales, el comportamiento del programa es este. Cabe destacar que cada vez que imprimimos un nuevo menú los botones anteriores se ocultan para mostrar el nuevo menú.




# 7. REFERENCIAS 

Cuando nos hemos estancado hemos recurrido a diversos foros:
Stack Overflow - Where Developers Learn, Share, & Build Careers. (s. f.). Stack Overflow.
https://stackoverflow.com/

Aprender Lenguaje de Programación C. (s. f.). Diseño Web akus.net.
https://disenowebakus.net/aprender-programacion-c.php

Aprender WinApi, en general algunos de los capítulos de esta serie de Dave++ han sido
útiles para entender el funcionamiento de la interfaz.
https://www.youtube.com/watch?v=L-_3onUzZ8Y

Los videos de Michael Sambol nos han ayudado a comprender cómo funcionan los distintos
algoritmos de ordenación / búsqueda.
Before you continue to YouTube. (s. f.). https://www.youtube.com/@MichaelSambol

La página web de geeks for geeks ha sido de gran ayuda, sobre todo para la cola, ya que
tuvimos muchas dudas de cómo implementar una cola dinámica.

GeeksforGeeks. (2023). Different Types of Queues and its Applications. GeeksforGeeks.
https://www.geeksforgeeks.org/different-types-of-queues-and-its-applications/

La IA Chat GPT ha sido útil sobretodo para buscar errores en nuestro programa, nos ha
facilitado bastante la tarea de gestión de errores.
https://openai.com/chatgpt

Aún con todas las fuentes mencionadas posteriormente los apuntes que los integrantes
hemos tomado en las clases de teoria han sido nuestro mejor soporte en la creación de este
proyecto


