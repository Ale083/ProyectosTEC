import os
import time
from funcionesNoRelacionadas import *

def infoSolarpunk(): #info sobre solarpunk
    print("El solarpunk es un movimiento que presenta un futuro sostenible y optimista en el que la humanidad vive en armonía con la naturaleza. Se caracteriza por representar a un mundo utópico. Ejemplos de rasgos que podrían llegar a tener los solarpunks: ciudades impulsadas por energía solar, agricultura urbana y tecnología ecológica avanzada. Caracteristicas esenciales del solarpunk son la tecnología, la naturaleza, la comunidad, la igualdad y la sostenibilidad. \n \nEl término Solarpunk se originó en el 2008, sin embargo, su fama se dio hasta el 2014 con una publicación de Adam Flynn, un investigador de la Universidad Estatal de Arizona que comenzó a visibilizar el movimiento.\n\n") 
    
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")


def infoPueblosOriginarios(): #info sobre pueblos originarios
    print("Los pueblos originarios son comunidades con historias, culturas y tradiciones que han habitado el una región específica durante múltiples años y han contribuido significativamente al patrimonio natural y cultural de la zona. Algunos pueblos originarios en Costa Rica son: Cabécares, Bribris, Ngäbe, Térrabas, Borucas, Huetares, Malekus y Chorotegas. \n \nA pesar de ser quienes han habitado por un gran tiempo el mismo lugar, los pueblos originarios llegan a ser atacados por otros grupos de personas para adueñarse de sus tierras. Además, también enfrentan desafíos de discriminación, pobreza, acceso limitado a la educación y la salud, y luchan por  proteger sus recursos. \n\n")
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")


def infoConflictoCabagra(): #info sobre el conflicto de recuperación de tierras en Cabagra
    print("El conflicto trata sobre la recuperación de tierras en la zona de Cabagra de Buenos Aires, Puntarenas, por parte del pueblo originario de la región. Las tierras que fueron uzurpadas ilegalmente en años anteriores están siendo reclamadas por la comunidad de indígenas, quienes han iniciado con planes para recuperar sus tierras. La recuperación de ese terreno inició en abril del 2021 por parte de la familia Sandí Morales.\n\n El conflicto ha causado numerosas concecuencias negativas para los pueblos originarios. Ya que las personas fuera de la comunidad indígena ha promovido un ambiente de violencia. Este grupo ha realizado amenazas, agresiones físicas y psicologicas, e incluso asesinatos para mantener tierras que no les pertenecían originalmente. \n\nActualmente, se ha discutido la situación entre el pueblo originario, las autoridades y las personas no indígenas, sin embargo, aún no se ha llegado a ningún tipo de acuerdo. \n\n")
    
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")



def infoReferencias(): #referencias en formato apa
    print("Cervera, A. (2023, 22 noviembre). Solarpunk: dibujando un futuro positivo para el planeta. SIMBIOTIA. https://www.simbiotia.com/solarpunk/#:~:text=El%20solarpunk%20es%20un%20movimiento,de%20la%20sociedad%20en%20general. \n \nChavarría, D. (2022, 5 noviembre). Coordinadora de Lucha Sur-Sur cuestiona a Gobierno por pedir detener las recuperaciones de tierras indígenas. Radioemisoras UCR. https://radios.ucr.ac.cr/2022/11/interferencia/destacada/gobierno-detener-recuperaciones-tierras-indigenas/ \n \nPueblos indígenas: Panorama general. (s. f.). World Bank. https://www.bancomundial.org/es/topic/indigenouspeoples#:~:text=Los%20pueblos%20ind%C3%ADgenas%20son%20grupos,los%20cuales%20han%20sido%20desplazados. \n \nTerritorios indígenas sufren la desidia y el olvido de sus compatriotas. (s. f.). Delfino.cr. https://delfino.cr/2023/09/territorios-indigenas-en-el-olvido \n \n")
    
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")



def instrucciones():
    print("Bienvenido a el juego PROTEGE A CABAGRA/TU SOLARPUNK. Al iniciciar el juego, tendrás un tablero cuadrado del largo que tu escojas. Dentro de ella, van a haber espacios vacios en donde puedes crear iniciativas, proyectos y difundir la cultura durante el día. \n")
    print("Puedes crear proyectos instantaneamente. También puedes crear iniciativas, las cuales no importa si son atacadas, al siguiente día serán convertidas en proyectos. Además, puedes difundir la cultura desde cualquier casilla, y se expanderá en toda la hilera, horizontal o vertical, hasta chocar con un borde, un proyecto/iniciativa o si choca con un territorio usurpado, devuelve esa territorio a la comunidad de Cabagra, y para de difundir la cultura ahí.\n")
    print("Durante la noche, serás atacado por personas usurpadoras que van a conquistar las tierras de Cabagra. Atacarán entre [3 y el largo del tablero] territorios al día. Si atacan una iniciativa, no pasará nada y se convertirá en un proyecto al siguiente día de todas formas. Si atacan un proyecto, se convertirá en un territorio usurpado. Si atacan un territorio donde se difundió la cultura, tendrán que suprimir esta cultura antes de poder conquistarla, entonces se convierte en un territorio en blanco. \n")
    print("Ganarás si consigues una línea vertical u horizontal de proyectos. Sin embargo, si los uzurpadores logran obtener una hilera completa de terrenos, perderás.\n") 
    print ("Suerte en tu aventura, y que la fuerza de Cabagra te acompañe.\n")
    print(r'''
                       ***          ***                     
                    ***....**     **...***                  
                   **........** **.......**                 
            ***    **..........*.........**    ***
         **.....**  **..................**  **.....**
       **.........**  **..............**  **.........**
      *..............*   *..........*   *..............*
       **..............*   *......*   *..............**
         **..............** *....* **..............**
           *......................................*
         **..............**........**..............**
       **..............*    *....*....*..............**
      *..............*    *........* ...*..............*
       **.........**    *............* ...**.........**
         **.....**   **...............**....**.....**
            ***    **...................**.....***
                 **...........*...........**....*
                  **.........* *.........** 
                    *......**   **......*     
                      **  *       * **        
      ''')
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")
    
def largoTablero():
    '''
    E: No tiene parámetros
    S: Pregunta que tamaño quiere que sea el tablero, valida el número y retorna el valor.
    '''
    largo = input(
        "De qué tamaño quieres que sea el tablero? Ten en cuenta que será un tablero cuadrado, tendrá la misma cantidad de filas que de columnas. También, ten en cuenta que entre más pequeño el tablero, más dificil será de ganar el juego. [3-10]\n"
    )
    if not esDigito(largo):
        print("El carácter ingresado no es un número.")
        time.sleep(3)
        os.system("clear")
        return largoTablero()
    largo = int(largo)
    if largo < 3 or largo > 10:
        print("El número ingresado debe ser entre 3 y 10")
        time.sleep(3)
        os.system("clear")
        return largoTablero()
    return largo


def printTablero(tablero, largo):
    '''
    E: Tiene como parámetros el tablero y el largo del tablero.
    S: Imprime el tablero de una forma ordenada y fácil de entender al usuario.
    '''
    rojo = '\033[31m'
    verde = '\033[92m'
    amarillo = '\033[93m'
    azulito = '\033[94m'
    reset = '\033[0m'
    
    for k in range(largo):
        print(f"  {k}  ", end="") #para numerar las columnas
    print()
    for k in range(largo):
        print("-----", end="")
    print("-")
    for i in range(len(tablero)):
        for j in tablero[i]:
            print("|", end=" ")
            #ponerle color a las actividades sucedidas
            if j == "U":
                print(rojo + j +reset, end="  ")
            elif j == "P":
                print(verde + j +reset, end="  ")
            elif j == "I":
                print(amarillo + j +reset, end="  ")
            elif j == "C":
                print(azulito + j +reset, end="  ")
            else:
                print(j, end="  ")
        print(f"| {i}") #termina el tablero a la derecha y numera las filas
        print("-", end="")
        for k in range(largo):
            print("-----", end="")
        print()


def revisarCasilla(casilla,tablero): #revisa las restricciones que debe tener la posición de la casilla
    '''
    E: Tiene como parámetros la "casilla" y el tablero.
    S: Revisa si es una casilla válida según las reglas del juego, retorna True si es válida, False si no lo es.
    '''
    if not esDigito(casilla):
        print("No has escogido una opción válida. Vuelve a intentarlo.")
        return False
    fila = int(casilla[0])
    columna = int(casilla[1])
    if fila >= len(tablero) or columna >= len(tablero):
        print("Uno o ambos valores se exceden del largo del tablero. Vuelve a intentarlo.")
        return False #si se sale de los parámentros
    return True #sí cumple con las restricciones


def expansionVertical(tablero,columna,fila): #para expandir la cultura vertivalmente
    '''
    E: Tiene como parámetros el tablero, y la columna y fila de la casilla donde se iniciará la cultura.
    S: Pone "C" en las casillas y cambia el tablero siguiendo las reglas, retorna el tablero actualizado.
    '''
    i=fila-1
    while i >=0:
        if tablero[i][columna] == "◼":
            tablero[i][columna] = "C"
        elif tablero[i][columna] == "P" or tablero[i][columna] == "I" or tablero[i][columna] == "C":
            break #si se topa con algo, para
        else: #territorio usurpado
            tablero[i][columna] = "◼" #se devuelve a los pueblos originarios
            break
        i-=1 #sigue para arriba
        
    i=fila+1
    while i < len(tablero):
        if tablero[i][columna] == "◼":
            tablero[i][columna] = "C"
        elif tablero[i][columna] == "P" or tablero[i][columna] == "I" or tablero[i][columna] == "C":
            break #si se topa con algo, para
        else: #territorio usurpado
            tablero[i][columna] = "◼" #se devuelve a los pueblos originarios
            break
        i+=1 #sigue para abajo

def expansionHorizontal(tablero,columna,fila): #para expandir la cultura horizontalmente
    '''
    E: Tiene como parámetros el tablero, y la columna y fila de la casilla donde se iniciará la cultura.
    S: Pone "C" en las casillas y cambia el tablero siguiendo las reglas, retorna el tablero actualizado.
    '''
    i=columna-1
    while i >=0:
        if tablero[fila][i] == "◼":
            tablero[fila][i] = "C"
        elif tablero[fila][i] == "P" or tablero[fila][i] == "I" or tablero[fila][i] == "C":
            break #si se topa con algo, para
        else: #territorio usurpado
            tablero[fila][i] = "◼" #se devuelve a los pueblos originarios
            break
        i-=1 #sigue para la izquierda

    i=columna+1
    while i < len(tablero):
        if tablero[fila][i] == "◼":
            tablero[fila][i] = "C"
        elif tablero[fila][i] == "P" or tablero[fila][i] == "I" or tablero[fila][i] == "C":
            break #si se topa con algo, para
        else: #territorio usurpado
            tablero[fila][i] = "◼" #se devuelve a los pueblos originarios
            break
        i+=1 #sigue para la derecha
        