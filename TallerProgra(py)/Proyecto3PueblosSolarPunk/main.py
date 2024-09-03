import time
import os
import random as r
from funcionesNoRelacionadas import *
from Auxiliar import *

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
        return menu()
    elif opcion == 3:
        infoPueblosOriginarios()
        return menu()
    elif opcion == 4:
        infoConflictoCabagra()
        return menu()
    elif opcion == 5:
        infoReferencias()
        return menu()
    elif opcion == 6:
        instrucciones()
        return menu()

def turnoDia(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Llama a las funciones que se encargan de realizar las actividades del día.
    '''
    revisarIniciativa(tablero) #revisar si hay iniciativas para convertir en proyectos
    decisionDia(tablero) #dar a escoger qué hacer


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
            noImporta = input("Presiona enter para continuar")
            
        elif tablero[ataques[i][0]][ataques[i][1]] == "I":
            print(f"En el ataque {i+1} los usurpadores atacaron una iniciativa")
            print(listaAtaques[1][r.randint(0,len(listaAtaques[1])-1)])
            printTablero(tablero, len(tablero))
            noImporta = input("Presiona enter para continuar")
            
        elif tablero[ataques[i][0]][ataques[i][1]] == "C":
            print(f"En el ataque {i+1} los usurpadores atacaron una casilla donde se difundió cultura")
            print(listaAtaques[2][r.randint(0,len(listaAtaques[2])-1)])
            tablero[ataques[i][0]][ataques[i][1]] = "◼"
            printTablero(tablero, len(tablero))
            noImporta = input("Presiona enter para continuar")
            
        elif tablero[ataques[i][0]][ataques[i][1]] == "◼":
            print(f"En el ataque {i+1} los usurpadores atacaron una casilla vacia de los pueblos originarios.")
            print(listaAtaques[3][r.randint(0,len(listaAtaques[3])-1)])
            tablero[ataques[i][0]][ataques[i][1]] = "U"
            printTablero(tablero, len(tablero))
            noImporta = input("Presiona enter para continuar")
            
        else: #otro usurpado
            print(f"En el ataque {i+1} los usurpadores atacaron una casilla que ya había sido usurpada anteriormente.")
            print(listaAtaques[4][r.randint(0,len(listaAtaques[4])-1)])
            printTablero(tablero, len(tablero))
            noImporta = input("Presiona enter para continuar")
            
        os.system("clear")
    
    
def revisarGane(tablero):
    '''
    E: Tiene como parámetro el tablero del juego.
    S: Revisa si hay alguna línea llena del tablero con proyectos, significando que se ganó, y retorna True
    '''
    for i in range(len(tablero)): #revisa si hay alguna fila completa de proyectos
        j=0
        while j <= len(tablero):
            if j == len(tablero):
                printTablero(tablero, len(tablero))
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
                printTablero(tablero, len(tablero))
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
                printTablero(tablero, len(tablero))
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
                printTablero(tablero, len(tablero))
                print ("Perdiste :( Los usurpadores han logrado adueñarse de toda una columna de terrenos en Cabagra.")
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
            if tablero[j][i] != "U":
                break
            j+=1

    return False






    




main()