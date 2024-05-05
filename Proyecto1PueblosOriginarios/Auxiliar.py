import random
import time
import os
from funcionesNoRelacionadas import *

def AsignarNombresComunidades(num):
  '''
  E: Tiene como parámetro el número de comunidades extra que escogió el jugador, que servirá como index.
  S: Retorna una lista con los nombres de las nuevas comunidades.
  '''
  if num == 0:
    return []
  else:
    nombreComunidad = input(
        "\nQue nombre quiere asignarle a la siguiente comunidad\n")
    return [nombreComunidad] + AsignarNombresComunidades(num - 1)


def AsignarColoresBandera(comunidades):
  '''
  E: Tiene como parámetro la lista de comunidades, cuando se llama se quitan los 2 primeros elementos pues son Salitre y Cabagra, estos ya tienen bandera predeterminada. La lista le indicará al jugador la bandera de que comunidad está refiriendose.
  S: Retorna una lista con listas dentro de los colores para cada bandera, elegidos uno por uno por el jugador al llamar queColores()
  R: Cuando se llama hay que quitar a salitre y cabagra de la lista de comunidades en el parámetro
  '''
  if comunidades == []:
    return []
  print("Cuantos colores quiere que tenga la bandera de", comunidades[0],"[2-3]")
  numColores = input()
  if not esDigito(numColores):
    return print("Debe ser un número entero. Intente de nuevo.")
  elif int(numColores) != 2 and int(numColores) != 3:
    return print("El número de colores debe ser 2 o 3. Intente de nuevo.")

  numColores = int(numColores)
  return [queColores(numColores)] + AsignarColoresBandera(comunidades[1:])


def queColores(numColores):
  '''
  E: Tiene como parámetros el número de colores que el jugador quería que tuviera la bandera de x comunidad.
  S: Retorna una lista de colores que el jugador escogió.
  '''
  if numColores == 0:
    return []
  else:
    color = input(
        "\nQue color quiere que tenga la bandera [rojo, blanco, verde, amarillo, azul, morado]\n"
    )
    if color != "rojo" and color != "blanco" and color != "verde" and color != "amarillo" and color != "azul" and color != "morado":
      print("Color no válido")
    else:
      return [color] + queColores(numColores - 1)


def AsignarValorCultura(num):
  '''
  E: Tiene como parámetro el número de comunidades extra que escogió el jugador.
  S: Retorna una lista con los valores de cultura de las nuevas comunidades como un valor aleatorio entre 40,60.
  '''
  if num == 0:
    return []
  else:
    return [random.randint(40, 60)] + AsignarValorCultura(num - 1)


def AsignarValorAutonomia(num):
  '''
  E: Tiene como parámetro el número de comunidades extra que escogió el jugador.
  S: Retorna una lista con los valores de autonomia de las nuevas comunidades como un valor aleatorio entre 40,60.
  '''
  if num == 0:
    return []
  else:
    return [random.randint(40, 60)] + AsignarValorAutonomia(num - 1)


def AsignarNiveles(num):
  '''
  E: Tiene como parámetro el número de comunidades extra que escogió el jugador.
  S: Retorna una lista asignando a las nuevas comunidades el nivel 1. Esto para que hayan tantos elementos en la lista de niveles como comunidades.
  R: Puede que sus valores sean suficiente para ser uno diferente, por eso hay que llamar después de esta la función que actualiza su nivel.
  '''
  if num == 0:
    return []
  else:
    return [1] + AsignarNiveles(num - 1)


def RevisarValoresNivel(cultura, autonomia):
  '''
  E: Las listas de cultura y autonomia
  S: Una lista de los niveles de cada comunidad, este reemplazará la lista anterior cuando se llama la función
  '''
  if cultura == [] and autonomia == []: #caso de parada.
    return []
  elif cultura[0] == 0 or autonomia[0] == 0:
    return [0] + RevisarValoresNivel(cultura[1:], autonomia[1:])  #Si se pierde, la comunidad es nvl 0
  elif (cultura[0] > 0 and cultura[0] <= 25) or (autonomia[0] > 0 and autonomia[0] <= 25): #1-25 = nivel 1
    return [1] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  elif (cultura[0] > 25 and cultura[0] <= 50) or (autonomia[0] > 25 and autonomia[0] <= 50): #26-50 = nivel 2
    return [2] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  elif (cultura[0] > 50 and cultura[0] <= 75) or (autonomia[0] > 50 and autonomia[0] <= 75): #51-75 = nivel 3
    return [3] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  elif (cultura[0] > 75 and cultura[0] <= 100) or (autonomia[0] > 75 and autonomia[0] <= 100): #76-100 = nivel 4
    return [4] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  elif (cultura[0] > 100 and cultura[0] <= 125) or (autonomia[0] > 100 and autonomia[0] <= 125): #101-125 = nivel 5
    return [5] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  elif (cultura[0] > 125 and cultura[0] <= 150) or (autonomia[0] > 125 and autonomia[0] <= 150): #126-150 = nivel 6
    return [6] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  elif (cultura[0] > 150 and cultura[0] <= 175) or (autonomia[0] > 150 and autonomia[0] <= 175): #151-175 = nivel 7
    return [7] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  elif (cultura[0] > 175 and cultura[0] <= 200) or (autonomia[0] > 175 and autonomia[0] <= 200): #176-200 = nivel 8
    return [8] + RevisarValoresNivel(cultura[1:], autonomia[1:])
  else:  #200+ = nivel 9
    return [9] + RevisarValoresNivel(cultura[1:], autonomia[1:])


def Menu(comunidades, cultura, autonomia, niveles, colores, nivelMejoras):
  '''
  E: Sus parametros son las listas de comunidades, cultura, autonomía, de niveles, colores de banderas y el nivel de Mejoras
  S: Hace print de una forma fácil de entender al jugador sobre los valores que tiene para sus comunidades.
  '''
  os.system('clear')  #limpia la terminal ## PD: Para linux y mac es 'clear', para windows es 'cls'
  print("------------------------------------------------------------------------------------------")
  print("Información de tus comunidades:")
  print("Tienes un nivel de Mejora de", nivelMejoras, "\n")
  Valores(comunidades, cultura, autonomia, colores, niveles,len(comunidades) - 1)

  print(r"""
     ~         ~~          __
           _T      .,,.    ~--~ ^^
     ^^   // \                    ~
          ][O]    ^^      ,-~ ~
       /''-I_I         _II____
    __/_  /   \ ______/ ''   /'\\_,__
      | II--'''' \\,--:--..,_/,.-{ },
    ; '/__\\,.--';|   |[] .-.| O{ _ }
    :' |  | []  -|   ''--:.;[,.'\\,/
    '  |[]|,.--'' '',   ''-,.    |
      ..    ..-''    ;       ''. ' 
  """)

  print("------------------------------------------------------------------------------------------")
  

def Valores(comunidades, cultura, autonomia, colores, niveles, index):
  '''
  E: Tiene como parámetos la lista de comunidades, la lista de cultura, la lista de autonomia, la lista de colores de banderas, la lista de niveles y el número de comunidades-1 que servirá como index.
  S: Imprime los valores de cada comunidad junto a su bandera
  '''
  # caso base
  if index == -1:
    return print()  #-1 porque el 0 nos sirve para print el primero de la lista
  else:
    print("\nLa comunidad de", comunidades[index], end=" ")
    dibujarBandera(index, colores)
    print("tiene un valor de cultura de", cultura[index],"y un valor de autonomía de", autonomia[index], "\n",comunidades[index], "está a nivel", niveles[index], "\n")
    return Valores(comunidades, cultura, autonomia, colores, niveles, index - 1)


def dibujarBandera(num, colores, i=0):  #i=0 significa que si no se le pone ningún valor a i cuando se llama a la función, se le asigna el valor 0, esto pasa la primera vez que se llama a la función.
  '''
  E: Tiene como parámetros el número que representa a la comunidad dentro de cada lista, la lista colores y la i, que se usará como index dentro de la lista de colores. 
  S: Imprime la bandera de la comunidad.
  '''
  #Se usan codigos de escape ANSI
  #\033 es lo que se usa para "decirle a la terminal" que lo que sigue no es texto normal.
  #[ es para indicar el inicio de la secuencia
  #el número que sigue es el color.
  # la m es para indicar el fin de la secuencia.
  rojo = '\033[31m'
  blanco = '\033[97m'
  verde = '\033[92m'
  amarillo = '\033[93m'
  azul = '\033[94m'
  morado = '\033[95m'
  reset = '\033[0m'
  #[["rojo", "azul"]["rojo", "azul"]]
  if len(colores[num]) == i:
    return print(reset, end=" ")  
  #^^^^^Esto significa que cuando i sea igual a la longitud de la lista de los colores de x bandera, lo cual pasará despues de iterar e imprimir los colores, es decir, 
  #"despues de imprimir la bandera / caso base", el reset hace que el texto vuelva a ser el color normal y el end=" " hace que en vez que al final como siempre haga otra línea, solo ponga un espacio.
  if colores[num][i] == "rojo":
    print(rojo + "█", end="")
    return dibujarBandera(num, colores, i + 1)
  if colores[num][i] == "blanco":
    print(blanco + "█", end="")
    return dibujarBandera(num, colores, i + 1)
  if colores[num][i] == "verde":
    print(verde + "█", end="")
    return dibujarBandera(num, colores, i + 1)
  if colores[num][i] == "amarillo":
    print(amarillo + "█", end="")
    return dibujarBandera(num, colores, i + 1)
  if colores[num][i] == "azul":
    print(azul + "█", end="")
    return dibujarBandera(num, colores, i + 1)
  if colores[num][i] == "morado":
    print(morado + "█", end="")
    return dibujarBandera(num, colores, i + 1)


def Proyecto(comunidades, cultura, autonomia, niveles, comunidad, nivelMejoras, index=0):
  '''
  E: Los parámetros son la lista de comunidades, la lista de cultura, la lista de autonomia, la lista de niveles, la comunidad en la que se trabajará y un número que es 0 por default, será usado como index.
  S: Retorna la lista de cultura/autonomía con su valor actualizado después de realizar el proyecto.
  '''
  proyectosAutonomia = [
      "Tu comunidad ha creado una escuela.",
      "Tu comunidad logró construir un hospital.",
      "Tu comunidad ha creado un centro de investigación.",
      "Tu comunidad ha plantado cultivos.",
      "Tu comunidad ha construido una biblioteca.",
      "Tu comunidad ha creado una granja.",
      "Tu comunidad ha construido más viviendas."
  ]
  proyectosCultura = [
      "Tu comunidad ha creado un museo.",
      "Tu comunidad ha creado una iglesia para fomentar la religión.",
      "Tu comunidad le ha brindado gran apoyo a sus artesanos.",
      "En tu comunidad, han habido presentaciones culturales para pasarles la cultura a la nuevas generaciones.",
      "Tu comunidad ha celebrado una festividad con rituales."
  ]

  if len(comunidades) == index:  #Caso base. Si no encuentra ninguna comunidad que coincida con la variable comunidad
    print("No parece que tengas ninguna comunidad con ese nombre, pierdes el turno.")
    time.sleep(2)
    return None 
  
  if comunidad == comunidades[index]: #si encuentra alguna comunidad con el mismo nombre del input
    tipo = input("Quieres hacer un proyecto de cultura o de autonomía? [c,a]\n")
    if tipo == "c":
      print(proyectosCultura[random.randint(0, len(proyectosCultura) - 1)])
      cultura[index] += redondeoAbajo(random.randint(10, 15) *(nivelMejoras/ 10 + 1))
      print (r"""
                  .                  *                     *                   
                        *        .          *        .           *        .       .
                .         .            .          .     *            .         *
             *     ,_          *   .-.-------.               .           .          .
                 __(_\   .        //^\\       \  *      .         . *           . 
               ~( _ )    ___      \\_//_______/                    .--------.-.
            ^^^ // >>^^,/ _ )~ ^^/[_=/]______]^^^^^^^^^^^^^^^^^^^^/        //^\\^^^^^^^
                      /_/< \\   /_(=/ (o)  (o)                    \________\\=//
                                       ~    ~             ^^      [________[\__]\
                ^^^               ^^          .="=.               (o)    (o)`\=)_\
                                         /\_ /|6 6|\ _/\           ~      ~
                      )     ^^           \_//O\_+_/O\\_/
                    o ,( o                \\\/`ooo`\///                      ^^
                  o =(_,)= o               \   ($)   /     ^^^
                  o ="  "= o      ^^^     ./---/_\---\.
                    o oo o               /`"---------"`\          ^^  
        """)
      time.sleep(4)
      return cultura #retorna la lista de cultura con el valor de x comunidad cambiado
    
    elif tipo == "a":
      print(proyectosAutonomia[random.randint(0, len(proyectosAutonomia) - 1)])
      autonomia[index] += redondeoAbajo(random.randint(10, 15) *(nivelMejoras/ 10 + 1))
      print (r"""
            ~         ~~          __
                   _T      .,,.    ~--~ ^^
             ^^   // \                    ~
                  ][O]    ^^      ,-~ ~
               /''-I_I         _II____
            __/_  /   \ ______/ ''   /'\_,__
              | II--'''' \,--:--..,_/,.-{ },
            ; '/__\,.--';|   |[] .-.| O{ _ }
            :' |  | []  -|   ''--:.;[,.'\,/
            '  |[]|,.--'' '',   ''-,.    |
              ..    ..-''    ;       ''. '
      """)
      time.sleep(4)
      return autonomia #retorna la lista de autonomia con el valor de x comunidad cambiado
    
  else:
    return Proyecto(comunidades, cultura, autonomia, niveles, comunidad, nivelMejoras, index + 1)  #llamada recursiva


def Mejora(nivelMejoras, niveles, comunidades):
  '''
  E: Los parámetros son el nivel actual de las mejoras, la lista de niveles y la lista de comunidades.
  S: Si el nivel de mejora es igual a la comunidad de nivel más alto, el nivel de mejora queda igual. Si es menor, entonces sube 1 nivel de mejora.
  '''
  nivelMax = Maximo(niveles)  # ver cual es el índice del nivel más alto de las comunidades. Será el límite para la mejora.
  print(comunidades[nivelMax], "tiene el nivel más alto, con", niveles[nivelMax], "niveles, este es el máximo para tu mejora")
  time.sleep(4)
  if nivelMejoras == niveles[nivelMax]: #Si el nivel de mejora es igual a la comunidad de nivel más alto, no puede cambiarlo
    print("Ya estás en la mejora más alta, sube de nivel para mejorar más.")
    time.sleep(3)
    return nivelMejoras
  else:
    nivelMejoras += 1
    print("Los trabajadores de tu consejo consiguieron mejores herramientas, tu nivel de mejora ha subido a", nivelMejoras, "y el máximo es", niveles[nivelMax], "\n")
    time.sleep(5)
    return nivelMejoras
  

def Ataque(comunidades, cultura, autonomia, niveles):
  '''
  E: Los parámetros son la lista de comunidades, la lista de cultura, la lista de autonomia y la lista de niveles.
  S: Se imprime lo que sea que ocurrió dependiendo del rng, se retorna la lista de autonomía o cultura de la comunidad que fue atacada con su valor reducido.
  '''
  #Listas de lo que podría ocurrir en cada ataque.
  ataqueMisioneroCabagra = [
    "La familia Sandí Morales, recuperadora de tierras en Cabagra, ha recibido numerosas amenazas de muerte.",
    "Un misionero habitante de tierras no indígenas detonó un arma de fuego en contra de los habitantes de Cabagra."
  ]
  ataqueMineroCabagra = [
    "Se ha descubierto el plan de los mineros de venir a atacar Cabagra con armas de fuego.",
    "Se encontraron mineros no indígenas infiltrados dentro de las viviendas de Cabagra"
  ]
  ataqueMisioneroSalitre = [
    "Han asesinado al líder de la comunidad de Salitre, Sergio Rojas. Ahora tu comunidad está en peligro, ya que deben organizarse antes de que vuelvan a atacar a Salitre.", 
    "Se escucharon varios disparos durante la noche de ayer, hoy se encontarron a bastantes habitantes de tu comunidad muertos o heridos en las calles.", 
    "Muchos habitantes de tu comunidad han recibido amenazas de muerte por parte de los misioneros."
  ]
  ataqueMineroSalitre = [
    "Un grupo de mineros ha llegado a quemar ranchos de Salitre.",
    "La mafia de los mineros ha golpeado a los habitantes de tu comunidad para que salgan de sus tierras.",
    "Salitre ha sufrido de bloqueos del acceso al territorio con piedras y arena que llevaron en dos vagonetas mineras.",
    "Salitre ha sufrido de cortes en la electricidad gracias a ataques mineros."
   
  ]
  ataqueMisionero = [
    "Han llegado misioneros a tu comunidad para imponerle a tus habitantes una nueva religión.",
    "Un grupo de misioneros se ha metido a vivir en casas de tu comunidad.",
    "Un grupo de misioneros le está inculcando nuevas tradiciones a los habitantes de tu comunidad.",
    "Los misioneros han cerrado el museo de tu comunidad.",
    "Los misioneros han atentado en contra de los derechos humanos de tu comunidad."
  ]
  ataqueMinero = [
    " Un grupo de mineros ha llegado a tu comunidad a extraer minerales y gemas preciosas.",
    "Los habitantes de tu comunidad han decidido desalojar sus casa y mudarse a otras comunidades.",
    "Un grupo de mineros se ha metido a vivir en casas de tu comunidad.",
    "Los mineros han atentado en contra de los derechos humanos de tu comunidad."
  ]

  if random.randint(1, 10) == 1: #10% de probabilidad de no ser atacado
    print("Tuviste suerte, no fuiste atacado esta ronda.")  
    time.sleep(3)
    return None
  
  elif random.randint(1, 100) <= 5:  #5% de probabilidad, ataque grande, en el cual mineros y misioneros atacan a la vez.
    index = random.randint(0, len(comunidades) - 1)
    comunidadAtaque = comunidades[index]
    print("Has sufrido del ataque máximo del juego. Los misioneros y los mineros han armado fuerzas para derrotar a",comunidadAtaque,"\n Ellos lograron ejecutar su plan para robarle una parte de sus tierras a tu comunidad. Lo cual ha causado un gran daño en los niveles de autonomia y cultura.")
    print (r"""
     (')) ^v^  _           (`)_
    (__)_) ,--j j-------, (__)_)
          /_.-.___.-.__/ \
        ,8| [_],-.[_] | oOo
    ,,,oO8|_o8_|_|_8o_|&888o,,,
    """)
    cultura[index] -= redondeoAbajo(random.randint(10, 15) * niveles[index] / 10 + 1)
    if cultura[index] < 0: #si el valor llega a un valor negativo, cambiarlo a 0.
      cultura[index] = 0
    autonomia[index] -= redondeoAbajo(
        random.randint(10, 15) * niveles[index] / 10 + 1)
    if autonomia[index] < 0:
      autonomia[index] = 0
    time.sleep(5)
    return cultura, autonomia
  
  else:
    index = random.randint(0, len(comunidades) - 1) #se escoge al azar el índice de una comunidad
    comunidadAtaque = comunidades[index]

    if comunidadAtaque == "Cabagra": #Cabagra y Salitre están separados pues tienen mensajes de ataque diferentes a las comunidades extra.
      if random.randint(1, 10) >= 5:
        print("Los misioneros atacan a", comunidadAtaque)
        time.sleep(2)
        print(ataqueMisioneroCabagra[random.randint(0,len(ataqueMisioneroCabagra) - 1)])
        print (r"""
                   |
               \       /
                 .---. 
            '-.  |   |  .-'
              ___|   |___
         -=  [           ]  =-
             `---.   .---' 
          __||__ |   | __||__
          '-..-' |   | '-..-'
            ||   |   |   ||
            ||_.-|   |-,_||
          .-"`   `"`'`   `"-.
        .'                   '.
       /                       \
       """)
        cultura[index] -= redondeoAbajo(random.randint(10, 15) * niveles[index] / 10 + 1)
        if cultura[index] < 0:
          cultura[index] = 0
        time.sleep(4)
        return cultura
      else:
        print("Los mineros atacan a", comunidadAtaque)
        time.sleep(2)
        print(ataqueMineroCabagra[random.randint(0, len(ataqueMineroCabagra)-1)])
        print(r"""
        ⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⡆⠀⠀⠀⠀⠀⠠⠤⢤⣤⣀⡀⢀⡀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣻⣿⣏⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠘⠿⠿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠉⠻⡆⠀⠀⠀
        ⠀⠀⠀⠀⠀⣀⣴⣶⣶⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠁⠀⠀⠀⢹⠀⠀⠀
        ⠀⠀⠀⠀⣴⣿⣿⣿⣿⡿⠿⣿⣷⣦⣄⠀⠀⠀⣴⡿⠋⠀⠀⠀⢀⣀⣨⠀⠀⠀
        ⠀⠀⠀⢰⣿⣿⣿⣿⡟⠀⠀⠀⠙⠻⢿⣷⣦⡀⠉⠀⢀⣠⣴⣾⣿⣿⣿⡇⠀⠀
        ⠀⠀⠀⢸⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠉⠛⠁⠀⠀⠀⠀⣠⣾⡿⣿⢿⣿⠀⠀
        ⠀⠀⠀⢸⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠟⠉⢸⡿⠀⢻⡀⠀
        ⠀⠀⠀⠘⣿⣿⡟⠻⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⢸⠃⠀⠀⠇⠀
        ⠀⠀⠀⠀⢻⣿⣿⡄⠈⠻⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⢀⣿⣿⠇⠀⠀⣹⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⢠⣾⣿⠏⠀⠀⢀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠴⣿⡿⠁⠀⠀⢀⣾⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        """)
        autonomia[index] -= redondeoAbajo(random.randint(10, 15) * niveles[index] / 10 + 1)
        if autonomia[index] < 0:
          autonomia[index] = 0
        time.sleep(4)
        return autonomia
      
    elif comunidadAtaque == "Salitre":
      if random.randint(1, 10) >= 5:
        print("Los misioneros atacan a", comunidadAtaque)
        time.sleep(2)
        print(ataqueMisioneroSalitre[random.randint(0,len(ataqueMisioneroSalitre) - 1)])
        print (r"""
                   |
               \       /
                 .---. 
            '-.  |   |  .-'
              ___|   |___
         -=  [           ]  =-
             `---.   .---' 
          __||__ |   | __||__
          '-..-' |   | '-..-'
            ||   |   |   ||
            ||_.-|   |-,_||
          .-"`   `"`'`   `"-.
        .'                   '.
       /                       \
       """)
        cultura[index] -= redondeoAbajo(random.randint(10, 15) * niveles[index] / 10 + 1)
        if cultura[index] < 0:
          cultura[index] = 0
        time.sleep(4)
        return cultura
      else:
        print("Los mineros atacan a", comunidadAtaque)
        time.sleep(2)
        print(ataqueMineroSalitre[random.randint(0,len(ataqueMineroSalitre)-1)])
        print (r"""
⠀⠀⠀⠀⠀⠠⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣷⣦⡀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣿⣇⠘⠿⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠙⢿⣷⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠆⠀⠙⢿⣿⣿⡄⠀⠈⣿⡟⠀⠀⢸⣿⣿⣿⠀
⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⠟⠁⠀⠀⠀⠈⠻⣿⣷⠀⠀⣿⠁⠀⠀⠀⣿⣿⣿⠀
⠀⠀⠀⠀⠀⣠⣾⣿⠟⠁⠀⠀⢠⣦⣄⠀⠀⠘⢿⡇⠀⠁⠀⠀⠀⠀⢹⣿⣿⠀
⠀⠀⠀⢠⣾⣿⠟⠁⠀⠀⠀⠀⠉⠙⠛⠛⠒⠀⠈⠃⠀⠀⠀⣴⣶⣾⣿⣿⣿⠀
⠀⢀⣴⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⠀
⠀⠀⠙⠁⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⡇⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣃⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⠀
⠀⠀⠀⠀⣤⣤⣄⣀⡀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣶⣤⡄⠀⠀⠀⣠⣿⣿⣿⠀
⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢰⣿⣿⣿⣿⠀
⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣽⣿⣿⣿⠀
⠀⠀⠀⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠀
        """)
        autonomia[index] -= redondeoAbajo(random.randint(10, 15) * niveles[index] / 10 + 1)
        if autonomia[index] < 0:
          autonomia[index] = 0
        time.sleep(4)
        return autonomia

    #En caso de ser otra comunidad  
    if random.randint(1, 10) >= 5: 
      print("Los misioneros atacan a", comunidadAtaque)
      time.sleep(2)
      print(ataqueMisionero[random.randint(0, len(ataqueMisionero) - 1)])
      print (r"""
                   .
                  -|-
                   |
                  /A\
                 //^\\
               ,// _ \\,
               |/`/_\`\|
                |  ,  |
                | /^\ |
                |//'\\|
              ,//` _ `\\,
            ,//` .'|'. `\\,
          ,//`   |-|-|   `\\,
        ,//`     [_|_]     `\\,
        |/T                 T\|
          |  _   __ __   _  |
          | /_\ |  |  | /_\ |
          | |_| | .|. | |_| |
          |     |__|__|     |
          '----[_______]----'
                =======
               ======
      """)
      cultura[index] -= redondeoAbajo(random.randint(10, 15) * niveles[index] / 10 + 1)
      if cultura[index] < 0:
        cultura[index] = 0
      time.sleep(4)
      return cultura
    else: 
      print("Los mineros atacan a", comunidadAtaque)
      time.sleep(2)
      print(ataqueMinero[random.randint(0, len(ataqueMinero) - 1)])
      print (r"""
        ____||____
       ///////////\
      ///////////  \
      |    _    |  |
      |[] | | []|[]|
      |   | |   |  |
      
      .     '     ,
        _________
      _ /_|_____|_\ _
       '. \   / .'
         '.\ /.'
           '.'
      """)
      autonomia[index] -= redondeoAbajo(random.randint(10, 15) * niveles[index] / 10 + 1)
      if autonomia[index] < 0:
        autonomia[index] = 0
      time.sleep(4)
      return autonomia
    

def revisarSiPerdio(comunidades, niveles):
  '''
  E: lista de comunidades, lista de niveles.
  S: La lista de comunidades es usada para señalar al jugador cual de sus comunidades llegó a nivel 0. 
  '''
  if niveles == []:
    return False
  if niveles[0] == 0:
    print("El valor de autonomía o cultura de la comunidad de", comunidades[0], "ha llegado a 0, has perdido el juego.\n")
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
    return True
  else:
    return revisarSiPerdio(comunidades[1:], niveles[1:])


def revisarSiGano(niveles):
  if niveles == []:
    print("Ganaste el juego! Todas tus comunidades llegaron a nivel 9")
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
    return True
  if niveles[0] != 9:
    #Si encuentra alguno que no es 9 aún
    return False
  else:
    return revisarSiGano(niveles[1:])


def revisarNivelDeMejora(niveles, nivelMejoras):
  if nivelMejoras < Maximo(niveles):
    nivelMejoras = Maximo(niveles)
    print("Parece que bajaste a un nivel máximo más bajo que tu nivel de mejora tras ese ataque. Tu nivel de Mejora baja a", nivelMejoras)



