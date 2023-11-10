***************************************************************************************************
*                                                                                                 *
*                                           README.txt                                            *
*                                                                                                 *
*                W         w EEEEE  BBBB   SSSS  EEEEE  RRRR  V   V  EEEEE  RRRR                  *
*                 W       w  E      B   B  S     E      R   R V   V  E      R   R                 *
*                  W  W  w   EEEE   BBBB   SSSS  EEEE   RRRR   V V   EEEE   RRRR                  *
*                   W W w    E      B   B     S  E      R R     V    E      R R                   *
*                    W w     EEEEE  BBBB   SSSS  EEEEE  R  RR   V    EEEEE  R  RR                 *
*                                                                                                 *
*                                 URDULIZ_42 - @sULTANSoFtECH!!!                                  *
*                                                                                                 *
***************************************************************************************************
                                      
                                      © [2023] [@SultansOfTech (@cbustama / @ualcibar / @pojea-lo)]


ES -

Texto explicativo con los requisitos básicos que ha de cumplir el archivo de configuración y otra
serie de normas para la correcta ejecución del programa.

    - Para ejecutar el programa, se ha de realizar make y ejecutar con ./webserv
    - El número de argumentos para la función será de 2
    - El segundo argumento es el archivo de configuración, que ha de tener extensión .conf
    - No se podrán realizar subidas de archivos con body size > 2 MB
    - Las páginas de error han de estar situadas en /src/errorPages
    - No se permite la existencia de puertos duplicados en diferentes servidores
    - Serán puertos válidos los comprendidos entre el 2 - 65535 incluídos
    - Respecto al archivo de configuración:
        *Todos los scopes han de estar precedidos por la palabra 'server'
        *Todas las lineas han de ser terminadas por ';'
        *No se podrá iniciar ningún servidor sin unos datos mínimos, como son:
            ºServer name
            ºHostname
            ºPuerto o puertos
        *Todas las location deberán llevar su path correspondiente
        *Quedan prohibidos los siguientes paths para las locations:
            º /default
            º /login
            º /logout
            º /dologout
            º /errorPages
        *Las ruta para las carpetas de upload han de comenzar por '/'

EN -

Explanatory text with the basic requirements that the configuration file must meet and other
series of rules for the correct execution of the program.

    - To run the program, make must be performed and executed with ./webserv
    - The number of arguments for the function will be 2
    - The second argument is the configuration file, which must have a .conf extension
    - File uploads with body size > 2 MB will not be possible
    - Error pages must be located in /src/errorPages
    - The existence of duplicate ports on different servers is not allowed
    - Valid ports will be those between 2 - 65535 included.
    - Regarding the configuration file:
        *All scopes must be preceded by the word 'server'
        *All lines must be ended by ';'
        *No server can be started without minimum data, such as:
            ºServer name
            ºHostname
            ºPort or ports
        *All locations must have their corresponding path
        *The following paths are prohibited for locations:
            º /default
            º /login
            º /logout
            º /dologout
            º /errorPages
        *The paths for the upload folders must begin with '/'

EU -

Konfigurazio-artxiboak bete behar dituen oinarrizko baldintzak azaltzen dituen testua eta beste bat
Programa behar bezala gauzatzeko arauak.

    - Programa exekutatzeko, make egin behar da eta webserv bidez exekutatu.
    - Funtziorako argudio-kopurua 2 izango da
    - Bigarren argudioa konfigurazio-fitxategia da, eta horrek luzapena izan behar du .conf
    - Ezingo da fitxategirik igo body size > 2 MB erabiliz.
    - Errore-orriek hemen egon behar dute:/src/errorPages
    - Hainbat zerbitzaritan ezin da portu bikoizturik egon.
    - Portu baliodunak izango dira 2-65535 artekoak, biak barne.
    - Konfigurazio-artxiboari dagokionez:
        *Skope guztien aurretik "server" hitza jarri behar da.
        *Lerro guztiak honela amaitu behar dira: ';'
        *Ezin izango da zerbitzaririk abiarazi gutxieneko datu batzuk izan gabe, hala nola:
            ºServer name
            ºHostname
            ºPortua edo portuak
        *Lokalizazio guztiek dagokien path-a eraman beharko dute
        *Debekatuta daude locations direlakoetarako paths hauek:
            º /default
            º /login
            º /logout
            º /dologout
            º /erroreaPages
        *Upload karpetentzako ibilbidea '/' tik hasi behar da.