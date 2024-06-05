import time
import os
import random as r
from funcionesNoRelacionadas import *

def main():
    menu()
    largo = largoTablero()
    tablero = crearMatrizCuadrada(largo)
    i=1
    while not revisarGane(tablero) and not revisarPerdida(tablero):
        print(f"Día {i}")
        turnoDia(tablero) #da las opciones de juego para el usuario
        print("Este es el tablero después de las actividades hechas durante el día.")
        if revisarGane(tablero):
            break
        printTablero(tablero, largo)
        time.sleep(4)
        os.system("clear")
        turnoNoche(tablero) #donde ocurren los ataques de los usurpadores
        i+=1
        os.system("clear")
    
def turnoDia(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Llama a las funciones que se encargan de realizar las actividades del día.
    '''
    revisarIniciativa(tablero) #revisar si hay iniciativas para convertir en proyectos
    decisionDia(tablero) #dar a escoger qué hacer

    
def turnoNoche(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Escoge las casillas que se atacarán y se llama a la función para atacar con esas casillas siendo un parámetro.
    '''
    numAtaques = r.randint(3,len(tablero)) #escoger un numero random para la cantidad de ataques
    ataques = [] #ataques = [[fila,columna],[fila,columna]...]
    for i in range(numAtaques): #escoger numeros random para las posiciones/casillas de los ataques
        fila = r.randint(0,len(tablero)-1)
        columna = r.randint(0,len(tablero)-1)
        ataques += [[fila,columna]]
    ataque(tablero,ataques)

def ataque(tablero,ataques):
    '''
    E: Tiene como parámetros el tablero del juego y una lista con las posiciones de los ataques.
    S: Se hacen los ataques con sus respectivas casos, y luego retorna el tablero
    '''
    listaAtaques = [
        [
            "Los usurpadores destruyen un proyecto comunitario en Cabagra.",
            "Un proyecto fue tomado por los usurpadores, devastando la esperanza local.",
            "Los usurpadores han convertido un proyecto vital en un territorio usurpado.",
            "El proyecto de revitalización de Cabagra ha caído en manos de los usurpadores.",
            "Un proyecto de sostenibilidad clave fue capturado por los enemigos.",
            "Los usurpadores destruyen la infraestructura del proyecto, causando desolación.",
            "Un proyecto de desarrollo se pierde ante el avance enemigo.",
            "Los usurpadores convierten un proyecto ecológico en su fortaleza.",
            "Los enemigos destrozan el proyecto de energía renovable y se apoderan del territorio.",
            "Un valioso proyecto agrícola ha sido usurpado.",
            "Los usurpadores han ganado control sobre un proyecto importante para Cabagra.",
            "El proyecto de educación ha sido transformado en un bastión enemigo.",
            "Un proyecto cultural crucial ha caído bajo el control de los usurpadores.",
            "El proyecto de salud comunitaria fue demolido y convertido en tierra usurpada.",
            "Los enemigos toman el control y destruyen un proyecto vital para Cabagra.",
            "El proyecto de conservación ha sido arrasado por los usurpadores.",
            "Un proyecto de infraestructura ha sido reducido a escombros por los usurpadores.",
            "El proyecto de reforestación ha sido arrebatado por los enemigos.",
            "Los usurpadores convierten el proyecto de vivienda en una zona de control.",
            "El proyecto de agua potable ha sido destruido por los invasores."
        ], # Si es P (Proyecto)

        [
            "Los usurpadores atacaron una iniciativa, pero esta se convertirá en un proyecto.",
            "Una iniciativa fue atacada, pero seguirá avanzando.",
            "Los usurpadores no pudieron detener la iniciativa, mañana será un proyecto.",
            "Una iniciativa de empoderamiento fue blanco de los usurpadores, pero se mantendrá firme.",
            "Los enemigos atacaron una iniciativa cultural, pero se convertirá en un proyecto pronto.",
            "La iniciativa de educación resistió el ataque y se transformará en un proyecto.",
            "Los usurpadores no lograron detener la iniciativa comunitaria.",
            "La iniciativa de salud atacada se convierte en un proyecto mañana.",
            "Una iniciativa de sostenibilidad fue atacada, pero no será detenida.",
            "El ataque a la iniciativa fue inútil, se transformará en un proyecto.",
            "La iniciativa de energía renovable resistió y mañana será un proyecto.",
            "Los usurpadores atacaron, pero la iniciativa de vivienda se convertirá en un proyecto.",
            "El ataque a la iniciativa ecológica no la detendrá.",
            "Una iniciativa agrícola fue atacada sin éxito y se convertirá en un proyecto.",
            "Los usurpadores fallaron al detener la iniciativa de conservación.",
            "El ataque a la iniciativa de agua potable no tuvo éxito.",
            "La iniciativa de revitalización resistió el ataque y mañana será un proyecto.",
            "Los usurpadores no pudieron destruir la iniciativa cultural.",
            "La iniciativa de desarrollo fue atacada, pero seguirá adelante.",
            "Una iniciativa de infraestructura fue atacada, pero se mantendrá firme."
        ], # Si es I (Iniciativa)

        [
            "Los usurpadores atacaron una casilla cultural, borrando su influencia.",
            "La cultura de Cabagra fue suprimida en una casilla.",
            "Un ataque logró eliminar la difusión cultural en una casilla.",
            "La casilla cultural fue atacada y su influencia borrada.",
            "Los enemigos eliminaron la influencia cultural de Cabagra en una casilla.",
            "La casilla cultural fue suprimida por los usurpadores.",
            "La difusión cultural en la casilla fue detenida.",
            "Los usurpadores borraron la cultura indígena en una casilla.",
            "Una casilla cultural fue atacada y suprimida.",
            "La influencia cultural de Cabagra fue eliminada en una casilla.",
            "Los enemigos destruyeron la difusión cultural en una casilla.",
            "La cultura en una casilla fue suprimida por los usurpadores.",
            "La casilla cultural fue borrada por el ataque enemigo.",
            "Los usurpadores atacaron y suprimieron la cultura de Cabagra en una casilla.",
            "La casilla cultural fue destruida.",
            "La influencia cultural en la casilla fue eliminada.",
            "Los enemigos suprimieron la cultura en una casilla.",
            "Una casilla cultural fue atacada y borrada.",
            "La difusión cultural en una casilla fue detenida.",
            "La casilla cultural fue suprimida por los usurpadores."
        ], # Si es C (Cultura)

        [
            "Un territorio vacío fue usurpado.",
            "Los usurpadores han tomado un terreno vacío.",
            "Un espacio de los pueblos originarios ha sido conquistado.",
            "Los usurpadores se han apoderado de un terreno vacío.",
            "Un territorio vacío fue capturado por los usurpadores.",
            "Los usurpadores han usurpado un terreno vacío.",
            "Un espacio vacío ha sido tomado por los enemigos.",
            "Los usurpadores conquistaron un territorio vacío.",
            "Un terreno vacío ha sido usurpado.",
            "Los enemigos han tomado control de un territorio vacío.",
            "Un espacio vacío fue capturado por los usurpadores.",
            "Los usurpadores tomaron un terreno vacío.",
            "Un territorio vacío ha sido usurpado por los enemigos.",
            "Los enemigos capturaron un terreno vacío.",
            "Un espacio vacío fue conquistado por los usurpadores.",
            "Los usurpadores han tomado control de un terreno vacío.",
            "Un territorio vacío fue capturado.",
            "Los enemigos se apoderaron de un terreno vacío.",
            "Un espacio vacío fue usurpado por los enemigos.",
            "Los usurpadores tomaron un territorio vacío."
        ], # Si es ◼ (Vacío)

        [
            "Los usurpadores atacaron de nuevo una casilla usurpada previamente.",
            "Un territorio usurpado fue atacado nuevamente.",
            "Los usurpadores refuerzan su control sobre una casilla previamente tomada.",
            "Una casilla usurpada fue atacada de nuevo por los enemigos.",
            "Los usurpadores consolidan su control en una casilla previamente usurpada.",
            "Un territorio usurpado sufrió otro ataque.",
            "Los enemigos refuerzan su presencia en una casilla usurpada.",
            "La casilla usurpada fue atacada nuevamente por los usurpadores.",
            "Los usurpadores fortalecen su control en una casilla previamente usurpada.",
            "Un territorio previamente usurpado fue atacado otra vez.",
            "Los enemigos refuerzan su control en una casilla usurpada.",
            "La casilla usurpada sufrió otro ataque de los enemigos.",
            "Los usurpadores consolidan su presencia en una casilla previamente tomada.",
            "Una casilla previamente usurpada fue atacada de nuevo.",
            "Los usurpadores fortalecen su control sobre una casilla ya usurpada.",
            "Un territorio usurpado fue atacado nuevamente.",
            "Los enemigos atacaron de nuevo una casilla usurpada previamente.",
            "Los usurpadores refuerzan su control en una casilla usurpada.",
            "Una casilla previamente usurpada fue atacada otra vez.",
            "Los enemigos fortalecen su control en una casilla ya usurpada."
        ] # Si ya había U (Usurpado)
    ]
    
    for i in range(len(ataques)):
        #ataques = [[fila,columna],[fila,columna]...]
        if tablero[ataques[i][0]][ataques[i][1]] == "P":
            print(f"En el ataque {i+1} los usurpadores atacaron un proyecto")
            print(listaAtaques[0][r.randint(0,len(listaAtaques[0])-1)])
            tablero[ataques[i][0]][ataques[i][1]] = "U"
            printTablero(tablero, len(tablero))
            noImporta = input("Inserta cualquier cosa para continuar:")
            
        elif tablero[ataques[i][0]][ataques[i][1]] == "I":
            print(f"En el ataque {i+1} los usurpadores atacaron una iniciativa")
            print(listaAtaques[1][r.randint(0,len(listaAtaques[1])-1)])
            printTablero(tablero, len(tablero))
            noImporta = input("Inserta cualquier cosa para continuar:")
            
        elif tablero[ataques[i][0]][ataques[i][1]] == "C":
            print(f"En el ataque {i+1} los usurpadores atacaron una casilla donde se difundió cultura")
            print(listaAtaques[2][r.randint(0,len(listaAtaques[2])-1)])
            tablero[ataques[i][0]][ataques[i][1]] = "◼"
            printTablero(tablero, len(tablero))
            noImporta = input("Inserta cualquier cosa para continuar:")
            
        elif tablero[ataques[i][0]][ataques[i][1]] == "◼":
            print(f"En el ataque {i+1} los usurpadores atacaron una casilla vacia de los pueblos originarios.")
            print(listaAtaques[3][r.randint(0,len(listaAtaques[3])-1)])
            tablero[ataques[i][0]][ataques[i][1]] = "U"
            printTablero(tablero, len(tablero))
            noImporta = input("Inserta cualquier cosa para continuar:")
            
        else: #otro usurpado
            print(f"En el ataque {i+1} los usurpadores atacaron una casilla que ya había sido usurpada anteriormente.")
            print(listaAtaques[4][r.randint(0,len(listaAtaques[4])-1)])
            printTablero(tablero, len(tablero))
            noImporta = input("Inserta cualquier cosa para continuar:")
            
        os.system("clear")
    
def decisionDia(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Le pregunta al usuario la actividad que quiere hacer ese día, luego llama a su respectiva función
    '''
    printTablero(tablero,len(tablero))
    opcion = input("Qué quieres hacer en este día? Un proyecto, iniciativa o difundir cultura? (P/I/C) \n") #pone al usuario a decidir qué hacer
    if opcion == "P":
        proyecto(tablero)
    elif opcion == "I":
        iniciativa(tablero)
    elif opcion == "C":
        cultura(tablero)	
    else:
        print("No has escogido una opción válida. Vuelve a intentarlo.")
        time.sleep(3)
        os.system("clear")
        decisionDia(tablero)

        
def proyecto(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Le pregunta al usuario donde quiere hacer el proyecto y pone "P" en la casilla.
    '''
    casilla = input("En qué casilla quieres hacer un proyecto? Digita el numero de fila y luego el de la columna. Ejemplo: la posicion de fila (horizontal) 0 con la columna (vertical) 1 sería 01. \n") #posicion en donde se realizará el proyecto
    if not revisarCasilla(casilla,tablero): #es False si hay algún error
        time.sleep(3)
        os.system("clear")
        return proyecto(tablero) 
    fila = int(casilla[0])
    columna = int(casilla[1])
    tablero[fila][columna] = "P"

def iniciativa(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Le pregunta al usuario donde quiere hacer la iniciativa y pone "I" en la casilla.
    '''
    casilla = input("En qué casilla quieres hacer una iniciativa? Digita el numero de fila y luego el de la columna. Ejemplo: la posicion de fila (horizontal) 0 con la columna (vertical) 1 sería 01. \n") #posicion en donde se realizará el proyecto
    if not revisarCasilla(casilla,tablero): #es False si hay algún error
        time.sleep(3)
        os.system("clear")
        return iniciativa(tablero) 
    fila = int(casilla[0])
    columna = int(casilla[1])
    tablero[fila][columna] = "I"
    
def cultura(tablero): #para poner una hilera de cultura
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Le pregunta al usuario la casilla y donde quiere que se expanda la cultura, en vertical u horizontal, luego llama a la función correspondente.
    '''
    casilla = input("En qué casilla quieres empezar a expandir la cultura? Digita el numero de fila y luego el de la columna. Ejemplo: la posicion de fila (horizontal) 0 con la columna (vertical) 1 sería 01. \n") #posicion en donde se iniciará la cultura
    if not revisarCasilla(casilla,tablero): #es False si hay algún error
        time.sleep(3)
        os.system("clear")
        return cultura(tablero) 
    fila = int(casilla[0]) #volver la casilla a numeros enteros
    columna = int(casilla[1])
    tablero[fila][columna] = "C" #poner una C en la casilla a iniciar la cultura
    direccion = input("Quieres expandir la cultura en vertical u horizontal? (v/h) \n") #preguntar hacia donde expandir
    if direccion == "v":
        expansionVertical(tablero,columna, fila)
    elif direccion == "h":
        expansionHorizontal(tablero,columna, fila)    
    else: #errores
        print("No has escogido una opción válida. Vuelve a intentarlo.")
        time.sleep(3)
        os.system("clear")
        return cultura(tablero)


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
    
def revisarGane(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Revisa si hay alguna línea llena del tablero con proyectos, significando que se ganó, y retorna True
    '''
    for i in range(len(tablero)): #revisa si hay alguna fila completa de proyectos
        j=0
        while j <= len(tablero):
            if j == len(tablero):
                print("Ganaste contra los usurpadores, se rindieron de tanto atacar y nunca pudieron adueñarse de una fila entera de terrenos en Cabagra/TU SOLARPUNK. Has recuperado todos tus terrenos. Felicidades! \n") #mensaje de ganar
                print(r"""
                |@@@@|     |####|
                |@@@@|     |####|
                |@@@@|     |####|
                \@@@@|     |####/
                 \@@@|     |###/
                  `@@|_____|##'
                       (O)
                    .-'''''-.
                  .'  * * *  `.
                 :  *       *  :
                 :~W I N N E R~:
                 :  *       *  :
                  `.  * * *  .'
                    `-.....-'
                """)
                return True #Ganó
            if tablero[i][j] != "P":
                break
            j+=1
    
    for i in range(len(tablero[0])): #revisa si hay alguna columna completa de proyectos
        j=0
        while j <= len(tablero):
            if j == len(tablero):
                print("Ganaste contra los usurpadores, se rindieron de tanto atacar y nunca pudieron adueñarse de una fila entera de terrenos en Cabagra/TU SOLARPUNK. Has recuperado todos tus terrenos. Felicidades! \n") #mensaje de ganar
                print(r"""
                |@@@@|     |####|
                |@@@@|     |####|
                |@@@@|     |####|
                \@@@@|     |####/
                 \@@@|     |###/
                  `@@|_____|##'
                       (O)
                    .-'''''-.
                  .'  * * *  `.
                 :  *       *  :
                 :~W I N N E R~:
                 :  *       *  :
                  `.  * * *  .'
                    `-.....-'
                """)
                return True #Ganó
            if tablero[j][i] != "P":
                break
            j+=1

    return False
    
def revisarPerdida(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Revisa si hay alguna línea llena del tablero con tierras usurpadas, significando que se perdió, y retorna True
    '''
    for i in range(len(tablero)):
        j=0
        while j <= len(tablero):
            if j == len(tablero):
                print ("Perdiste :( Los usurpadores han logrado adueñarse de toda una fila de terrenos en Cabagra.")
                print(r"""
                 _______  _______  _______  _______ 
                (  ____ \(  ___  )(       )(  ____ \
                | (    \/| (   ) || () () || (    \/
                | |      | (___) || || || || (__    
                | | ____ |  ___  || |(_)| ||  __)   
                | | \_  )| (   ) || |   | || (      
                | (___) || )   ( || )   ( || (____/\
                (_______)|/     \||/     \|(_______/

                 _______           _______  _______ 
                (  ___  )|\     /|(  ____ \(  ____ )
                | (   ) || )   ( || (    \/| (    )|
                | |   | || |   | || (__    | (____)|
                | |   | |( (   ) )|  __)   |     __)
                | |   | | \ \_/ / | (      | (\ (   
                | (___) |  \   /  | (____/\| ) \ \__
                (_______)   \_/   (_______/|/   \__/

                """)
                return True #Pasó por todo, perdió
            if tablero[i][j] != "U":
                break
            j+=1

    for i in range(len(tablero[0])):
        j=0
        while j <= len(tablero):
            if j == len(tablero):
                return True #Pasó por todo, perdió
            if tablero[j][i] != "U":
                break
            j+=1

    return False

def revisarIniciativa(tablero):
    '''
    E: Tiene como parámetro el tablero de juego.
    S: Revisa si hay alguna iniciativa del día anterior en el tablero, los cambia a proyectos y retorna el tablero actualizado.
    '''
    for i in range(len(tablero)):
        for j in range(len(tablero[0])):
            if tablero[i][j] == "I":
                tablero[i][j] = "P" #al siguiente día las I se convierten en P
    return tablero

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

def menu():
    '''
    E: No tiene parámetros.
    S: Imprime el menú del juego, le pregunta al usuario que opción quiere elegir y llama a la función correspondiente.
    '''
    print("1. Jugar")
    print("2. Ver información sobre Solarpunk")
    print("3. Ver información sobre pueblos originarios")
    print("4. Ver información sobre el conflicto de cabagra")
    print("5. Referencias")
    print("6. Instrucciones del juego\n")

    opcion = input("Qué quieres hacer? [1-6]\n")
    if not esDigito(opcion):
        print("El carácter ingresado no es un número.")
        time.sleep(3)
        os.system("clear")
        return menu()
    opcion = int(opcion)
    os.system("clear")
    if opcion < 1 or opcion > 6: #si ingresa algo que no está entre el rango de opciones
        print("El número ingresado debe ser entre 1 y 6")
        time.sleep(3)
        os.system("clear")
        return menu()
    

    #para que ejecute la opcion que se escoja
    elif opcion == 1: #jugar
        pass
    elif opcion == 2:
        infoSolarpunk()
    elif opcion == 3:
        infoPueblosOriginarios()
    elif opcion == 4:
        infoConflictoCabagra()
    elif opcion == 5:
        infoReferencias()
    elif opcion == 6:
        instrucciones()
    
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
    return menu()
    
def infoSolarpunk(): #info sobre solarpunk
    print("El solarpunk es un movimiento que presenta un futuro sostenible y optimista en el que la humanidad vive en armonía con la naturaleza. Se caracteriza por representar a un mundo utópico. Ejemplos de rasgos que podrían llegar a tener los solarpunks: ciudades impulsadas por energía solar, agricultura urbana y tecnología ecológica avanzada. Caracteristicas esenciales del solarpunk son la tecnología, la naturaleza, la comunidad, la igualdad y la sostenibilidad. \n \nEl término Solarpunk se originó en el 2008, sin embargo, su fama se dio hasta el 2014 con una publicación de Adam Flynn, un investigador de la Universidad Estatal de Arizona que comenzó a visibilizar el movimiento.\n\n") 
    
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")
    return menu()


def infoPueblosOriginarios(): #info sobre pueblos originarios
    print("Los pueblos originarios son comunidades con historias, culturas y tradiciones que han habitado el una región específica durante múltiples años y han contribuido significativamente al patrimonio natural y cultural de la zona. Algunos pueblos originarios en Costa Rica son: Cabécares, Bribris, Ngäbe, Térrabas, Borucas, Huetares, Malekus y Chorotegas. \n \nA pesar de ser quienes han habitado por un gran tiempo el mismo lugar, los pueblos originarios llegan a ser atacados por otros grupos de personas para adueñarse de sus tierras. Además, también enfrentan desafíos de discriminación, pobreza, acceso limitado a la educación y la salud, y luchan por  proteger sus recursos. \n\n")
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")
    return menu()


def infoConflictoCabagra(): #info sobre el conflicto de recuperación de tierras en Cabagra
    print("El conflicto trata sobre la recuperación de tierras en la zona de Cabagra de Buenos Aires, Puntarenas, por parte del pueblo originario de la región. Las tierras que fueron uzurpadas ilegalmente en años anteriores están siendo reclamadas por la comunidad de indígenas, quienes han iniciado con planes para recuperar sus tierras. La recuperación de ese terreno inició en abril del 2021 por parte de la familia Sandí Morales.\n\n El conflicto ha causado numerosas concecuencias negativas para los pueblos originarios. Ya que las personas fuera de la comunidad indígena ha promovido un ambiente de violencia. Este grupo ha realizado amenazas, agresiones físicas y psicologicas, e incluso asesinatos para mantener tierras que no les pertenecían originalmente. \n\nActualmente, se ha discutido la situación entre el pueblo originario, las autoridades y las personas no indígenas, sin embargo, aún no se ha llegado a ningún tipo de acuerdo. \n\n")
    
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")
    return menu()


def infoReferencias(): #referencias en formato apa
    print("Cervera, A. (2023, 22 noviembre). Solarpunk: dibujando un futuro positivo para el planeta. SIMBIOTIA. https://www.simbiotia.com/solarpunk/#:~:text=El%20solarpunk%20es%20un%20movimiento,de%20la%20sociedad%20en%20general. \n \nChavarría, D. (2022, 5 noviembre). Coordinadora de Lucha Sur-Sur cuestiona a Gobierno por pedir detener las recuperaciones de tierras indígenas. Radioemisoras UCR. https://radios.ucr.ac.cr/2022/11/interferencia/destacada/gobierno-detener-recuperaciones-tierras-indigenas/ \n \nPueblos indígenas: Panorama general. (s. f.). World Bank. https://www.bancomundial.org/es/topic/indigenouspeoples#:~:text=Los%20pueblos%20ind%C3%ADgenas%20son%20grupos,los%20cuales%20han%20sido%20desplazados. \n \nTerritorios indígenas sufren la desidia y el olvido de sus compatriotas. (s. f.). Delfino.cr. https://delfino.cr/2023/09/territorios-indigenas-en-el-olvido \n \n")
    
    noImporta = input("Digita algo para volver al menú.")
    os.system("clear")
    return menu()


main()